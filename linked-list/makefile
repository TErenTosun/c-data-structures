CC = gcc 

default: main.o linked_list.o
	${CC} main.o linked_list.o -o main.exe

linked_list.o: linked_list.c linked_list.h
	${CC} -c linked_list.c

main.o: main.c linked_list.h
	${CC} -c main.c

clean:
	del *.o *.exe