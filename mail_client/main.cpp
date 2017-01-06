/*
 * Client.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: bensterenson
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "General.h"
#include "Client.h"
#include <iostream>
#include <sstream>
#include <sys/select.h>

#include "MSG_Login.h"
#include "MSG_Show_Inbox.h"
#include "MSG_Get_Mail.h"
#include "MSG_Quit.h"
#include "MSG_Delete_Mail.h"
#include "MSG_Compose.h"
#include "MSG_Show_Online_Users.h"
using std::string;

#define USER_LEN 50
#define INPUT_MAX 3000

bool isValidPort(char port[]) {
	for (int i = 0; port[i] != 0; i++) {
		if (!isdigit(port[i]))
			return false;
	}
	return true;
}

int extract_Mail_id(string input) {
	size_t pos = 0;
	string str;
	pos = input.find(' ');

	// if command + mail id
	if (string::npos != pos)
		str = input.substr(pos, input.length());
	else
		return -1;

	int mail_id = atoi(str.c_str());

	if(mail_id == 0)
		return -1;
	return mail_id;
}
void handleInput(CClient* client, EMessage type, string input) {

	switch (type) {
	case LOGIN:
		break;

	case COMPOSE: {
		size_t pos = 0;
		string temp;

		// HANDLE TO::
		string const_prefix = "To: ";
		std::getline(std::cin, temp);
		// check if starts with TO::
		pos = temp.find(const_prefix);
		if (string::npos == pos) {
			printf("Should start with To: \n");
			return;
		}
		string str_to = temp.substr(pos + const_prefix.length(), temp.length());

		// HANDLE SUBJECT::
		const_prefix = "Subject: ";
		std::getline(std::cin,temp);
		// check if starts with Subject::
		pos = temp.find(const_prefix);
		if (string::npos == pos) {
			printf("Should start with Subject: \n");
			return;
		}
		string str_subject = temp.substr(pos + const_prefix.length(), temp.length());


		// HANDLE Text::
		const_prefix = "Text: ";
		std::getline(std::cin,temp);
		// check if starts with Text::
		pos = temp.find(const_prefix);
		if (string::npos == pos) {
			printf("Should start with Text: \n");
			return;
		}
		string str_text = temp.substr(pos + const_prefix.length(), temp.length());
		MSG_Compose mail = MSG_Compose(str_to, str_subject, str_text);
		client->SendMsg(mail);

		// Receive a reply from the server
		CReply *tmpReply = client->ReceiveMsg();
		mail.reply = REP_Compose(tmpReply);
		delete tmpReply;
	}
		break;


	case DELETE_MAIL: {
		int mail_id = extract_Mail_id(input);
		if (mail_id == -1)
			return;
		MSG_Delete_Mail mail = MSG_Delete_Mail(mail_id);
		client->SendMsg(mail);

		// Receive a reply from the server
		CReply *tmpReply = client->ReceiveMsg();
		mail.reply = REP_Delete_Mail(tmpReply);

		delete tmpReply;
	}
		break;

	case GET_MAIL: {
		int mail_id = extract_Mail_id(input);
		if (mail_id == -1)
			return;
		MSG_Get_Mail mail = MSG_Get_Mail(mail_id);
		client->SendMsg(mail);

		// Receive a reply from the server
		CReply *tmpReply = client->ReceiveMsg();
		mail.reply = REP_Get_Mail(tmpReply);

		delete tmpReply;
	}
		break;

	case QUIT: {
		MSG_Quit quit_msg = MSG_Quit();
		client->SendMsg(quit_msg);
		}
		break;

	case SHOW_INBOX: {
		MSG_Show_Inbox showInbox = MSG_Show_Inbox();
		client->SendMsg(showInbox);

		// Receive a reply from the server
		CReply *tmpReply = client->ReceiveMsg();
		showInbox.reply = REP_Show_Inbox(tmpReply);
		delete tmpReply;
	}
		break;

	case SHOW_ONLINE_USERS: {
		MSG_Show_Online_Users online_Users = MSG_Show_Online_Users();
		client->SendMsg(online_Users);

		// Receive a reply from the server
		CReply *tmpReply = client->ReceiveMsg();
		online_Users.reply = REP_Show_Online_Users(tmpReply);
		delete tmpReply;
	}
		break;
	case UNKOWN: {
		printf("Unkown command please try again\n");
	}
		break;
	}
	return;
}

void refresh_sets(fd_set *readfds, fd_set *errorfds, int isLoggedIn, int *maxFd, int socket){
	FD_ZERO(readfds);
	FD_ZERO(errorfds);
	FD_SET(STDIN_FILENO, readfds);
	FD_SET(STDIN_FILENO, errorfds);
	*maxFd = STDIN_FILENO + 1;
	if (isLoggedIn){
		FD_SET(socket, readfds);
		FD_SET(socket, errorfds);
		*maxFd = socket + 1;
	}
}


int main(int argc, char** argv) {
	int port = 6423, sock;
	struct sockaddr_in server;
	char user_buff[USER_LEN], password_buff[USER_LEN];
	string user_in = "", pass_in = "";
	string hostname = string("localhost");
	int user_flag;

	fd_set readfds, errorfds;
	int maxFd;


	if (argc > 1)
		hostname = hostname.assign(argv[1]);

	if (argc > 2) {
		if (!isValidPort(argv[2]))
			printf("Given port is not number. Default port selected: 6423 \n");

		else
			port = atoi(argv[2]);
	}

	//Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf("Could not create socket.\n");
	}

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	// Connect to remote server
	if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
		perror("connect failed. Error\n");
		return -1;
	}

	printf("Welcome! I am simple-mail-server.\n");

	//keep communicating with server
	CClient *client = new CClient(sock); //= new CClient::CClient();
	while (true) {
		//scanf("%s", message);

		fgets(user_buff, INPUT_MAX, stdin);
		user_flag = client->extract_login(&user_in, user_buff, INPUT_MAX, USER);
		if (user_flag == false) {
			continue;
		}

		fgets(password_buff, INPUT_MAX, stdin);
		user_flag = client->extract_login(&pass_in, password_buff, INPUT_MAX,
				PASSWORD);
		if (user_flag == false) {
			continue;
		} else {
			MSG_Login login_msg = MSG_Login(user_in, pass_in);
			client->SendMsg(login_msg);

			// Receive a reply from the server
			CReply *tmpReply = client->ReceiveMsg();
			login_msg.reply = REP_Login(tmpReply);
			delete tmpReply;

			if (login_msg.reply.status == SERVER_SUCCESS) {
				printf("Connected to server\n");
				break;
			}
		}
	}

	string input;
	int res;
	while (true) {

		refresh_sets(&readfds, &errorfds, isLoggedIn, &maxFd, chatSocket);

		res = select(maxFd, &readfds, NULL, &errorfds, NULL);
		res = handle_return_value(res);

		if (res == ERROR)
			break;



		fgets(user_buff, INPUT_MAX, stdin);
		string input = string(user_buff);

		EMessage MsgType = CGeneral::stringToMsgType(input);
		handleInput(client, MsgType, input);

		if (MsgType == QUIT)
			break;
	}
	close(sock);
	return 0;

}

