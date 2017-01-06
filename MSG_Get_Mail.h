/*
 * MSG_Get_Mail.h
 *
 *  Created on: Dec 2, 2016
 *      Author: bensterenson
 */

#ifndef MSG_GET_MAIL_H_
#define MSG_GET_MAIL_H_

#include <string>
#include <list>
#include "Message.h"
#include "General.h"

using std::string;
using std::list;

class REP_Get_Mail : public CReply {

public:
	string from;
	string to;
	string subject;
	string text;


	EReply status;

	REP_Get_Mail();
	REP_Get_Mail(CReply* reply);
	virtual ~REP_Get_Mail();
	void PrintGetMail();
	void ParseMsg();
};

class MSG_Get_Mail : public CMessage {

public:
	MSG_Get_Mail(int mail_id);
	virtual ~MSG_Get_Mail();
	REP_Get_Mail reply;

protected:
	void BuildHeader();
	void BuildBody();

private:
	int mail_id;
};


#endif /* MSG_GET_MAIL_H_ */
