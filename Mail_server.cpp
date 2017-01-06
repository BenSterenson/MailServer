//============================================================================
// Name        : Mail_server.cpp
// Author      : Ben Sterenson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "Server.h"

#define DEFAULT_PORT 6423

bool isValidPath(char path[]) {
	return (access(path, F_OK ) != -1 );
}

bool isValidPort(char port[]) {
    for (int i = 0; port[i] != 0; i++)
	    {
	        if (!isdigit(port[i]))
	            return false;
	    }
    return true;
}

int main(int argc, char** argv) {
	int port = DEFAULT_PORT;
	char* path;

	// check for path problem
	if (argc < 2 || !isValidPath(argv[1])) {
		printf("File Not Found\n");
		return -1;
	}
	path = argv[1];

	// check for port problem
	if (argc >= 3) {
		if (!isValidPort(argv[2]))
			printf("Given port is not number. Default port selected: 6423 \n");

		else
			port = atoi(argv[2]);
	}

	CServer& mailServer = CServer::getInstance();
	mailServer.init(path, port);

	// valid port, path and init
	mailServer.Start();
}

