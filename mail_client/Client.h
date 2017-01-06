/*
 * Client.h
 *
 *  Created on: Nov 19, 2016
 *      Author: bensterenson
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "General.h"
#include "Message.h"

using std::string;

class CClient {
public:
	CClient(int socket);
	virtual ~CClient();
	bool extract_login(string *extracted_str, char* buf_input, int len,
			extract_type extraction_type);
	bool login(string user, string pass);
	bool SendMsg(CMessage &msg);
	CReply* ReceiveMsg();

private:
	static const char* DELIMITERS;
    static const char* USER_PREFIX;
    static const char* PASS_PREFIX;

	int socket;
};

#endif /* CLIENT_H_ */
