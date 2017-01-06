/*
 * MSG_Login.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */
#include "MSG_Login.h"
#include "General.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

REP_Login::REP_Login() {
	this->status = SERVER_FAILED;
}

REP_Login::~REP_Login() {

}

REP_Login::REP_Login(CReply* reply) {
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	this->status = SERVER_FAILED;
	this->ParseMsg();
}


void REP_Login::ParseMsg(){
	char opcode = this->dataMsg.at(0);
	if (opcode == LOGIN)
		this->status = (EReply)this->dataMsg.at(1);
	else {
		printf("Error parsing msg - login parser received %c as an opcode", opcode);
	}
}

MSG_Login::MSG_Login(string userName, string password) {
	CMessage();
	this->userName = userName;
	this->password = password;
}

MSG_Login::~MSG_Login() {

}

void MSG_Login::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = LOGIN;
}

void MSG_Login::BuildBody() {
	// (do nothing) insert parameters and length

	this->dataMsg.append(this->userName);
	//this->dataMsg.push_back('\0');
	this->dataMsg.append(this->DELIMITER);
	this->dataMsg.append(this->password);
}
