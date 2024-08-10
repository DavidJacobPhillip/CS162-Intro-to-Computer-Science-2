CC = g++ -std=c++11
exe_file = run
$(exe_file): Event.o Bats.o Gold.o Pit.o Start.o Wumpus.o Room.o HuntTheWumpus.o prog.o
	$(CC) Event.o Bats.o Gold.o Pit.o Start.o Wumpus.o Room.o HuntTheWumpus.o prog.o -o $(exe_file)
Event.o: Event.cpp
	$(CC) -c Event.cpp
Bats.o: Bats.cpp
	$(CC) -c Bats.cpp
Gold.o: Gold.cpp
	$(CC) -c Gold.cpp
Pit.o: Pit.cpp
	$(CC) -c Pit.cpp
Start.o: Start.cpp
	$(CC) -c Start.cpp
Wumpus.o: Wumpus.cpp
	$(CC) -c Wumpus.cpp
Room.o: Room.cpp
	$(CC) -c Room.cpp
HuntTheWumpus.o: HuntTheWumpus.cpp
	$(CC) -c HuntTheWumpus.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *a.out *.o $(exe_file)