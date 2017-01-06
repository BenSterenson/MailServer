/*
 * Client.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: bensterenson
 */

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <cerrno>
#include <list>
#include <stdlib.h>
#include "Client.h"
#include "General.h"

using std::list;
using std::string;

const char* CClient::DELIMITERS = " ";
const char* CClient::USER_PREFIX = "User:";
const char* CClient::PASS_PREFIX = "Password:";

CClient::CClient(int socket) {
	// TODO
	this->socket = socket;
}

CClient::~CClient() {
	// TODO
}

bool CClient::SendMsg(CMessage &msg) {
	string built_msg = msg.buildMsg();
	char* buff = strdup(built_msg.c_str());

	int total_sent = CGeneral::sendall(this->socket, buff, msg.length);
	free(buff);
	if (total_sent == msg.length)
		return true;
	return false;
}

CReply* CClient::ReceiveMsg() {
	int received;
	CReply *reply = new CReply();
	char server_reply[MSG_LEN];
	memset(server_reply, '\0', sizeof(char) * MSG_LEN);


	received = recv(this->socket, &server_reply[0], SIZE_OF_MSG_PROTOCOL, 0);
	if (received <= 0 || received != SIZE_OF_MSG_PROTOCOL) {
		printf("Error: %s\n", strerror(errno));
		return reply;
	}
	int len_to_read = atoi(server_reply) - SIZE_OF_MSG_PROTOCOL ;
	reply->length = len_to_read;

	memset(server_reply, '\0', sizeof(char) * MSG_LEN);

	received = recv(this->socket, &server_reply[0], len_to_read, 0);
	if (received <= 0 || received != len_to_read){
		printf("Error: %s\n", strerror(errno));
		return reply;
	}

	reply->dataMsg = string(server_reply);
	return reply;
}

bool CClient::extract_login(string* extracted_str, char* buf_input, int len,
		extract_type extraction_type) {
	char extracted_arr[len];
	memset(extracted_arr, '\0', sizeof(char) * len);
	char prefix_user[] = "User: ";
	char prefix_pass[] = "Password: ";
	char *prefix_check;

	if (extraction_type == USER)
		prefix_check = prefix_user;
	else
		prefix_check = prefix_pass;

	int len_to_copy, pos, prefix_len = CGeneral::checkLength(prefix_check);

	for (int i = 0; i < len && i < prefix_len; i++) {
		// check if prefix is equal to buf_input
		if (buf_input[i] != prefix_check[i]) {
			if (extraction_type == USER)
				printf("# Login request format: \'%s username\' prefix expected \n", USER_PREFIX);
			else
				printf("# Login request format: \'%s password\' prefix expected \n", PASS_PREFIX);
			return false;
		}
	}

	// copy login info:
	string login_str = string(buf_input);
	len_to_copy = CGeneral::checkLength(buf_input) - prefix_len;
	pos = prefix_len;
	login_str.copy(extracted_arr, len_to_copy, pos);
	*extracted_str = string(extracted_arr);

	/*Debug
	printf("login_str: %s\n", login_str.c_str());
	printf("len_to_copy : %d\n", len_to_copy);
	printf("pos : %d\n", pos);
	printf("extracted_arr: %s\n", extracted_arr);
	printf("extracted_str: %s\n", (*extracted_str).c_str());
	*/
	return true;
}

