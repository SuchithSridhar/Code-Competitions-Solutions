CC = gcc
CFLAGS = -Wall -g -Wextra

help:
	@printf "Read the makefile\n"

q1: src/stringToInt.c src/largeNumberRemainder.c src/q1.c
	mkdir -f bin
	$(CC) $(CFLAGS) -o bin/q1 src/stringToInt.c src/largeNumberRemainder.c src/q1.c

clean:
	rm -f bin/*
