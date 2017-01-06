/*
 * Message.h
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>

using std::string;

class CMessage {

public:
	int length;
	string dataMsg;

	CMessage();
	virtual ~CMessage();

	static void pad_length(string& reply);

	enum type {
		SHOW_INBOX = 'i',
		GET_MAIL = 'm',
		DELETE_MAIL = 'd',
		QUIT = 'q',
		COMPOSE = 'c',
		LOGIN = 'l',
		SHOW_ONLINE_USERS = 's',
	};
	static const string DELIMITER;
};

#endif /* MESSAGE_H_ */
