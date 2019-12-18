CC = gcc -g
AR = ar -rcs
FLAGS = -Wall -fPIC

all: isort txtfind
isort: isort.o mainSort.o
	$(CC) $(FLAGS) -o isort isort.o mainSort.o
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c
mainSort.o: mainSort.c
	$(CC) $(FLAGS) -c mainSort.c
txtfind: txtfind.o mainStr.o
	$(CC) $(FLAGS) -o txtfind txtfind.o mainStr.o
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c
mainStr.o: mainStr.c
	$(CC) $(FLAGS) -c mainStr.c

.PHONY: clean all mybanks mybankd

clean:
	rm -f *.o *.a *.so isort txtfind