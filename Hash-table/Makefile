CC = gcc
CFLAGS = -Wall -g -Iinclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

main:$(OBJDIR)main.o $(OBJDIR)createTable.o $(OBJDIR)createNode.o $(OBJDIR)destroyTable.o $(OBJDIR)insertData.o $(OBJDIR)removeData.o $(OBJDIR)lookupData.o $(OBJDIR)functions.o
	mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)main $(OBJDIR)main.o $(OBJDIR)createTable.o $(OBJDIR)createNode.o $(OBJDIR)destroyTable.o $(OBJDIR)insertData.o $(OBJDIR)removeData.o $(OBJDIR)lookupData.o $(OBJDIR)functions.o

$(OBJDIR)main.o:$(SRCDIR)main.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

$(OBJDIR)createTable.o:$(SRCDIR)createTable.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)createTable.c -o $(OBJDIR)createTable.o

$(OBJDIR)createNode.o:$(SRCDIR)createNode.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)createNode.c -o $(OBJDIR)createNode.o

$(OBJDIR)destroyTable.o:$(SRCDIR)destroyTable.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)destroyTable.c -o $(OBJDIR)destroyTable.o

$(OBJDIR)insertData.o:$(SRCDIR)insertData.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)insertData.c -o $(OBJDIR)insertData.o

$(OBJDIR)removeData.o:$(SRCDIR)removeData.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)removeData.c -o $(OBJDIR)removeData.o

$(OBJDIR)lookupData.o:$(SRCDIR)lookupData.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)lookupData.c -o $(OBJDIR)lookupData.o

$(OBJDIR)functions.o:$(SRCDIR)functions.c include/HashTableAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)functions.c -o $(OBJDIR)functions.o
clean:
	rm $(BINDIR)main $(OBJDIR)main.o $(OBJDIR)createTable.o $(OBJDIR)createNode.o $(OBJDIR)destroyTable.o $(OBJDIR)insertData.o $(OBJDIR)removeData.o $(OBJDIR)lookupData.o $(OBJDIR)functions.o

doxygen:
	doxygen

cppcheck:
	cppcheck $(SRCDIR) ./include/HashTableAPI.h
