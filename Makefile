all: main_set main

main_set: main_set.cpp card_list.cpp
	# Use a tab here instead of spaces
	g++ -o main_set main_set.cpp card_list.cpp

main: main.cpp card_list.cpp
	# Use a tab here instead of spaces
	g++ -o main main.cpp card_list.cpp

clean:
	# Use a tab here instead of spaces
	rm -f main_set main