/*
 * MSG_Compose.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_COMPOSE_H_
#define MSG_COMPOSE_H_

#include <string>
#include <list>
#include "Server_Message.h"

using std::string;
using std::list;

class MSG_Compose : public CMessage {

public:
	MSG_Compose(CMessage* msg);
	virtual ~MSG_Compose();

	string from;
	list<string> to;
	string subject;
	string text;
};

#endif /* MSG_COMPOSE_H_ */
