CXX = g++
OUTPUT = Debug/game
SOURCES = $(wildcard src/*.cpp)
CURRENT_DIR = $(shell chdir)
INCLUDE = -ISDL\x86_64-w64-mingw32\include -LSDL\x86_64-w64-mingw32\lib
FLAGS = -lSDL2 -lSDL2main -mwindows -pthread -std=c++11

$(OUTPUT):
	$(CXX) $(INCLUDE) $(SOURCES) $(FLAGS) -o $(OUTPUT)