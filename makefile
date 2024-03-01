CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJ=main.o terminal.o maze.o move.o
EXEC=maze

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c maze.h terminal.h move.h
	$(CC) $(CFLAGS) -c main.c


maze.o: maze.c maze.h
	$(CC) $(CFLAGS) -c maze.c

terminal.o: terminal.c terminal.h move.h 
	$(CC) $(CFLAGS) -c terminal.c

move.o: move.c move.h
	$(CC) $(CFLAGS) -c move.c