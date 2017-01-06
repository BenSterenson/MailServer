/*
 * General.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: bensterenson
 */

#include <list>
#include <string>
#include <sys/socket.h>
#include <sstream>
#include "General.h"
#include <stdio.h>

using std::list;
using std::string;

//template<typename T>
string CGeneral::to_string(int value) {
	//create an output string stream
	std::ostringstream os;

	//throw the value into the string stream
	os << value;

	//convert the string stream into a string and return
	return os.str();
}

EMessage CGeneral::stringToMsgType(string input) {
	size_t pos = 0;
	string str;
	pos = input.find(' ');

	// if command + mail id
	if (string::npos != pos)
		str = input.substr(0, pos);//idnore delimiter
	//command only
	else
		str = input.substr(0, input.length()-1);;

	if(str.compare("SHOW_INBOX") == 0)
		return SHOW_INBOX;

	if(str.compare("GET_MAIL") == 0)
		return GET_MAIL;

	if(str.compare("DELETE_MAIL") == 0)
		return DELETE_MAIL;

	if(str.compare("QUIT") == 0)
		return QUIT;

	if(str.compare("COMPOSE") == 0)
		return COMPOSE;

	return UNKOWN;
}

int CGeneral::checkLength(char* array) {
	for (int len = 0; len < MSG_LEN; len++) {
		if (array[len] == '\0' || array[len] == '\n')
			return len;
	}
	return MSG_LEN;
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


