/*
 * MSG_Show_Inbox.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include "MSG_Show_Inbox.h"
#include "General.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
using std::string;
using std::tr1::tuple;


REP_Show_Inbox::~REP_Show_Inbox() {

}

REP_Show_Inbox::REP_Show_Inbox(CReply* reply) {
	this->dataMsg = reply->dataMsg;
	this->length = reply->length;
	//this->status = SERVER_FAILED;
	this->ParseMsg();
}

void REP_Show_Inbox::PrintInbox(){
	typedef map<int, std::tr1::tuple<string,string> >::const_iterator MapIterator;
	for (MapIterator iter = this->mails.begin(); iter != this->mails.end(); iter++)
	{
		std::tr1::tuple<string,string> sender_subject = iter->second;
		cout << iter->first << " " << std::tr1::get<0>(sender_subject) << " \"" << std::tr1::get<1>(sender_subject) <<"\"" << endl;
	}
}


void REP_Show_Inbox::ParseMsg(){
	char opcode = this->dataMsg.at(0);
	if (opcode == SHOW_INBOX){

		// work on tmp msg remove first char AND STATUS.
		string tmpmsg = this->dataMsg.substr(2,this->dataMsg.length()-1);

		size_t pos = 0;
		int mail_id, field_count = 0;
		std::tr1::tuple<string,string> sender_subject = std::tr1::make_tuple("","");
		string token;

		while ((pos = tmpmsg.find(CMessage::DELIMITER)) != std::string::npos) {
		    token = tmpmsg.substr(0, pos);
		    tmpmsg.erase(0, pos + CMessage::DELIMITER.length());
		    // mail id
		    if(field_count % 3 == 0){
		    	mail_id = atoi(token.c_str());
		    	if (mail_id == 0){
		    		printf("Error parsing msg mail_id\n");
		    		break;
		    	}
		    	field_count++;
		    }
		    // sender
		    else if(field_count % 3 == 1){
		    	std::tr1::get<0>(sender_subject) = token;
		    	field_count++;
		    }
		    else { //(field_count % 3 == 2){
		    	std::tr1::get<1>(sender_subject) = token;
		    	field_count++;

		    	// insert to map and init all varibels.
		    	this->mails.insert(std::pair<int, std::tr1::tuple<string,string> >(mail_id, sender_subject));

		    	std::tr1::get<0>(sender_subject) = "";
		    	std::tr1::get<1>(sender_subject) = "";
		    }
		}
	}
	else {
		printf("Error parsing msg - show_Inbox parser failed\n");
	}
	this->PrintInbox();
}


MSG_Show_Inbox::MSG_Show_Inbox() {
	CMessage();
}

MSG_Show_Inbox::~MSG_Show_Inbox() {

}

void MSG_Show_Inbox::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = SHOW_INBOX;
}

void MSG_Show_Inbox::BuildBody() {
	// (do nothing)
}
