/*
 * MSG_Get_Mail.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: bensterenson
 */

#include <stdlib.h>
#include "Server_MSG_Get_Mail.h"

MSG_Get_Mail::MSG_Get_Mail(CMessage* msg) {
	// data = [opcode][mail_id]
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;

	char* tmp = &msg->dataMsg.substr(1)[0];
	mail_id = atoi(tmp);
}

MSG_Get_Mail::~MSG_Get_Mail() {

}
