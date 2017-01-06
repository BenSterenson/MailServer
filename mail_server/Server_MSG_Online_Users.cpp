/*
 * MSG_Online_Users.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include "Server_MSG_Online_Users.h"

MSG_Online_Users::MSG_Online_Users(CMessage* msg) {
	// data = [opcode]
	// do nothing (reading length and opcode were already read)
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;

}

MSG_Online_Users::~MSG_Online_Users() {

}
