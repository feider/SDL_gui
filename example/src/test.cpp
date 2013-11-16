#include <SDL/SDL.h>
#include <SDL_gui.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

int main()
{
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();
	SDL_Surface * screen = SDL_SetVideoMode( 640, 480, 32, SDL_HWSURFACE);
	GUI_Init(screen);
	GUI_standard_font = TTF_OpenFont( "freefont/FreeMono.ttf", 15 );
	std::cout<<"fontptr: "<<GUI_standard_font<<std::endl;


	Area * screen_widget = new Area(0, 0, 640, 480);
	Area * test_widget = new Area(20, 20, 200, 200, screen_widget);
	test_widget->set_colour(200, 100, 100);

	Area * another_test_widget = new Area(240, 20, 200, 200, screen_widget);
	another_test_widget->set_colour(100, 200, 100);

	Area * ultra_test_widget = new Area(20, 20, 160, 160, another_test_widget);
	ultra_test_widget->set_colour(100, 100, 200);

	Label * test_label = new Label(10, 10, 140, 50, ultra_test_widget);
	test_label->set_colour(100, 100, 200);
	test_label->set_text("Hallo Welt!");

	SDL_Surface * screen_surface = screen_widget->get_sdl_surface();	
	SDL_BlitSurface(screen_surface, NULL, screen, NULL);
	SDL_Flip(screen);
	SDL_Delay(5000);

	return 0;
}