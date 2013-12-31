#ifndef BASIC_WIDGETS_H
#define BASIC_WIDGETS_H

#include <string>
#include "basic_elements.h"

class Area: public Widget, Child_Supporter
{
public:
	SDL_Surface* get_sdl_surface();

	Area(int x, int y, int width, int height);
	Area(int x, int y, int width, int height, Widget * parent);

	void update();
protected:


private:
};








class Label: public Widget
{
public:
	SDL_Surface* get_sdl_surface();


	Label(int x, int y, int width, int height);
	Label(int x, int y, int width, int height, Widget * parent);
	Label(int x, int y, int width, int height, TTF_Font * font);
	Label(int x, int y, int width, int height, TTF_Font * font, Widget * parent);

	//From Text Container
	void set_text(std::string text){this->text = text;}
	std::string get_text(){return this->text;}
	void set_font(TTF_Font * font){this->font = font;};
	void set_text_colour(Uint8 r, Uint8 g, Uint8 b){ this->text_colour = new SDL_Color({r, g, b, 0}); }

private:
	SDL_Color * text_colour;
	std::string text;
	TTF_Font * font;
};












class Button: public Widget
{
public:
	SDL_Surface* get_sdl_surface();


	Button(int x, int y, int width, int height);	
	Button(int x, int y, int width, int height, Widget * parent);

	//From Text Container
	void set_text(std::string text){this->text = text;}
	std::string get_text(){return this->text;}
	void set_font(TTF_Font * font){this->font = font;};
	void set_text_colour(Uint8 r, Uint8 g, Uint8 b){ this->text_colour = new SDL_Color({r, g, b, 0}); }


	void update();

private:
	SDL_Color * text_colour;
	std::string text;
	TTF_Font * font;
};


// One line text edit
class Text_Edit: public Widget
{
public:
	SDL_Surface* get_sdl_surface();


	Text_Edit(int x, int y, int width, int height);	
	Text_Edit(int x, int y, int width, int height, Widget * parent);

	bool focused;
	bool typing;



	//From Text Container
	void set_text(std::string text){this->text = text;}
	std::string get_text(){return this->text;}
	void set_font(TTF_Font * font){this->font = font;};
	void set_text_colour(Uint8 r, Uint8 g, Uint8 b){ this->text_colour = new SDL_Color({r, g, b, 0}); }

	
	void update();

private:
	SDL_Color * text_colour;
	std::string text;
	TTF_Font * font;
};




class Text_Field: public Widget
{
};

#endif