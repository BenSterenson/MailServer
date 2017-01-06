/*
 * MSG_Get_Mail.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: bensterenson
 */




#include "MSG_Get_Mail.h"
#include "General.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

void split(const string &s, char delim, vector<string> &elems) {
	std::stringstream ss;
	ss.str(s);
	string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

REP_Get_Mail::REP_Get_Mail() {
	status = SERVER_FAILED;
}

REP_Get_Mail::~REP_Get_Mail() {

}

REP_Get_Mail::REP_Get_Mail(CReply* reply) {
	status = SERVER_FAILED;
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	this->ParseMsg();
}

void REP_Get_Mail::PrintGetMail() {
	printf("From: %s\n", this->from.c_str());
	printf("To: %s\n", this->to.c_str());
	printf("Subject: %s\n", this->subject.c_str());
	printf("Text: %s\n", this->text.c_str());
}

void REP_Get_Mail::ParseMsg(){
	// assuming msg protocol: len_opcode_status_from/to/subject/text
	char opcode = this->dataMsg.at(0);
	if (opcode != GET_MAIL) {
		printf("Error parsing msg - Get mail parser received '%c' as opcode. \n", opcode);
		return;
	}

	this->status = (EReply)this->dataMsg.at(1);
	if (this->status == SERVER_FAILED) {
		printf("Server failed: probably no such mail id. \n");
		return;
	}

	string s = this->dataMsg.substr(2);
	string delimiter = CMessage::DELIMITER;

	int pos = s.find(delimiter);
	this->from = s.substr(0, pos);
	s = s.erase(0, pos + delimiter.length());

	pos = s.find(delimiter);
	this->to = s.substr(0, pos);
	s = s.erase(0, pos + delimiter.length());

	pos = s.find(delimiter);
	this->subject = s.substr(0, pos);
	s = s.erase(0, pos + delimiter.length());

	pos = s.find(delimiter); // assuming that we have a delimiter in the end as well!!
	this->text = s.substr(0, pos);
	s = s.erase(0, pos + delimiter.length());

	//print
	this->PrintGetMail();
}

MSG_Get_Mail::MSG_Get_Mail(int mail_id) {
	CMessage();
	this->mail_id = mail_id;
}

MSG_Get_Mail::~MSG_Get_Mail() {

}

void MSG_Get_Mail::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = GET_MAIL;
}

void MSG_Get_Mail::BuildBody() {
	// (do nothing) insert parameters and length
	this->dataMsg.append(CGeneral::to_string(this->mail_id));
}

