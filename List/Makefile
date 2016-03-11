.PHONY : clean
.PHONY : oclean
#CC=gcc
CXXFLAGS=-c -Wextra -g -Wall
CONT=list

all: list

list: main.o list.o container.o
	$(CC) *.o -o $@ -g -Wextra -DCREATE=$(CONT)_create

main.o: main.c
	$(CC) $(CXXFLAGS) main.c -DCREATE=$(CONT)_create

list.o: list.c
	$(CC) $(CXXFLAGS) list.c

container.o: container.c
	$(CC) $(CXXFLAGS) container.c

clean:
	rm -rf *.o list
oclean:
	rm -rf *.o
