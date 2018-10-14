# Makefile para el Proyecto 
# Andres Labbe
# Oswaldo Capriles

BIN   = main
CC    = gcc
FLAGS = -lm -Wall -Wextra

all:
	$(CC) -o $(BIN) main.c matrix.c $(FLAGS)

run: all
	./$(BIN)

clean:
	rm -f $(BIN) *.o
	@echo "Cleaned!"

love:
	@echo "Not war"

