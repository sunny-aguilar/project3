# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	February 2019
# Description:	Makefile for Project 3 Fantasy Combat

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += game.o
OBJECTS += character.o
OBJECTS += dice.o
OBJECTS += vampire.o
OBJECTS += barbarian.o
OBJECTS += bluemen.o
OBJECTS += medusa.o
OBJECTS += harrypotter.o
OBJECTS += menu.o


HPPs = zoo.hpp
HPPs += game.hpp
HPPs += character.hpp
HPPs += dice.hpp
HPPs += vampire.hpp
HPPs += barbarian.hpp
HPPs += bluemen.hpp
HPPs += medusa.hpp
HPPs += harrypotter.hpp
HPPs += menu.hpp


CPPs = main.cpp
CPPs += game.cpp
CPPs += character.cpp
CPPs += dice.cpp
CPPs += vampire.cpp
CPPs += barbarian.cpp
CPPs += bluemen.cpp
CPPs += medusa.cpp
CPPs += harrypotter.cpp
CPPs += menu.cpp


# Targets needed to bring the executable up to date
Zoo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Zoo $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

zoo.o: zoo.cpp

menu.o: menu.hpp

animal.o: animal.hpp

tiger.o: tiger.hpp

penguin.o: penguin.hpp

Turtle.o: turtle.hpp


# Clean-up operations
clean:
	rm Zoo *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Zoo

zip:
	zip -D Project2_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
