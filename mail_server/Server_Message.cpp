/*
 * Message.c
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */

#include <string>
#include "Server_Message.h"
#include "Server_General.h"

using std::string;

const string CMessage::DELIMITER = "\n";

CMessage::CMessage() {
	this->length = 0;
}

CMessage::~CMessage() {

}

void CMessage::pad_length(string& reply) {

	int total_len = reply.length() + SIZE_OF_MSG_PROTOCOL;

	string len_str = CGeneral::to_string(total_len);
	int pad_len = SIZE_OF_MSG_PROTOCOL - len_str.length();

	reply.insert(0, len_str);

	for (int i = 0; i < pad_len; i++)
		reply.insert(0, "0");
}
