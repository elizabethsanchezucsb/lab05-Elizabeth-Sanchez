all: game_set game

game_set: main_set.o card.o
	g++ -o game_set main_set.o card.o

game: main.o card.o card_list.o
	g++ -o game main.o card.o card_list.o

main_set.o: main_set.cpp card.h
	g++ -c main_set.cpp

main.o: main.cpp card.h card_list.h
	g++ -c main.cpp

card.o: card.cpp card.h
	g++ -c card.cpp

card_list.o: card_list.cpp card_list.h card.h
	g++ -c card_list.cpp

clean:
	rm -f *.o game_set game
