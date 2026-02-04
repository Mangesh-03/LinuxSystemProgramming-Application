CC = gcc
CFLAGS = -Wall -Wextra -O2
ARGS = rcs
AR = ar
OBJ = math.o
LIB = libmath.a 

app : $(LIB) Main.o
	@$(CC)  Main.o -L. $(LIB) -o app -w

$(LIB) :$(OBJ)
	@$(AR) $(ARGS) $(LIB) $(OBJ)
	
$(OBJ) : 
	@$(CC) -c math.c -w

Main.o:
	@$(CC) -c Main.c -w

run : 
	@./app

clean : 
	@rm -f *.o  app

help : 
	@echo "Building Process : make"
	@echo "Cleaning Process : make clean"