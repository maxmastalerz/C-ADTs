CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

main:$(OBJDIR)main.o $(OBJDIR)initializeList.o $(OBJDIR)initializeNode.o $(OBJDIR)insertFront.o $(OBJDIR)insertBack.o $(OBJDIR)deleteList.o $(OBJDIR)insertSorted.o $(OBJDIR)deleteDataFromList.o $(OBJDIR)getFromFront.o $(OBJDIR)getFromBack.o $(OBJDIR)printForward.o $(OBJDIR)printBackwards.o $(OBJDIR)listFunctions.o
	mkdir -p $(BINDIR)
	$(CC) -o $(BINDIR)main $(OBJDIR)main.o $(OBJDIR)initializeList.o $(OBJDIR)initializeNode.o $(OBJDIR)insertFront.o $(OBJDIR)insertBack.o $(OBJDIR)deleteList.o $(OBJDIR)insertSorted.o $(OBJDIR)deleteDataFromList.o $(OBJDIR)getFromFront.o $(OBJDIR)getFromBack.o $(OBJDIR)printForward.o $(OBJDIR)printBackwards.o $(OBJDIR)listFunctions.o

$(OBJDIR)main.o:$(SRCDIR)main.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(OBJDIR)main.o

$(OBJDIR)initializeList.o:$(SRCDIR)initializeList.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)initializeList.c -o $(OBJDIR)initializeList.o

$(OBJDIR)initializeNode.o:$(SRCDIR)initializeNode.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)initializeNode.c -o $(OBJDIR)initializeNode.o

$(OBJDIR)insertFront.o:$(SRCDIR)insertFront.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)insertFront.c -o $(OBJDIR)insertFront.o

$(OBJDIR)insertBack.o:$(SRCDIR)insertBack.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)insertBack.c -o $(OBJDIR)insertBack.o

$(OBJDIR)deleteList.o:$(SRCDIR)deleteList.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)deleteList.c -o $(OBJDIR)deleteList.o

$(OBJDIR)insertSorted.o:$(SRCDIR)insertSorted.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)insertSorted.c -o $(OBJDIR)insertSorted.o

$(OBJDIR)deleteDataFromList.o:$(SRCDIR)deleteDataFromList.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)deleteDataFromList.c -o $(OBJDIR)deleteDataFromList.o

$(OBJDIR)getFromFront.o:$(SRCDIR)getFromFront.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)getFromFront.c -o $(OBJDIR)getFromFront.o

$(OBJDIR)getFromBack.o:$(SRCDIR)getFromBack.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)getFromBack.c -o $(OBJDIR)getFromBack.o

$(OBJDIR)printForward.o:$(SRCDIR)printForward.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)printForward.c -o $(OBJDIR)printForward.o

$(OBJDIR)printBackwards.o:$(SRCDIR)printBackwards.c include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)printBackwards.c -o $(OBJDIR)printBackwards.o

$(OBJDIR)listFunctions.o:$(SRCDIR)listFunctions.c include/ListFunctions.h include/LinkedListAPI.h
	$(CC) $(CFLAGS) -c $(SRCDIR)listFunctions.c -o $(OBJDIR)listFunctions.o

clean:
	rm $(BINDIR)main $(OBJDIR)main.o $(OBJDIR)initializeList.o $(OBJDIR)initializeNode.o $(OBJDIR)insertFront.o $(OBJDIR)insertBack.o $(OBJDIR)deleteList.o $(OBJDIR)insertSorted.o $(OBJDIR)deleteDataFromList.o $(OBJDIR)getFromFront.o $(OBJDIR)getFromBack.o $(OBJDIR)printForward.o $(OBJDIR)printBackwards.o $(OBJDIR)listFunctions.o
