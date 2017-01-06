/*
 * MSG_Show_Inbox.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_SHOW_INBOX_H_
#define MSG_SHOW_INBOX_H_

#include "Server_Message.h"

class MSG_Show_Inbox: public CMessage {

public:
	MSG_Show_Inbox(CMessage* msg);
	virtual ~MSG_Show_Inbox();

};

#endif /* MSG_SHOW_INBOX_H_ */
