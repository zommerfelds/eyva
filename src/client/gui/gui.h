/*
 * EYVA - graphical user interface
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

#ifndef _GUI_H_
#define _GUI_H_

#include "login.h"
#include "gui_utils.h"
#include <client/network.h>
#include <generic/pipe.h>
#include <generic/utils/exception.h>
#include <generic/utils/ayelog.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include <utility>

class
GUI
{
	public:
		GUI(void);
		~GUI(void);
		void run(void);
	
	private:
		void handleEvents(void);

		SDL_Event* event;
		SDL_Surface* root;
		std::map<GUIComponentName, GUIComponent*> components;
		std::map<GUIComponentName, GUIComponent*>::iterator it;
		GUIComponentName active;
		Pipe* pipe;
		bool term_signal;
};

#endif

