/*
 * MSG_Get_Mail.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include <stdlib.h>
#include "Server_MSG_Delete_Mail.h"

MSG_Delete_Mail::MSG_Delete_Mail(CMessage* msg) {
	// data = [opcode][mail_id]
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;

	char* tmp = &msg->dataMsg.substr(1)[0];
	mail_id = atoi(tmp);
}

MSG_Delete_Mail::~MSG_Delete_Mail() {

}
