/*
 * EYVA - login screen
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

#ifndef _GUI_LOGIN_H_
#define _GUI_LOGIN_H_

#include "gui_component.h" // defines following:
#include "button.h"
#include "textbox.h"

class
Login : public GUIComponent
{
	public:
		Login(SDL_Surface* root, int x, int y, int w, int h);
		~Login(void);
};

#endif

