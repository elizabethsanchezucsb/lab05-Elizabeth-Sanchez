CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

all: game_set game

game_set: main_set.o card.o
	$(CXX) $(CXXFLAGS) -o game_set main_set.o card.o

game: main.o card.o card_list.o
	$(CXX) $(CXXFLAGS) -o game main.o card.o card_list.o

tests: tests.o card.o card_list.o
	$(CXX) $(CXXFLAGS) -o tests tests.o card.o card_list.o

main_set.o: main_set.cpp card.h
	$(CXX) $(CXXFLAGS) -c main_set.cpp

main.o: main.cpp card.h card_list.h
	$(CXX) $(CXXFLAGS) -c main.cpp

card.o: card.cpp card.h
	$(CXX) $(CXXFLAGS) -c card.cpp

card_list.o: card_list.cpp card_list.h
	$(CXX) $(CXXFLAGS) -c card_list.cpp

tests.o: tests.cpp card.h card_list.h
	$(CXX) $(CXXFLAGS) -c tests.cpp

clean:
	rm -f *.o game_set game tests
