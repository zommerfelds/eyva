/*
 * EYVA - various SDL related functionalities
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

#ifndef _GUI_UTILS_H_
#define _GUI_UTILS_H_

#include <generic/utils/exception.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

enum
GUIComponentName
{
	// relative names:
	GUI_COMPONENT_THIS,
	GUI_COMPONENT_NEXT,
	GUI_COMPONENT_PREVIOUS,
	GUI_COMPONENT_NONE,

	// main menu:
	GUI_COMPONENT_LOGIN,
	GUI_COMPONENT_MENU,
	GUI_COMPONENT_OPTIONS,
	GUI_COMPONENT_PLAYGROUND,
	GUI_COMPONENT_SOCIAL,
	GUI_COMPONENT_NAVIGATION,
	GUI_COMPONENT_CHARACTER
};

namespace
GUIUtils
{
	extern char ktoc(Uint8* keys);
	extern SDL_Surface* newSurface(Uint32 flags, int w, int h,
			const SDL_Surface* dst);
};

#endif

