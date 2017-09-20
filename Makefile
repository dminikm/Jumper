rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CC = g++
TARGET = game
FLAGS = -std=c++14 -g -ggdb -O1 
INCLUDE = -Idependencies\SDL2\include -Idependencies\SDL2_mixer\include -Ldependencies\SDL2\lib  -Ldependencies\SDL2_mixer\lib
LINK = -lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_mixer
SRC_DIR = src/
OUTPUT_DIR = bin/
BUILD_DIR = build/

SOURCES = $(call rwildcard,$(SRC_DIR),*.cpp)
OBJECTS = $(patsubst src/%.cpp,build/%.o,$(SOURCES))
OBJECTS_FINAL = $(addprefix build/,$(notdir $(OBJECTS)))


build/%.o: src/%.cpp
	$(CC) $(FLAGS) -c $< -o $(BUILD_DIR)$(notdir $@) $(INCLUDE)

all: $(OBJECTS)
	$(CC) $(INCLUDE) $(FLAGS) $(OBJECTS_FINAL) -o $(OUTPUT_DIR)$(TARGET) $(INCLUDE) $(LINK)

init:
	mkdir bin
	mkdir build
	mkdir dependencies

print-%  : ; @echo $* = $($*)