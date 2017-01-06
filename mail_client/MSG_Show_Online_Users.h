/*
 * MSG_Show_Online_Users.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_SHOW_ONLINE_USERS_H_
#define MSG_SHOW_ONLINE_USERS_H_


#include <string>
#include <map>
#include "Message.h"
#include "General.h"
#include <tr1/tuple>
using std::string;
using std::map;
using std::tr1::tuple;



class REP_Show_Online_Users : public CReply {
public:
	REP_Show_Online_Users(CReply* reply);
	virtual ~REP_Show_Online_Users();
	void PrintInbox();
	void ParseMsg();
};

class MSG_Show_Online_Users : public CMessage {

public:
	MSG_Show_Online_Users();
	virtual ~MSG_Show_Online_Users();
	CReply reply;

protected:
	void BuildHeader();
	void BuildBody();

private:

};




#endif /* MSG_SHOW_ONLINE_USERS_H_ */
