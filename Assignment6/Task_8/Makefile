CC = gcc

Myexe:	Main.o Helper.o
	$(CC) Main.o Helper.o -o Myexe

Main.o:
	$(CC) -c Main.c 

Helper.o:
	$(CC) -c Helper.c

run:
	./Myexe

clean:
	rm -f Myexe *.o