#include "basic_elements.h"



std::list<Widget*> all_widget_handler;
int current_global_widget_ID=0;
SDL_Surface * GUI_screen = 0;


void GUI_Init(SDL_Surface * screen)
{
	GUI_screen = screen;
}

TTF_Font * GUI_standard_font = NULL;