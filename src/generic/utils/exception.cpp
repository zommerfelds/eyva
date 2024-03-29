/*
 * `eyva' - Exception class of which instances are thrown.
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

#include "exception.h"

/**
 * Constructor.
 * @param format The format string. See docs for `printf()' and the like.
 * @param ...    The format string arguments.
 */
Exception::Exception(char const* format, ...)
{
	va_list args;           // access handler
	va_start(args, format); // prepare access
	vsnprintf(message, EXCEPTION_MSG_BUFFER_SIZE, format, args);
	va_end(args);           // end access
}


/* PUBLIC METHODS */


/**
 * @return The exception message.
 */
char const*
Exception::str(void)
{
	return message;
}

