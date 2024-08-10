CC = g++ -std=c++11
exe_file = run
$(exe_file): Implementation.o prog.o
	$(CC) Implementation.o prog.o -o $(exe_file)
Implementation.o: Implementation.cpp
	$(CC) -c Implementation.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *a.out *.o $(exe_file)
