/*
 * MSG_Online_Users.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_ONLINE_USERS_H_
#define MSG_ONLINE_USERS_H_

#include "Server_Message.h"

class MSG_Online_Users: public CMessage {

public:
	MSG_Online_Users(CMessage* msg);
	virtual ~MSG_Online_Users();

};

#endif /* MSG_ONLINE_USERS_H_ */
