CC = gcc
CFLAGS = -Wall -Wextra -O2


app : Main.o Helper.o
	@$(CC) $(CFLAGS) Main.o Helper.o -o app

Main.o : 
	@$(CC) -c Main.c

Helper.o : 
	@$(CC) -c Helper.c

run :
	@./app

clean :
	@rm -f *.o app

help : 
	@echo "Building Process : make"
	@echo "Running Process : make run"
	@echo "Cleaning Process :  make clean"
	
