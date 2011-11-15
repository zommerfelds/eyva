#ifndef _UI_PROMPT_H_
#define _UI_PROMPT_H_

// Parent class:
#include "window.h"

// Client:
#include "../pipe.h"

// Others:
#include <vector>

#define PROMPT_SIZE 80

class
WinPrompt : public Window
{
	public:
		WinPrompt(Pipe* pipe);
		~WinPrompt(void);
		/*virtual*/ WindowName process(int input);
		/*virtual*/ void focus(void);
		/*virtual*/ bool unfocus(void);
		/*virtual*/ void repaint(void);
	
	private:
		WindowName evaluate(void);
		bool cmdcmp(char const* keyword);
		int argcount(void);
		size_t argfetch(char* buffer, int pos);

		Pipe* pipe;
		std::vector<int> prompt;
		unsigned int cursor_pos;
};

#endif
