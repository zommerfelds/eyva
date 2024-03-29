/*
 * EYVA - textlabel element
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

#include "textlabel.h"

/**
 * @param root      Surface on which the label shall be printed on.
 * @param alignment How to align the label. The position is aligned, too.
 * @param x         X position.
 * @param y         Y position.
 * @param label     Label to be printed.
 * @param size      Label size.
 * @param r         Red component.
 * @param g         Green component.
 * @param b         Blue component.
 * @param a         Alpha component.
 */
Textlabel::Textlabel(SDL_Surface* root, Alignment alignment, int x, int y,
		char const* label, int size, char r, char g, char b, char a)
{
	// TODO handle zero length strings:
	font = TTF_OpenFont("usr/fonts/FreeSans.ttf", size);
	if(font == NULL || root == NULL || strlen(label) == 0)
		throw new Exception("textlabel: invalid data");

	this->label = new char[strlen(label)+1]; // +1 for \0
	strcpy(this->label, label);

	updateColor(r, g, b, a);

	// render with the information above:
	local = TTF_RenderText_Blended(font, label, color);

	rectangle = new SDL_Rect();
	rectangle->w = local->w;
	rectangle->h = local->h;
	switch(alignment) {
		case TOP_LEFT:
			rectangle->x = x;
			rectangle->y = y;
			break;
		case TOP_CENTER:
			rectangle->x = x-local->w/2;
			rectangle->y = y;
			break;
		case TOP_RIGHT:
			rectangle->x = x-local->w;
			rectangle->y = y;
			break;
		case MIDDLE_LEFT:
			rectangle->x = x;
			rectangle->y = y-local->h/2;
			break;
		case MIDDLE_CENTER:
			rectangle->x = x-local->w/2;
			rectangle->y = y-local->h/2;
			break;
		case MIDDLE_RIGHT:
			rectangle->x = x-local->w;
			rectangle->y = y-local->h/2;
			break;
		case BOTTOM_LEFT:
			rectangle->x = x;
			rectangle->y = y-local->h;
			break;
		case BOTTOM_CENTER:
			rectangle->x = x-local->w/2;
			rectangle->y = y-local->h;
			break;
		case BOTTOM_RIGHT:
			rectangle->x = x-local->w;
			rectangle->y = y-local->h;
			break;
	}

	// here we draw:
	this->root = root;
}

Textlabel::~Textlabel(void)
{
	TTF_CloseFont(font);
	delete rectangle;
	delete[] label;
}


/* PUBLIC METHODS */


/**
 * Set a new label.
 * @param label The new label.
 */
void
Textlabel::updateLabel(char const* label)
{
	delete[] this->label;
	this->label = new char[strlen(label)+1]; // +1 for \0
	strcpy(this->label, label);
	local = TTF_RenderText_Blended(font, label, color);
}

/**
 * Set a new color.
 * @param r Red component.
 * @param g Green component.
 * @param b Blue component.
 * @param a Alpha component.
 */
void
Textlabel::updateColor(char const r, char const g, char const b, char const a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.unused = a;
	local = TTF_RenderText_Blended(font, label, color);
}

/**
 * Print the text to the root surface.
 */
void
Textlabel::print(void)
{
	SDL_BlitSurface(local, NULL, root, rectangle);
}

