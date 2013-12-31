all: SDL_gui.o basic_widgets.o basic_elements.o input.o
	ar -r libSDL_gui.a basic_widgets.o SDL_gui.o basic_elements.o input.o
	mkdir -p ../lib
	mv libSDL_gui.a ../lib

SDL_gui.o: SDL_gui.cpp SDL_gui.h
	c++ -g -c -Wall SDL_gui.cpp --std=c++11 -o SDL_gui.o

basic_widgets.o: basic_widgets.h basic_widgets.cpp
	c++ -g -c -Wall basic_widgets.cpp --std=c++11 -o basic_widgets.o

basic_elements.o: basic_elements.h basic_elements.cpp
	c++ -g -c -Wall basic_elements.cpp --std=c++11 -o basic_elements.o

input.o: input.cpp input.h
	c++ -g -c -Wall input.cpp --std=c++11 -o input.o

clean:
	rm *.o

ultra-clean: clean
	rm ../*.a

install:
	mkdir -p /usr/local/lib
	cp -f ../lib/libSDL_gui.a /usr/local/lib/
	mkdir -p /usr/local/include/SDL
	cp -f *.h /usr/local/include/SDL/