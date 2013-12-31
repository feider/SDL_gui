#include <SDL/SDL.h>
#include <SDL_gui.h>
#include <SDL/SDL_ttf.h>
#include <iostream>




int main(int argc, char * argv[])
{
	input_init();

	std::string path_to_exe("");
	{
		std::string path_with_exe(argv[0]);
		unsigned found = path_with_exe.find_last_of("/\\");
		path_to_exe = path_with_exe.substr(0,found+1);
	}

	std::cout<<path_to_exe<<std::endl;
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();
	SDL_Surface * screen = SDL_SetVideoMode( 640, 480, 32, SDL_HWSURFACE);
	GUI_Init(screen);

	{
		std::string font_path(path_to_exe);
		font_path += "freefont/FreeMono.ttf";
		GUI_standard_font = TTF_OpenFont( font_path.c_str(), 15 );
	}

	std::cout<<"fontptr: "<<GUI_standard_font<<std::endl;


	Area * screen_widget = new Area(0, 0, 640, 480);

	Area * test_widget = new Area(20, 20, 200, 200, screen_widget);
	test_widget->set_colour(200, 100, 100);

	Area * another_test_widget = new Area(240, 20, 200, 200, screen_widget);
	another_test_widget->set_colour(100, 200, 100);

	Area * ultra_test_widget = new Area(20, 20, 160, 160, another_test_widget);
	ultra_test_widget->set_colour(100, 100, 200);

	Label * test_label = new Label(10, 10, 140, 20, ultra_test_widget);
	test_label->set_colour(120, 120, 220);
	test_label->set_text("Hallo Welt!");



	Button * test_button = new Button(10, 40, 120, 20, ultra_test_widget);
	test_button->set_colour(100, 200, 200);
	test_button->set_text("Test!");

	Button * end_button = new Button(20, 240, 120, 20, screen_widget);
	end_button->set_colour(255, 0, 0);
	end_button->set_text("Ende!");




	Text_Edit * text_edit = new Text_Edit(20, 280, 160, 20, screen_widget);
	text_edit->set_text("aender mich!");



	input_update();
	while(!key_hit(SDLK_ESCAPE) && !end_button->released)// && !mouse_hit(1))
	{
		SDL_Surface * screen_surface = screen_widget->get_sdl_surface();	
		SDL_BlitSurface(screen_surface, NULL, screen, NULL);

		screen_widget->update();
		if(test_button->released)
		{
			test_label->set_text("Button geklickt!");
		}
		SDL_Flip(screen);
		flush_keys();
		flush_mouse();
		SDL_Delay(1000/60);
		input_update();
	}

	//SDL_Delay(2000);

	return 0;
}