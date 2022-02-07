CC := gcc
SOURCES := src/main.c

all: run

run: 
	$(CC) -o wordle $(SOURCES) 

clean: 
	rm wordle
