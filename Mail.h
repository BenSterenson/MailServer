/*
 * Mail.h
 *
 *  Created on: Nov 14, 2016
 *      Author: bensterenson
 */

#ifndef MAIL_H_
#define MAIL_H_

#include <string>
#include <list>

struct SMail
{
	std::string from;
	std::list<std::string> to;
	std::string subject;
	std::string text;
};

#endif /* MAIL_H_ */
