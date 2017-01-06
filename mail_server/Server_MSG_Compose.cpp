/*
 * MSG_Compose.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include "Server_MSG_Compose.h"

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

MSG_Compose::MSG_Compose(CMessage* msg) {
	// data = [opcode][to][subject][text]
	// [to] = [user1, user2, ..]
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;

	size_t pos1, pos2;
	string tmp_msg, tmp_to;

	tmp_msg = this->dataMsg;
	pos1 = 1; // skip opcode
	pos2 = tmp_msg.find(CMessage::DELIMITER);
	if (string::npos == pos2)
		printf(">>> Error: failed parsing Compose message.\n");

	tmp_to = tmp_msg.substr(pos1, pos2 - pos1);
	tmp_to.erase(std::remove_if(tmp_to.begin(), tmp_to.end(), isspace), tmp_to.end());

	// parse 'to' list
	vector<string> *tmpVec = new vector<string>();
	split(tmp_to, ',', *tmpVec);
	std::copy(tmpVec->begin(), tmpVec->end(), std::back_inserter(this->to));
	delete tmpVec;

	tmp_msg = tmp_msg.substr(pos2 + CMessage::DELIMITER.length());
	pos1 = 0; // after modifying the msg
	pos2 = tmp_msg.find(CMessage::DELIMITER);
	if (string::npos == pos2)
		printf(">>> Error: failed parsing Compose message.\n");

	this->subject = tmp_msg.substr(pos1, pos2 - pos1);
	this->text = tmp_msg.substr(pos2 + CMessage::DELIMITER.length());
}

MSG_Compose::~MSG_Compose() {

}
