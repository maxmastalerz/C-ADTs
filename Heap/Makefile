CC = gcc

CFLAGS = -Iinclude 

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

all:
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(SRCDIR)heap.c $(SRCDIR)testing.c -o bin/testing -lm

clean:
	rm $(BINDIR)heap $(BINDIR)testing $(OBJDIR)heap.o $(OBJDIR)testing.o

doxygen:
	doxygen

cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude ./src/*.c -i include