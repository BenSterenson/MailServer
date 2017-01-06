/*
 * MSG_Login.h
 *
 *  Created on: Nov 22, 2016
 *      Author: bensterenson
 */

#ifndef MSG_LOGIN_H_
#define MSG_LOGIN_H_

#include "Server_Message.h"

class MSG_Login : public CMessage {

public:
	MSG_Login(CMessage* msg);
	virtual ~MSG_Login();

	string username;
	string password;
};

#endif /* MSG_LOGIN_H_ */
