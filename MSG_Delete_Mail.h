/*
 * MSG_Delete_Mail.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_DELETE_MAIL_H_
#define MSG_DELETE_MAIL_H_


#include <string>
#include "Message.h"
#include "General.h"
using std::string;


class REP_Delete_Mail : public CReply {

public:
	EReply status;

	REP_Delete_Mail(CReply* reply);
	virtual ~REP_Delete_Mail();

	void ParseMsg();
	void Print_Status();
};


class MSG_Delete_Mail : public CMessage {

public:
	MSG_Delete_Mail(int mail_id);
	virtual ~MSG_Delete_Mail();
	CReply reply;

protected:
	void BuildHeader();
	void BuildBody();

private:
	int mail_id;
};


#endif /* MSG_DELETE_MAIL_H_ */
