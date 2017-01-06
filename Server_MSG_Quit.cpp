/*
 * MSG_Quit.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#include "Server_MSG_Quit.h"

MSG_Quit::MSG_Quit(CMessage* msg) {
	// data = [opcode]
	// do nothing (reading length and opcode were already read)
	this->dataMsg = msg->dataMsg;
	this->length = msg->length;
}

MSG_Quit::~MSG_Quit() {

}
