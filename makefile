CC = gcc -g
CFLAGS = -c -Wall -ansi -pedantic
OBJ = main.o move_up.o move_down.o move_left.o move_right.o printKeyPad.o terminal.o clear.o
HEADERS = move.h printkeypad.h 
EXEC = calculator

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c $(HEADERS)
		$(CC) $(CFLAGS)  main.c

move_up.o : move_up.c move.h
			$(CC) $(CFLAGS)  move_up.c

move_down.o : move_down.c move.h
			$(CC) $(CFLAGS)  move_down.c

move_left.o : move_left.c move.h
			$(CC) $(CFLAGS)  move_left.c

move_right.o : move_right.c move.h
			$(CC) $(CFLAGS)  move_right.c

print.o : printKeyPad.c print.h
			$(CC) $(CFLAGS)  printKeyPad.c

terminal.o : terminal.c terminal.h
			$(CC) $(CFLAGS)  terminal.c

clear.o : clear.c clear.h
			$(CC) $(CFLAGS) clear.c

clean : 
		rm -f $(EXEC) $(OBJ)