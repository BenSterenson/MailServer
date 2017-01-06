/*
 * MSG_Login.h
 *
 *  Created on: Nov 22, 2016
 *      Author: bensterenson
 */

#ifndef MSG_LOGIN_H_
#define MSG_LOGIN_H_

#include <string>
#include "Message.h"
#include "General.h"
using std::string;


class REP_Login : public CReply {
public:

	string username;
	string password;
	EReply status;

	REP_Login();
	REP_Login(CReply* reply);
	virtual ~REP_Login();

	void ParseMsg();
};

class MSG_Login : public CMessage {

public:
	MSG_Login(string userName, string password);
	virtual ~MSG_Login();
	REP_Login reply;

protected:
	void BuildHeader();
	void BuildBody();

private:
	string userName;
	string password;
};

#endif /* MSG_LOGIN_H_ */
