CC = gcc
CFLAGS = -Wall -std=c99 -g
driver: driver.o board.o danger.o piece.o rules.o 
driver.o: driver.c rules.h
board.o: board.c board.h
danger.o: danger.c danger.h
piece.o: piece.c piece.h
rules.o: rules.c rules.h
clean : 
	rm *.o 
	rm driver 
