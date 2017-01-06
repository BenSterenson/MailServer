/*
 * MSG_Compose.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_COMPOSE_H_
#define MSG_COMPOSE_H_



#include <string>
#include "Message.h"
#include "General.h"
using std::string;


class REP_Compose : public CReply {
public:

	EReply status;

	REP_Compose();
	REP_Compose(CReply* reply);
	virtual ~REP_Compose();

	void ParseMsg();
};



class MSG_Compose : public CMessage {

public:
	MSG_Compose(string str_to, string str_subject, string str_text);
	virtual ~MSG_Compose();
	CReply reply;

protected:
	void BuildHeader();
	void BuildBody();

private:
	string str_to;
	string str_subject;
	string str_text;
};




#endif /* MSG_COMPOSE_H_ */
