/*
 * MSG_Show_Inbox.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_SHOW_INBOX_H_
#define MSG_SHOW_INBOX_H_


#include <string>
#include <map>
#include "Message.h"
#include "General.h"
#include <tr1/tuple>
using std::string;
using std::map;
using std::tr1::tuple;



class REP_Show_Inbox : public CReply {
public:
	//EReply status;
	map<int, std::tr1::tuple<string, string> > mails;

	REP_Show_Inbox(CReply* reply);
	virtual ~REP_Show_Inbox();
	void PrintInbox();
	void ParseMsg();
};

class MSG_Show_Inbox : public CMessage {

public:
	MSG_Show_Inbox();
	virtual ~MSG_Show_Inbox();
	CReply reply;

protected:
	void BuildHeader();
	void BuildBody();

private:

};




#endif /* MSG_SHOW_INBOX_H_ */
