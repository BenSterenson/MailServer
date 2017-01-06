/*
 * MSG_Get_Mail.h
 *
 *  Created on: Dec 2, 2016
 *      Author: bensterenson
 */

#ifndef MSG_GET_MAIL_H_
#define MSG_GET_MAIL_H_

#include "Server_Message.h"

class MSG_Get_Mail : public CMessage {

public:
	MSG_Get_Mail(CMessage* msg);
	virtual ~MSG_Get_Mail();

	int mail_id;
};

#endif /* MSG_GET_MAIL_H_ */
