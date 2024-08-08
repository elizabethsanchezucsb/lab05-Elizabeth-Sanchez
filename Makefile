CC = g++
CFLAGS = -std=c++11 -Wall

all: game_set game

game_set: main_set.cpp card.cpp
	$(CC) $(CFLAGS) -o game_set main_set.cpp card.cpp

game: main.cpp card_list.cpp card.cpp
	$(CC) $(CFLAGS) -o game main.cpp card_list.cpp card.cpp

tests: tests.cpp card_list.cpp card.cpp
	$(CC) $(CFLAGS) -o tests tests.cpp card_list.cpp card.cpp

clean:
	rm -f game_set game tests
