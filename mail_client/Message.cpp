/*
 * Message.c
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */

#include <string>
#include "Message.h"
#include "General.h"

using std::string;

CMessage::CMessage() {
	this->length = 0;
}

CMessage::~CMessage() {

}

const string CMessage::DELIMITER = "\n";
const string CMessage::EOP = "\0";

//template<typename T>
//static string to_string(T value);

string CMessage::buildMsg() {
	// build:
	this->BuildHeader(); 	// opcode
	this->BuildBody();		// content
	this->BuildFooter();	// EOP

	// calculate and add length (padded) at the begining
	string len_str = CGeneral::to_string(this->dataMsg.length() + SIZE_OF_MSG_PROTOCOL);
	int pad_len = SIZE_OF_MSG_PROTOCOL - len_str.length();

	this->dataMsg.insert(0, len_str);

	for (int i = 0; i < pad_len; i++)
		this->dataMsg.insert(0, CGeneral::to_string(0));

	this->length = dataMsg.length();

	return this->dataMsg;
}

void CMessage::BuildHeader() {
	// (do nothing) insert opcode (by inheriting class) and length (by BuildMsg after building is done)
}

void CMessage::BuildBody() {
	// (do nothing) insert parameters
}

void CMessage::BuildFooter() {
	// insert EOP
	//this->dataMsg.append(this->EOP);
	this->length = dataMsg.length();
}
