CC = g++
exe_file = run
$(exe_file): Animal.o Sealion.o Bear.o Tiger.o Zoo.o ZooTycoon.o prog.o
	$(CC) Animal.o Sealion.o Bear.o Tiger.o Zoo.o ZooTycoon.o prog.o -o $(exe_file)
Animal.o: Animal.cpp
	$(CC) -c Animal.cpp
Sealion.o: Sealion.cpp
	$(CC) -c Sealion.cpp
Bear.o: Bear.cpp
	$(CC) -c Bear.cpp
Tiger.o: Tiger.cpp
	$(CC) -c Tiger.cpp
Zoo.o: Zoo.cpp
	$(CC) -c Zoo.cpp
ZooTycoon.o: ZooTycoon.cpp
	$(CC) -c ZooTycoon.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm –f *.out *.o $(exe_file)