/*
 * EYVA - server side network handler
 * Copyright (C) 2011 ayekat (martin.weber@epfl.ch)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _NETWORK_H_
#define _NETWORK_H_

#include "session.h"
#include <generic/pipe.h>
#include <generic/savefile.h>
#include <generic/variables.h> 
#include <generic/utils/ayelog.h>
#include <generic/utils/exception.h>
#include <generic/utils/ayestring.h>

#include <cstring>
#include <vector>
#include <map>
#include <utility>

// network headers:
#include <sys/types.h>  // socket types
#include <sys/socket.h> // sockets
#include <arpa/inet.h>  // inet (3) functions
#include <unistd.h>     // for write, read
#include <cerrno>       // for the "errno" macro

/* Mac OS X does not know the MSG_NOSIGNAL flag; therefore we "link"
 * MSG_NOSIGNAL to SO_NOSIGPIPE.
 * (If there's an error with sending data, the application crashes at send(),
 * rather than returning -1. That's the default behaviour (FSM knows why), so to
 * avoid that, the flag is required.)
 *
 * TODO see if Linux would also get along with SO_NOSIGPIPE
 */
#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL SO_NOSIGPIPE
#endif

#define SESSIONS_MAX 255
#define QUEUE_SIZE 10  // maximum connection requests to handle

class
Network
{
	public:
		Network(Pipe* pipe_game, int port);
		~Network(void);
		void poll(void);
		void send(char const* msg);

	private:
		void handleConnection(void);
		void handleData(char socket);

		Pipe* pipe_game;
		Pipe* pipe_network;
		Savefile* savefile_users;
		std::map<int, Session*> sessions;
		std::map<int, Session*>::iterator it; // iterator for the sessions map
		int sockc;                            // connection socket
		char buffer[NETWORK_BUFFER_SIZE];
};

#endif

