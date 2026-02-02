CC = gcc

Myexe: Main.o
	$(CC) Main.o -o Myexe

Main.o:
	$(CC) -c Main.c -o Main.o

clean:
	rm -f *.o Myexe

run:	
	./Myexe