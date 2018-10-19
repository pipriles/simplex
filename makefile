# Makefile para el Proyecto 
# Andres Labbe
# Oswaldo Capriles

BIN   = main
CC    = gcc
LIB   = matrix.c simplex.c
FLAGS = -lm -Wall -Wextra

all:
	$(CC) -o $(BIN) main.c $(LIB) $(FLAGS)

debug:
	$(CC) -g -o $(BIN) main.c $(LIB) $(FLAGS)

run: all
	./$(BIN)

clean:
	rm -f $(BIN) *.o
	@echo "Cleaned!"

love:
	@echo "Not war"

