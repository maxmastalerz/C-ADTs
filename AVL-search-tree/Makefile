CC = gcc
CFLAGS = -Wall -g -Iinclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

testing:$(OBJDIR)testing.o $(OBJDIR)tree.o
	mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)testing $(OBJDIR)testing.o $(OBJDIR)tree.o -lm

$(OBJDIR)testing.o:$(SRCDIR)testing.c include/balancedTreeAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)testing.c -o $(OBJDIR)testing.o

$(OBJDIR)tree.o:$(SRCDIR)tree.c include/balancedTreeAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)tree.c -o $(OBJDIR)tree.o

clean:
	rm $(BINDIR)testing $(OBJDIR)testing.o

doxygen:
	doxygen

cppcheck:
	cppcheck --enable=all --language=c --std=c99 --suppress=missingInclude ./src/*.c -i include
