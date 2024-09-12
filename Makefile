CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS =

SRC = src/Game.cpp src/Grid.cpp src/Tile.cpp src/main.cpp
INCLUDES = include/Game.hpp include/Grid.hpp include/Tile.hpp

TARGET = game

all: $(TARGET)

$(TARGET): $(SRC) $(INCLUDES)
	$(CXX) $(CXXFLAGS) -Iinclude $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)