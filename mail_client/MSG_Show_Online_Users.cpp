/*
 * MSG_Show_Inbox.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include "MSG_Show_Online_Users.h"
#include "General.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
using std::string;
using std::tr1::tuple;


REP_Show_Online_Users::~REP_Show_Online_Users() {

}

REP_Show_Online_Users::REP_Show_Online_Users(CReply* reply) {
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	//this->status = SERVER_FAILED;
	this->ParseMsg();
}

void REP_Show_Online_Users::ParseMsg(){
	char opcode = this->dataMsg.at(0);
	if (opcode == SHOW_ONLINE_USERS){

		// work on tmp msg remove first char AND STATUS.
		string tmpmsg = this->dataMsg.substr(2,this->dataMsg.length()-1);

		printf("Online users: %s\n", tmpmsg.c_str());

	}
	else {
		printf("Error parsing msg - show_Online_Users parser failed\n");
	}
}


MSG_Show_Online_Users::MSG_Show_Online_Users() {
	CMessage();
}

MSG_Show_Online_Users::~MSG_Show_Online_Users() {

}

void MSG_Show_Online_Users::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = SHOW_ONLINE_USERS;
}

void MSG_Show_Online_Users::BuildBody() {
	// (do nothing)
}
