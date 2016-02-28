.PHONY : clean
CC=gcc
CFLAGS=-c -Wextra -g

all: list

list: main.o list.o container.o
	$(CC) main.o list.o container.o -o $@ -g -Wextra

main.o: main.c
	$(CC) $(CFLAGS) main.c
	
list.o: list.c
	$(CC) $(CFLAGS) list.c

container.o: container.c
	$(CC) $(CFLAGS) container.c

clean:
	rm -rf *.o list
oclean:
	rm -rf *.o
