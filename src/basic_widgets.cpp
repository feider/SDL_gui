#include "basic_widgets.h"

typedef std::list<Widget*>::iterator Widget_Iterator;

Area::Area(int x, int y, int width, int height)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_border_style(line);
	this->set_parent(NULL);
	current_global_widget_ID++;
}

Area::Area(int x, int y, int width, int height, Widget * parent)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_border_style(line);
	this->set_parent(parent);
	current_global_widget_ID++;
}

SDL_Surface* Area::get_sdl_surface()
{

	SDL_Surface * return_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, (Uint16) this->get_width(), (Uint16) this->get_height(), 32, 0, 0, 0, 0);
	SDL_Rect rs_rect({0, 0, this->get_width(), this->get_height()});
	SDL_FillRect(return_surface, &rs_rect, this->colour);
	for(Widget_Iterator it = this->children.begin(); it != this->children.end(); ++it)
	{
		SDL_Surface * blit_surface = (*it)->get_sdl_surface();
		short int blit_x = (short int) (*it)->get_x();
		short int blit_y = (short int) (*it)->get_y();
		short unsigned blit_width = (short unsigned int) (*it)->get_width();
		short unsigned int blit_height = (short unsigned int) (*it)->get_height();

		SDL_Rect blit_rect = {blit_x, blit_y, blit_width, blit_height};
		SDL_BlitSurface(blit_surface, NULL, return_surface, &blit_rect);
		SDL_FreeSurface(blit_surface);
	}

	return return_surface;
}

void Area::update()
{
	for(Widget_Iterator it = this->children.begin(); it != this->children.end(); ++it)
	{
		(*it)->update();
	}
}

void Area::set_parent(Widget * parent)
{ 
	this->parent = parent;
	if(parent)
	{
		parent->add_child(this);
	}
} 

Widget * Area::get_parent()
{ 
	return this->parent; 
}


Label::Label(int x, int y, int width, int height)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_text_colour(0,0,0);
	this->set_border_style(none);
	this->set_parent(NULL);
	this->set_font(GUI_standard_font);
	current_global_widget_ID++;
}
Label::Label(int x, int y, int width, int height, Widget * parent)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_text_colour(0,0,0);
	this->set_border_style(none);
	this->set_parent(parent);
	this->set_font(GUI_standard_font);
	current_global_widget_ID++;
}
Label::Label(int x, int y, int width, int height, TTF_Font * font)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_text_colour(0,0,0);
	this->set_border_style(none);
	this->set_parent(NULL);
	this->set_font(font);
	current_global_widget_ID++;
}
Label::Label(int x, int y, int width, int height, TTF_Font * font, Widget * parent)
{
	this->set_x(x);
	this->set_y(y);
	this->set_width(width);
	this->set_height(height);
	this->set_ID(current_global_widget_ID);
	this->set_colour(200, 200, 200);
	this->set_border_colour(0, 0, 0);
	this->set_text_colour(0,0,0);
	this->set_border_style(none);
	this->set_parent(parent);
	this->set_font(font);
	current_global_widget_ID++;
}


void Label::set_parent(Widget * parent)
{ 
	this->parent = parent;
	if(parent)
	{
		parent->add_child(this);
	}
} 

Widget * Label::get_parent()
{ 
	return this->parent; 
}


SDL_Surface* Label::get_sdl_surface()
{
	SDL_Surface * return_surface = TTF_RenderText_Solid(this->font, this->text.c_str(), *(this->text_colour));
	SDL_Rect rs_rect({0, 0, 0,0});//this->get_width(), this->get_height()});
	//SDL_FillRect(return_surface, &rs_rect, this->colour);
	return return_surface;
};