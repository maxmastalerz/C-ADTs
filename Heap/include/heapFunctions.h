//If you redefine the HEAP_TYPE stuff inside include guards then you won't get errors.

#ifndef _HEAPTYPES_
#define _HEAPTYPES_
#ifndef _HEAP_API_
#define MIN_HEAP 0
#define MAX_HEAP 1
#define HEAP_TYPE unsigned char
#endif
#endif

#include <stdio.h>
#include <stdlib.h>

struct node {
   void *data;
   struct node *left;
   struct node *right;
   struct node *parent;
};

typedef struct node Node;

struct heap {
    int heapSize;
    Node *heap; /* contains all of the heap nodes */
    HEAP_TYPE type; /* < flag for choosing between min and max heap*/
    Node *lastPosition; /* optional element useful for finding where to insert the next value */
    void (*destroyData)(void *data); /* < function pointer to a function to delete a single piece of data from the heap */
    void (*printNode)(void *toBePrinted); /* < function pointer to a function that prints out a data element of the heap */
    int (*compare)(const void *first, const void *second); /* < function pointer to a comparison function for the purpose of inserting and deleting elements */
};

typedef struct heap Heap;

//super cheezy cheat by putting the include statement AFTER the definitions of the struct.
//I promise to do this correctly next lab.   Please note this as an example of how
// modularity is good and having things coupled to each other is bad.  I'll explain
//in a news item.   This solves our immediate problem but I don't recommend it as a 
//solution in general.

#include "heap.h"

void destroyDataFP(void *data);
void printNodeFP(void *toBePrinted);
int compareFP(const void *first, const void *second);

void printHeap(Heap *h);
int insertToRowN(int numNodes);
Node* NthNode(Node* root, int n);
void fullHeapify(Heap *h);
void reheapify(Heap *h, Node *newNode);
void swapWithParent(Heap *h, Node *child);