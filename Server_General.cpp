/*
 * General.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: bensterenson
 */

#include <list>
#include <string>
#include <sys/socket.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Server_General.h"

using std::list;
using std::string;


int CGeneral::checkLength(char* array) {
	for (int len = 0; len < MSG_LEN; len++) {
		if (array[len] == '\0' || array[len] == '\n')
			return len;
	}
	return MSG_LEN;
}


//template<typename T>
string CGeneral::to_string(int value) {
	//create an output string stream
	std::ostringstream os;

	//throw the value into the string stream
	os << value;

	//convert the string stream into a string and return
	return os.str();
}

int CGeneral::sendall(int s, char *buf, int len) {
	int total = 0; /* how many bytes we've sent */
	int bytesleft = len; /* how many we have left to send */
	int n;

	while (total < len) {
		n = send(s, buf + total, bytesleft, 0);
		if (n == -1) {
			break;
		}
		total += n;
		bytesleft -= n;
	}

	return total;
}



