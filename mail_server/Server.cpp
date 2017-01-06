/*
 * Server.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: bensterenson
 */

#include "Server.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Server_General.h"

using std::string;
using namespace std;

enum extract_type {
	user = 0, password = 1
};

CServer* CServer::_instance = NULL;
pthread_mutex_t CServer::lock;

CServer& CServer::getInstance() {
	if (CServer::_instance == NULL) {
		pthread_mutex_lock(&CServer::lock);
		if (!CServer::_instance) {
			CServer* temp = new CServer();
			CServer::_instance = temp;
		}
		pthread_mutex_unlock(&CServer::lock);

	}

	return *CServer::_instance;
}

CServer::CServer() {
	CServer::_instance = NULL;
	this->port = 6423;
}

void CServer::init(string usersFile, int port) {
	this->port = port;
	this->usersFile = usersFile;
}

CServer::~CServer() {

}

CMessage* CServer::ReceiveMsg(int sock) {
	int received;
	CMessage* recv_msg = new CMessage();

	char client_msg[MSG_LEN];
	memset(client_msg, '\0', sizeof(char) * MSG_LEN);

	received = recv(sock, client_msg, SIZE_OF_MSG_PROTOCOL, 0);
	if (received == 0) {
		recv_msg->length = 0; // client disconnected
		return recv_msg;
	}
	if (received < 0 || received != SIZE_OF_MSG_PROTOCOL) {
		printf("Error: %s\n", strerror(errno));
		recv_msg->length = -1; // error
		return recv_msg;
	}
	int len_to_read = atoi(client_msg) - SIZE_OF_MSG_PROTOCOL;
	recv_msg->length = len_to_read;

	memset(client_msg, '\0', sizeof(char) * MSG_LEN);

	received = recv(sock, client_msg, len_to_read, 0);
	if (received == 0) {
		recv_msg->length = 0; // client disconnected
		return recv_msg;
	}
	if (received < 0 || received != len_to_read) {
		recv_msg->length = -1; // error
		printf("Error: %s\n", strerror(errno));
		return recv_msg;
	}

	recv_msg->dataMsg = string(client_msg);
	return recv_msg;
}

int checkLength(char* array) {
	for (int len = 0; len < MSG_LEN; len++) {
		if (array[len] == '\0')
			return len;
	}
	return MSG_LEN;
}

bool extract_login(string extracted_str, char* buf_input, int len,
		extract_type extraction_type) {
	char extracted_arr[len];
	memset(extracted_arr, '\0', sizeof(char) * len);
	char prefix_user[] = "User: ";
	char prefix_pass[] = "Password: ";
	char *prefix_check;

	if (extraction_type == user)
		prefix_check = prefix_user;
	else
		prefix_check = prefix_pass;

	int len_to_copy, pos, prefix_len = checkLength(prefix_check);

	//printf("input: %s\n", buf_input);
	//printf("prefix : %s\n", prefix_check);
	//printf("prefix len : %d\n", prefix_len);

	for (int i = 0; i < len && i < prefix_len; i++) {
		// check if prefix is equal to buf_input
		//printf("%c\n", buf_input[i]);
		//printf("%c\n", prefix_check[i]);
		if (buf_input[i] != prefix_check[i]) {
			printf("Failed user login\n");
			return false;
		}
	}

	// copy login info:
	string login_str = string(buf_input);
	len_to_copy = len - prefix_len;
	pos = prefix_len;
	login_str.copy(extracted_arr, len_to_copy, pos);
	extracted_str = string(extracted_arr);

	//printf("login_str: %s\n", login_str.c_str());
	//printf("len_to_copy : %d\n", len_to_copy);
	//printf("pos : %d\n", pos);
	//printf("extracted_arr: %s\n", extracted_arr);
	//printf("extracted_str: %s\n", extracted_str.c_str());

	return true;
}

void ParseLogin(string msg, string& username, string& password) {

	size_t pos = msg.find(CMessage::DELIMITER);
	if (string::npos == pos) {
		printf("Failed parsing\n");
		return;
	}

	// split up the line
	// skip opcode
	username = msg.substr(1, pos - 1);
	password = msg.substr(pos + 1, msg.length() - pos);
}

bool CServer::login(CMessage* msg, string& username_output) {
	string password;

	char opcode = msg->dataMsg.at(0);
	if (opcode != LOGIN)
		return false;

	// parse/extract user and pass
	ParseLogin(msg->dataMsg, username_output, password);

	// check if username in map
	std::map<string, string>::iterator it = CServer::username_password.find(
			username_output);

	// username not found
	if (it == CServer::username_password.end())
		return false;

	// found username - check password
	if (it->second.compare(password) != 0)
		return false;

	return true;
}

void CServer::execute(MSG_Login* msg, string username, int sock) {
	// TODO
}

void CServer::execute(MSG_Compose* msg, string username, int sock) {
	// send mail if users[to:..] exist

	string reply = "";
	reply += COMPOSE;

	bool valid = true;

	// first check that all users exists:
	for (list<string>::iterator it = msg->to.begin(); it != msg->to.end();
			it++) {
		if (this->username_password.find(*it)
				== this->username_password.end()) {
			valid = false;
			break;
		}
	}

	if (valid) {
		// for each user in 'to':
		for (list<string>::iterator it = msg->to.begin(); it != msg->to.end();
				it++) {
			map<int, SMail*> usermails = this->mails[*it];

			int min_i = 1;
			// find the minimum mail_id to insert the new msg
			for (map<int, SMail*>::iterator it2 = usermails.begin();
					it2 != usermails.end(); it2++) {
				if (it2->first == min_i) {
					min_i++;
				} else {
					break;
				}
			}

			// insert new mail
			SMail* mail = new SMail();
			mail->from = username;
			mail->to = msg->to;
			mail->subject = msg->subject;
			mail->text = msg->text;
			this->mails[*it][min_i] = mail;
		}

		reply += SERVER_SUCCESS;
	}

	else {
		reply += SERVER_FAILED;
	}

	CMessage::pad_length(reply);
	CGeneral::sendall(sock, &reply[0], (int) reply.length());
}

void CServer::execute(MSG_Delete_Mail* msg, string username, int sock) {
	// delete if exists
	string reply = "";
	reply += DELETE_MAIL;

	map<int, SMail*>::iterator it = this->mails[username].find(msg->mail_id);

	if (it != this->mails[username].end()) {
		this->mails[username].erase(it);
		reply += SERVER_SUCCESS;
	}

	else {
		reply += SERVER_FAILED;
	}

	CMessage::pad_length(reply);
	CGeneral::sendall(sock, &reply[0], (int) reply.length());
}

void CServer::execute(MSG_Get_Mail* msg, string username, int sock) {
	// get mail if exists

	string reply = "";
	reply += GET_MAIL;

	map<int, SMail*>::iterator it = this->mails[username].find(msg->mail_id);

	if (it != this->mails[username].end()) {
		reply += SERVER_SUCCESS;

		reply += it->second->from;
		reply += CMessage::DELIMITER;

		// list<string> -> str1,str2,..,strN
		string to = "";
		list<string> lst = it->second->to;
		for (list<string>::iterator it2 = lst.begin(); it2 != lst.end();
				it2++) {
			to += *it2;
			to += ',';
		}
		reply += to.substr(0, to.length() - 1);
		reply += CMessage::DELIMITER;

		reply += it->second->subject;
		reply += CMessage::DELIMITER;

		reply += it->second->text;
		reply += CMessage::DELIMITER;
	}

	else {
		reply += SERVER_FAILED;
	}

	CMessage::pad_length(reply);
	CGeneral::sendall(sock, &reply[0], (int) reply.length());
}

void CServer::execute(MSG_Quit* msg, string username, int sock) {
	// send 'ok' for quit command
	string reply = "";
	reply += QUIT;
	reply += SERVER_SUCCESS;

	CMessage::pad_length(reply);
	CGeneral::sendall(sock, &reply[0], (int) reply.length());
}

void CServer::execute(MSG_Show_Inbox* msg, string username, int sock) {
	// sends [len][opcode][msg1][msg2]...[msgN]
	// where [msgI] = [id][sender][subject]

	string reply = "";
	reply += SHOW_INBOX;
	reply += SERVER_SUCCESS;

	map<int, SMail*> mails = this->mails[username];

	for (map<int, SMail*>::iterator it = mails.begin(); it != mails.end();
			it++) {

		reply += CGeneral::to_string(it->first); // mail_id
		reply += CMessage::DELIMITER;

		reply += it->second->from;
		reply += CMessage::DELIMITER;

		reply += it->second->subject;
		reply += CMessage::DELIMITER;
	}

	CMessage::pad_length(reply);
	CGeneral::sendall(sock, &reply[0], (int) reply.length());
}

void* connection_handler(void* socket_desc) {
	int sock = *(int*) socket_desc;
	CServer& server = CServer::getInstance();

	CMessage *msg = NULL;
	bool logged_in = false;
	bool quit = false;
	string username = "";

	while (!logged_in) {

		msg = server.ReceiveMsg(sock);
		if (msg->length < 0) {
			printf(">>> Error: Recieved BAD msg, ignoring.\n");

			// free memory
			delete msg;
			msg = NULL;
			continue;
		}
		else if (msg->length == 0) {
			fflush(stdout);
			// memory is free'd after these:
			quit = true;
			break;
		}

		// TODO: make it like the switch case with server.execute(Login_command...)
		logged_in = server.login(msg, username);

		// TODO: think how to make it generic
		// send appropriate reply
		if (logged_in) {
			string message = "ls";
			CMessage::pad_length(message);
			CGeneral::sendall(sock, &message[0], (int) message.length());
		} else {
			string message = "lf";
			CMessage::pad_length(message);
			CGeneral::sendall(sock, &message[0], (int) message.length());
		}

		// free memory
		delete msg;
		msg = NULL;
	}

	while (!quit) {

		msg = server.ReceiveMsg(sock);
		if (msg->length < 0) {
			printf(">>> Error: Recieved BAD msg, ignoring.\n");

			// free memory
			delete msg;
			msg = NULL;
			continue;
		}
		else if (msg->length == 0) {
			fflush(stdout);
			// memory is free'd after these:
			quit = true;
			break;
		}

		char msg_type = msg->dataMsg.at(0);
		switch (msg_type) {
		case SHOW_INBOX: {
			MSG_Show_Inbox* command = new MSG_Show_Inbox(msg);
			server.execute(command, username, sock);
			delete command;
		}
			break;
		case GET_MAIL: {
			MSG_Get_Mail* command = new MSG_Get_Mail(msg);
			server.execute(command, username, sock);
			delete command;
		}
			break;
		case DELETE_MAIL: {
			MSG_Delete_Mail* command = new MSG_Delete_Mail(msg);
			server.execute(command, username, sock);
			delete command;
		}
			break;
		case QUIT: {
			MSG_Quit* command = new MSG_Quit(msg);
			server.execute(command, username, sock);
			delete command;
		}
			printf(">>> Quit: Quitting!.\n");
			quit = true;
			break;
		case COMPOSE: {
			MSG_Compose* command = new MSG_Compose(msg);
			server.execute(command, username, sock);
			delete command;
		}
			break;
		case LOGIN:
			printf(">>> Login: Already logged in, ignoring.\n");
			break;
		default:
			printf(">>> Error: Illegal msg, ignoring.\n");
			break;
		}
	}

	// free memory and exit
	delete msg;
	msg = NULL;
	free(socket_desc); // close/free file descriptor
	pthread_exit(NULL);
}

bool CServer::extract_users() {
	string sLine;
	ifstream db_file(this->usersFile.c_str());
	while (getline(db_file, sLine)) {
		// locate delimiter
		size_t pos = sLine.find('\t');
		if (string::npos == pos) {
			printf("Corrupted file\n");
			return false;
		}

		string userName_db, pass_db;

		// split up the line
		userName_db = sLine.substr(0, pos);
		pass_db = sLine.substr(pos + 1, sLine.length() - pos);
		// store the results
		this->username_password.insert(
				std::pair<string, string>(userName_db, pass_db));
	}
	return true;
}

bool CServer::Start() {
	struct sockaddr_in my_addr, client_adrr;
	size_t sin_size = sizeof(struct sockaddr_in);
	int client_sock, retval;

	//parse given file
	if (!this->extract_users()) {
		printf("Error parsing users file\n");
		return false;
	}

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Error: %s\n", strerror(errno));
		return false;
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(this->port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	retval = bind(sockfd, (struct sockaddr*) &my_addr, sizeof(my_addr));
	if (retval == -1) {
		printf("Error: %s\n", strerror(errno));
		return false;
	}

	retval = listen(sockfd, 5);
	if (retval == -1) {
		printf("Error: %s\n", strerror(errno));
		return false;
	}

	while ((client_sock = accept(sockfd, (struct sockaddr*) &client_adrr,
			(socklen_t*) &sin_size))) {

		pthread_t sniffer_thread;

		int* new_sock = (int*) malloc(1);
		*new_sock = client_sock;

		if (pthread_create(&sniffer_thread, NULL, connection_handler,
				(void*) new_sock) < 0) {
			printf("could not create thread\n");
			return false;
		}

		//Now join the thread , so that we dont terminate before the thread
		//pthread_join( sniffer_thread , NULL);
	}
	pthread_exit(NULL);

	if (client_sock < 0) {
		printf("Error: Connection refused\n");
		return false;
	}
	return true;
}

