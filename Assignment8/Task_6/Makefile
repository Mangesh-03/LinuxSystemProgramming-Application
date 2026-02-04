CC = gcc
CFLAGS = -Wall -Wextra -O2

ARGS = -fPIC -shared

app: libmath.so Main.o
	@$(CC) Main.o -o app -ldl

libmath.so : math.o 
	@$(CC) $(ARGS) -o libmath.so math.o

Main.o:
	@$(CC) -c Main.c 

math.o  : 
	@$(CC) -c math.c 

run:
	@LD_LIBRARY_PATH=. ./app

clean : 
	@rm -f *.o *.a app

help : 
	@echo "Building Process : make"
	@echo "Cleaning Process : make clean"