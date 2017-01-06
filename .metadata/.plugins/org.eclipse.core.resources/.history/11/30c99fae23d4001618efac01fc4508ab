/*
 * General.h
 *
 *  Created on: Nov 19, 2016
 *      Author: bensterenson
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include <string>
#include <list>

using std::list;
using std::string;

#define MSG_LEN 5000000
#define SIZE_OF_MSG_PROTOCOL 10


enum EMessage {
	SERVER_SUCCESS='s',
	SERVER_FAILED='f',
};

enum ClientOpcode {
	SHOW_INBOX = 'i',
	GET_MAIL = 'm',
	DELETE_MAIL = 'd',
	QUIT = 'q',
	COMPOSE = 'c',
	LOGIN = 'l',
//..
};

class CGeneral {
public:

	static string buildMessage(EMessage type, list<string> parameters);
	static int checkLength(char* array);
	static int sendall(int s, char *buf, int len);

	//template<typename T>
	static std::string to_string(int value);

private:
};

#endif /* GENERAL_H_ */
