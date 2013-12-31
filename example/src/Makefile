GUI_INCLUDE="../../src"
GUI_LIBRARY="../../lib"

all: test
	

test: test.o
	g++ test.o -L$(GUI_LIBRARY) -lSDL -lSDL_ttf -lSDL_gui   -o ../test

test.o: test.cpp
	g++ -g -c test.cpp -I$(GUI_INCLUDE) --std=gnu++11 -o test.o