CXX = g++
CXXFLAGS = -g --std=c++20 -Wall

all: game

game: card_list.o card.o main.o
	$(CXX) $(CXXFLAGS) card_list.o card.o main.o -o game

card_list.o: card_list.cpp card.h
	$(CXX) $(CXXFLAGS) -c card_list.cpp

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp

main.o: main.cpp card.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o game
