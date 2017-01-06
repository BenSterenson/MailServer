/*
 * Reply.h
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */

#ifndef REPLY_H_
#define REPLY_H_

#include <string>

using std::string;
class CReply {

public:
	int length;
	string dataMsg;

	enum type {
		SHOW_INBOX = 'i',
		GET_MAIL = 'm',
		DELETE_MAIL = 'd',
		QUIT = 'q',
		COMPOSE = 'c',
		LOGIN = 'l',
	};

	CReply();

	virtual ~CReply();

	virtual void ParseMsg();

private:

};

#endif /* REPLY_H_ */
