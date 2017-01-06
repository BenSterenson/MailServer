/*
 * MSG_Get_Mail.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */



#include "MSG_Delete_Mail.h"
#include "General.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;


REP_Delete_Mail::~REP_Delete_Mail() {

}

REP_Delete_Mail::REP_Delete_Mail(CReply* reply) {
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	this->status = SERVER_FAILED;
	this->ParseMsg();
}

void REP_Delete_Mail::Print_Status(){
	if (this->status != SERVER_SUCCESS)
		printf("Failed deleting message\n");
	else
		printf("Success deleting message\n");
}

void REP_Delete_Mail::ParseMsg(){
	char opcode = this->dataMsg.at(0);
	if (opcode == DELETE_MAIL)
		this->status = (EReply)this->dataMsg.at(1);
	else
		printf("Error parsing msg - parser received %c as an opcode\n", opcode);

	//this->Print_Status();
}


MSG_Delete_Mail::MSG_Delete_Mail(int mail_id) {
	CMessage();
	this->mail_id = mail_id;
}

MSG_Delete_Mail::~MSG_Delete_Mail() {

}

void MSG_Delete_Mail::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = DELETE_MAIL;
}

void MSG_Delete_Mail::BuildBody() {
	// (do nothing) insert parameters and length
	this->dataMsg.append(CGeneral::to_string(this->mail_id));
}
