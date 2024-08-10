CC = g++ -std=c++11
exe_file = run
$(exe_file): Card.o Hand.o Deck.o Player.o Game.o CrazyEights.o prog.o
	$(CC) Card.o Hand.o Deck.o Player.o Game.o CrazyEights.o prog.o -o $(exe_file)
Card.o: Card.cpp
	$(CC) -c Card.cpp
Hand.o: Hand.cpp
	$(CC) -c Hand.cpp
Deck.o: Deck.cpp 
	$(CC) -c Deck.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp
Game.o: Game.cpp 
	$(CC) -c Game.cpp
CrazyEights.o: CrazyEights.cpp
	$(CC) -c CrazyEights.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm –f *.out *.o $(exe_file)
