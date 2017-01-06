/*
 * MSG_Quit.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */




#include "MSG_Quit.h"
#include "General.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;


MSG_Quit::MSG_Quit() {
	CMessage();
}

MSG_Quit::~MSG_Quit() {

}

void MSG_Quit::BuildHeader() {
	// (do nothing) insert opcode
	this->dataMsg = QUIT;
}

void MSG_Quit::BuildBody() {
	// (do nothing)
}
