CC = g++
CFLAGS = -g -std=c++11 -Wall -lncurses -lm
EXECUTABLE = TTT

all: TTT

TTT: main.o boardCheck.o printBoard.o
	$(CC) main.o boardCheck.o printBoard.o $(CFLAGS) -o $(EXECUTABLE)

main.o: main.cpp boardCheck.h
	$(CC) -c main.cpp $(CFLAGS) 

boardCheck.o: boardCheck.cpp boardCheck.h
	$(CC) -c boardCheck.cpp $(CFLAGS) 

printBoard.o: printBoard.cpp printBoard.h
	$(CC) -c printBoard.cpp $(CFLAGS)


clean:
	rm -rf *.o $(EXECUTABLE)
