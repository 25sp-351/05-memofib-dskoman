all: memoize

OBJS = 03-memoize-fib.o memoize.o fib.o
CC = gcc
CFLAGS = -Wall -gdwarf-3

memoize: $(OBJS)
	gcc -o a.out $(CFLAGS) $(OBJS) -lm

03-memoize-fib.o: 03-memoize-fib.c

memoize.o: memoize.c memoize.h

fib.o: fib.c fib.h

clean:
	rm -f a.out $(OBJS)
