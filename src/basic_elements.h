#ifndef BASIC_ELEMENTS_H
#define BASIC_ELEMENTS_H

#include <string>
#include <map>
#include <set>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <list>
#include <iostream>


enum SDL_Border_Style
{
	line,
	dotted,
	none
};


class Widget;
extern std::list<Widget*> all_widget_handler;
extern int current_global_widget_ID;
extern SDL_Surface * GUI_screen;
extern TTF_Font * GUI_standard_font;
void GUI_Init(SDL_Surface * screen);


class Clickable
{
public:
	void (*on_click)(void);
private:
};

class Text_Container
{
public:
	void set_text(std::string text);
	std::string get_text();
	void set_font(TTF_Font * font);
	void set_text_colour(Uint8 r, Uint8 g, Uint8 b);
};


class Child_Supporter
{
	
public:

};


class Widget
{
public:
	inline int get_ID (){return this->ID;}
	inline int get_width(){return this->width;}
	inline int get_height(){return this->height;}
	inline int get_x(){return this->x;}
	inline int get_y(){return this->y;}


	inline int set_ID(int ID){this->ID = ID;}
	inline int set_width(int width){this->width = width;}
	inline int set_height(int height){this->height = height;}
	inline int set_x(int x){this->x = x;}
	inline int set_y(int y){this->y = y;}

	virtual SDL_Surface* get_sdl_surface(){};
	virtual void update(){};

	inline void set_colour(Uint8 r, Uint8 g, Uint8 b){ this->colour = SDL_MapRGB(GUI_screen->format, r, g, b); }
	inline void set_border_colour(Uint8 r, Uint8 g, Uint8 b){ this->border_colour = SDL_MapRGB(GUI_screen->format, r, g, b);	}
	inline void set_border_style(SDL_Border_Style style) { this->border_style=style; }

	void set_parent(Widget * parent);
	Widget * get_parent();

	inline void add_child(Widget * child)
	{
		this->children.push_back(child);
	}


protected:
	Uint32 colour;
	Uint32 border_colour;
	SDL_Border_Style border_style;
	int ID;
	int width, height, x, y;
	Widget * parent;
	std::list<Widget*> children;
};




#endif