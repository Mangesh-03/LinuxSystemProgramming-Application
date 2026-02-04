CC = gcc
CFLAGS = -Wall -Wextra -O2


app : Main.o
	$(CC) $(CFLAGS) Main.o -o app

Main.o : 
	$(CC) -c Main.c

run :
	./app

clean :
	rm -f *.o app

	
