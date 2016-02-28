.PHONY : clean
.PHONY : oclean
CC=gcc
CFLAGS=-c -Wextra -g
CONT=list

all: list

list: main.o list.o container.o
	$(CC) main.o list.o container.o -o $@ -g -Wextra -DCREATE=$(CONT)_create

main.o: main.c
	$(CC) $(CFLAGS) main.c -DCREATE=$(CONT)_create

list.o: list.c
	$(CC) $(CFLAGS) list.c

container.o: container.c
	$(CC) $(CFLAGS) container.c

clean:
	rm -rf *.o list
oclean:
	rm -rf *.o
