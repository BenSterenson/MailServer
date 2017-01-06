/*
 * MSG_Quit.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_QUIT_H_
#define MSG_QUIT_H_

#include "Server_Message.h"

class MSG_Quit: public CMessage {

public:
	MSG_Quit(CMessage* msg);
	virtual ~MSG_Quit();

};

#endif /* MSG_QUIT_H_ */
