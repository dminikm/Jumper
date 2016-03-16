CXX = g++
OUTPUT = Debug/game 
SOURCES = $(wildcard src/*.cpp)
CURRENT_DIR = $(shell chdir)
INCLUDE = -ISDL\i686-w64-mingw32\include -LSDL\i686-w64-mingw32\lib
FLAGS = -lSDL2 -lSDL2main -lSDL2_mixer -pthread -std=c++11 -lmingw32 

$(OUTPUT):
	$(CXX) $(INCLUDE) $(SOURCES) $(FLAGS) -o $(OUTPUT)