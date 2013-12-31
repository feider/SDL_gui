
#include "input.h"
#include <SDL/SDL.h>
#include <iostream>

// general input stuff

#define MOUSE_BUTTONS 256

bool key_down_array[SDLK_LAST];
bool key_was_down_array[SDLK_LAST];
bool button_down_array[MOUSE_BUTTONS];
bool button_was_down_array[MOUSE_BUTTONS];

int mouse_x, mouse_y;

void input_init()
{
	for(int i = 0; i < SDLK_LAST; i++)
	{
		key_down_array[i] = 0;
		key_was_down_array[i] = 0;
	}
}

SDL_Event e;
void input_update()
{
	//SDL_PumpEvents();
	//here be magic
	Uint8* keys;
	SDL_PollEvent(&e);
	keys = SDL_GetKeyState(NULL);
	for(int i = 0; i<SDLK_LAST; i++)
	{
		key_down_array[i] = (bool) keys[i];

		if(!key_down_array[i])
		{
			//if(key_was_down_array[i])
			//	std::cout<<"release key "<<i<<std::endl;

			key_was_down_array[i] = false;

		}
	}

	//free(keys);

	Uint8 buttons;

	buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
	for(int i = 0; i<MOUSE_BUTTONS; i++)
	{
		button_down_array[i] = ((buttons&SDL_BUTTON(i)) != 0);
		if(!button_down_array[i])
		{
			//if(button_was_down_array[i])
			//	std::cout<<"release button "<<i<<std::endl;

			button_was_down_array[i] = false;

		}
	}


}


// keyboard stuff



bool key_down(int key)
{
	return key_down_array[key];
}

bool key_hit(int key)
{
	if(key_down_array[key] && !key_was_down_array[key])
	{
		key_was_down_array[key]=true;
		//std::cout<<"hit key "<<key<<std::endl;
		return true;

	}
	return false;
}


void flush_keys()
{
	for(int i = 0; i<SDLK_LAST; i++)
	{
		key_down_array[i] = false;
		key_was_down_array[i] = false;
	}
}



//mouse stuff

bool mouse_down(int button)
{
	return button_down_array[button];
}

bool mouse_hit(int button)
{
	if(button_down_array[button] && !button_was_down_array[button])
	{
		button_was_down_array[button]=true;
		//std::cout<<"hit button "<<button<<std::endl;
		return true;

	}
	return false;
}


void flush_mouse()
{
	for(int i = 0; i<MOUSE_BUTTONS; i++)
	{
		button_down_array[i] = false;
		button_was_down_array[i] = false;
	}
}

int get_mouse_x()
{
	return mouse_x;
}

int get_mouse_y()
{
	return mouse_y;
}