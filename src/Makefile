all: SDL_gui.o basic_widgets.o basic_elements.o
	ar -r libSDL_gui.a *.o
	mkdir -p ../lib
	mv libSDL_gui.a ../lib

SDL_gui.o: SDL_gui.cpp SDL_gui.h
	c++ -g -c SDL_gui.cpp --std=c++11 -o SDL_gui.o

basic_widgets.o: basic_widgets.h basic_widgets.cpp
	c++ -g -c basic_widgets.cpp --std=c++11 -o basic_widgets.o

basic_elements.o: basic_elements.h basic_elements.cpp
	c++ -g -c basic_elements.cpp --std=c++11 -o basic_elements.o

clean:
	rm *.o

ultra-g -clean: clean
	rm ../*.a

install:
	mkdir -p /usr/local/lib
	cp -f ../lib/libSDL_gui.a /usr/local/lib/
	mkdir -p /usr/local/include/SDL
	cp -f *.h /usr/local/include/SDL/