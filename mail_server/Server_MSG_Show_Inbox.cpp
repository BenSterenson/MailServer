/*
 * MSG_Show_Inbox.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include "Server_MSG_Show_Inbox.h"

MSG_Show_Inbox::MSG_Show_Inbox(CMessage* msg) {
	// data = [opcode]
	// do nothing (reading length and opcode were already read)
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;

}

MSG_Show_Inbox::~MSG_Show_Inbox() {

}
