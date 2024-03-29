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

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#define EXCEPTION_MSG_BUFFER_SIZE 80

#include <generic/variables.h>

#include <cstdio>   // (v)(s)(f)(n)printf
#include <cstdarg>  // va_list

class
Exception
{
	public:
		Exception(char const* format, ...);
		char const* str(void);
	
	private:
		char message[EXCEPTION_MSG_BUFFER_SIZE];
};

#endif

