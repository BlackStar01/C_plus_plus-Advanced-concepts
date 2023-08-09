CC = g++
CFLAGS = -g -Wall -ansi -pedantic
OBJ:=test.o
EXE=test

test: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

test.o: ./test.cpp
	gcc -c ./test.cpp

clean:
	rm -f $(OBJ) $(EXE)