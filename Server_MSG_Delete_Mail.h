/*
 * MSG_Delete_Mail.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_DELETE_MAIL_H_
#define MSG_DELETE_MAIL_H_

#include "Server_Message.h"

class MSG_Delete_Mail : public CMessage {

public:
	MSG_Delete_Mail(CMessage* msg);
	virtual ~MSG_Delete_Mail();

	int mail_id;
};

#endif /* MSG_DELETE_MAIL_H_ */
