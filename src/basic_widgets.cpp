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
	this->visible=true;
	this->active=true;
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
	this->visible=true;
	this->active=true;
	current_global_widget_ID++;
}

SDL_Surface* Area::get_sdl_surface()
{

	SDL_Surface * return_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, (Uint16) this->get_width(), (Uint16) this->get_height(), 32, 0, 0, 0, 0);
	SDL_Rect rs_rect({0, 0, (Uint16) this->get_width(), (Uint16) this->get_height()});
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
	std::cout<<"before"<<std::endl;
	this->visible=true;
	this->active=true;
	std::cout<<"after"<<std::endl;
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
	this->visible=true;
	this->active=true;
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
	this->visible=true;
	this->active=true;
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
	this->visible=true;
	this->active=true;
	current_global_widget_ID++;
}



SDL_Surface* Label::get_sdl_surface()
{
	SDL_Surface * return_surface = TTF_RenderText_Solid(this->font, this->text.c_str(), *(this->text_colour));
	SDL_Rect rs_rect({0, 0, 0,0});//this->get_width(), this->get_height()});
	//SDL_FillRect(return_surface, &rs_rect, this->colour);
	return return_surface;
};






Button::Button(int x, int y, int width, int height)
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
	this->visible=true;
	this->active=true;
	this->clicked=false;
	current_global_widget_ID++;


}

Button::Button(int x, int y, int width, int height, Widget * parent)
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
	this->visible=true;
	this->active=true;
	this->clicked=false;
	current_global_widget_ID++;

}

SDL_Surface* Button::get_sdl_surface()
{
	SDL_Surface * return_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, this->width, this->height, 32, 0, 0, 0, 0);
	SDL_Rect rs_rect({0, 0, (Uint16) this->get_width(), (Uint16) this->get_height()});
	SDL_FillRect(return_surface, &rs_rect, this->colour);
	SDL_Surface * text_surface = TTF_RenderText_Solid(this->font, this->text.c_str(), *(this->text_colour));

	SDL_Rect text_position( 
		{  (Sint16)((return_surface->w/2)-(text_surface->w/2)), 
			(Sint16)((return_surface->h/2)-(text_surface->h/2)), 
			0, 
			0 } 
						);

	SDL_BlitSurface(text_surface, NULL, return_surface, &text_position);

	SDL_FreeSurface(text_surface);

	//Blit
	return return_surface;
};

void Button::update()
{
	//std::cout<<"updating button!";
	int mx = get_mouse_x();
	int my = get_mouse_y();
	int ax = this->absolute_x();
	int ay = this->absolute_y();

	this->released = false;

	if(this->clicked && mouse_down(1))
	{
		this->clicked = true;
		this->released = false;
	}
	else if( mx>=ax &&
				mx < ax+this->width &&
				my >= ay &&
				my < ay+this->height)
	{
		if(mouse_down(1))
		{
			this->clicked = true;
		}
		else if(this->clicked && !mouse_down(1))
		{
			this->clicked = false;
			this->released = true;
		}
	}
	else
	{
		if(!mouse_down(1) && this->clicked)
		{
			this->clicked = false;
			this->released = false;
		}
	}
	//std::cout <<" clicked:"<<this->clicked<<"; released: "<<this->released<<"; button_x: "<<ax<<"; button_y: "<<ay<<"; mouse_x:"<<mx<<"; mouse_y: "<<my<<std::endl;

}


SDL_Surface* Text_Edit::get_sdl_surface()
{
	SDL_Surface * return_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, this->width, this->height, 32, 0, 0, 0, 0);
	SDL_Rect rs_rect({0, 0, (Uint16) this->get_width(), (Uint16) this->get_height()});
	SDL_FillRect(return_surface, &rs_rect, this->colour);
	SDL_Surface * text_surface = TTF_RenderText_Solid(this->font, this->text.c_str(), *(this->text_colour));

	SDL_Rect text_position( 
		{  (Sint16)((return_surface->w/2)-(text_surface->w/2)), 
			(Sint16)((return_surface->h/2)-(text_surface->h/2)), 
			0, 
			0 } 
						);

	SDL_BlitSurface(text_surface, NULL, return_surface, &text_position);

	SDL_FreeSurface(text_surface);

	//Blit
	return return_surface;
}

Text_Edit::Text_Edit(int x, int y, int width, int height)
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
	this->visible=true;
	this->active=true;
	this->clicked=false;
	this->set_text("");
	this->focused = false;
	this->typing = false;
	current_global_widget_ID++;
}

Text_Edit::Text_Edit(int x, int y, int width, int height, Widget * parent)
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
	this->visible=true;
	this->active=true;
	this->clicked=false;
	this->set_text("");
	this->focused = false;
	this->typing = false;
	current_global_widget_ID++;

}


void Text_Edit::update()
{
	//std::cout<<"updating button!";
	int mx = get_mouse_x();
	int my = get_mouse_y();
	int ax = this->absolute_x();
	int ay = this->absolute_y();

	this->released = false;

	if( mx>=ax &&
				mx < ax+this->width &&
				my >= ay &&
				my < ay+this->height)
	{
		this->focused = true;
	}
	else
	{
		this->focused = false;
	}

	if(this->focused && mouse_hit(1))
	{
		this->typing = true;
	}
	else if (!this->focused && mouse_hit(1))
	{
		this->typing = false;
	}

}


