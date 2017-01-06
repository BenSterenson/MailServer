/*
 * MSG_Quit.h
 *
 *  Created on: Nov 26, 2016
 *      Author: bensterenson
 */

#ifndef MSG_QUIT_H_
#define MSG_QUIT_H_

#include <string>
#include "Message.h"
#include "General.h"
using std::string;

class MSG_Quit : public CMessage {

public:
	MSG_Quit();
	virtual ~MSG_Quit();
	CReply reply;

protected:
	void BuildHeader();
	void BuildBody();

private:

};




#endif /* MSG_QUIT_H_ */
