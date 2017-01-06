/*
 * MSG_Compose.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */
#include "MSG_Compose.h"
#include "General.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

REP_Compose::REP_Compose() {
	this->status = SERVER_FAILED;
}

REP_Compose::~REP_Compose() {

}

REP_Compose::REP_Compose(CReply* reply) {
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	this->status = SERVER_FAILED;
	this->ParseMsg();
}


void REP_Compose::ParseMsg(){
	char opcode = this->dataMsg.at(0);
	if (opcode == COMPOSE) {
		this->status = (EReply)this->dataMsg.at(1);
		if(this->status == SERVER_SUCCESS)
			printf("Mail sent\n");
	}
	else {
		printf("Error parsing msg - COMPOSE parser received %c as an opcode\n", opcode);
	}
}


MSG_Compose::MSG_Compose(string str_to, string str_subject, string str_text) {
	CMessage();
	this->str_to = str_to;
	this->str_subject = str_subject;
	this->str_text = str_text;
}

MSG_Compose::~MSG_Compose() {

}

void MSG_Compose::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = COMPOSE;
}

void MSG_Compose::BuildBody() {
	this->dataMsg.append(this->str_to);
	this->dataMsg.append(this->DELIMITER);
	this->dataMsg.append(this->str_subject);
	this->dataMsg.append(this->DELIMITER);
	this->dataMsg.append(this->str_text);
}

