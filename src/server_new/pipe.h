/*
 * `eyva'
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

#ifndef _PIPE_H_
#define _PIPE_H_

// Utilities:
#include <utils/ayestring.h>

// Others:
#include <vector>

class
Pipe
{
	public:
		Pipe(void);
		~Pipe(void);
		size_t fetch(char* msg);
		void push(char const* msg);
		bool check(void);
	
	private:
		std::vector<char const*> box;
};

#endif
