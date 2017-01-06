/*
 * Message.h
 *
 *  Created on: Nov 21, 2016
 *      Author: bensterenson
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <string>
#include "Reply.h"

using std::string;

class CMessage {
public:
	int length;
	CReply reply;

	CMessage();
	virtual ~CMessage();

	virtual string buildMsg();

	enum type {
		SHOW_INBOX = 'i',
		GET_MAIL = 'm',
		DELETE_MAIL = 'd',
		QUIT = 'q',
		COMPOSE = 'c',
		LOGIN = 'l',
	};
	static const string DELIMITER;

protected:
	virtual void BuildHeader();
	virtual void BuildBody();
	virtual void BuildFooter();

	string dataMsg;
	static const string EOP;
private:

};

#endif /* MESSAGE_H_ */
