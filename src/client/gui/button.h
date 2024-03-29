/*
 * EYVA - clickable button
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

#ifndef _GUI_BUTTON_H_
#define _GUI_BUTTON_H_

#include "gui_component.h"
#include "textlabel.h"
#include <generic/utils/ayelog.h>

class
Button : public GUIComponent
{
	public:
		Button(SDL_Surface* root, int x, int y, int w, int h,
				char const* label);
		~Button(void);
		void handleMouseMotion(int x, int y); // overrides
	
	private:
		Textlabel* textlabel;
		bool hover;
		bool active;
};

#endif

