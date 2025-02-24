all: memoize

OBJS = 03-memoize.o memoize.o
CC = gcc
CFLAGS = -Wall -gdwarf-3

memoize: $(OBJS)
	gcc -o a.out $(CFLAGS) $(OBJS) -lm

03-memoize.o: 03-memoize.c memoize.h

memoize.o: memoize.c memoize.h

clean:
	rm -f a.out $(OBJS)
