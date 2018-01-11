/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

/**
 * @file heap.c
 * @author Max Mastalerz
 * @date July 2017
 * @brief File containing all ADT functions and helper functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heapFunctions.h"
#include "heap.h"

/**Function to allocate memory to the heap and point the heap to the appropriate functions. Allocates memory to the heap based on the size given.
 *@return pointer to the heap
 *@param initialSize initial size of the heap
 *@param htype flag to choose whether to start the heap as a min heap or max heap. Takes in values MIN_HEAP and MAX_HEAP
 *@param compareFP function pointer to a function that compares two pieces of data.
 *@param destroyDataFP function pointer to a function to delete a single piece of data from the heap
 *@param printNodeFP function pointer to a function that prints out a data element of the heap
 *@return pointer to the heap
 **/
Heap *createHeap(size_t initialSize, HEAP_TYPE htype, void (*destroyDataFP)(void *data), void (*printNodeFP)(void *toBePrinted), int (*compareFP)(const void *first, const void *second)) {
    Heap *newHeap = malloc(sizeof(Heap));

    newHeap->heapSize = 0;
    newHeap->type = htype;
    newHeap->lastPosition = NULL;
    newHeap->destroyData = destroyDataFP;
    newHeap->printNode = printNodeFP;
    newHeap->compare = compareFP;

    int i;
    for(i=0; i<initialSize; i++) {
        
        int *newNum = malloc(sizeof(int));
        *newNum = 0;
        insertHeapNode(newHeap, newNum);
    }

    return newHeap;
}

/**Function for creating a node for a heap.
 *@pre Node must be cast to void pointer before being added.
 *@post Node is valid and able to be added to a heap
 *@param data is a generic pointer to any data type that is to be stored in the heap.
 *@return returns a node for a heap
 **/
Node *createHeapNode(void *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->data = data;
    return newNode;
}

/**Inserts a Node into the heap. Uses createHeapNode to place the data in a Node structure, and then puts the newly
 *created Node in the heap by adding at the bottom and comparing it to each parent node until it fits the Heap structure.
 *If the heap is a min heap, if the Node is lesser than the parent, it is swapped. The opposite is true for a max heap.
 *@pre Heap must exist and have data allocated to it
 *@param heap Pointer to a heap
 *@param data Pointer to generic data that is to be inserted into the heap
**/
void insertHeapNode(Heap *h, void *data) {
    Node *toInsert = createHeapNode(data);

    if(h->lastPosition==NULL) { /*First time inserting*/
        h->heap = toInsert;
    } else { /*Every other time we need to find the lowest level, rightmost branch to insert to*/
        Node *parent = NthNode(h->heap, floor((h->heapSize+1)/2));
        toInsert->parent = parent;

        if(parent->left==NULL) {
            parent->left = toInsert;
        } else if(parent->right==NULL) {
            parent->right = toInsert;
        }
    }
    h->lastPosition = toInsert;
    h->heapSize++;
    reheapify(h, toInsert);
}

/**Function to remove the maximum or minimum Node of the heap (depending on min heap or max heap).
 *Once the Node has been deleted, the Node at the deepest point in the Heap is placed in the min/max position.
 *Finally, the heap is heapified to maintain heap property.
 *@pre Heap must exist and have memory allocated to it
 *@param heap Pointer to a heap.
 **/
void deleteMinOrMax(Heap *heap) {
    Node *temp = heap->heap;

    if(heap->heap == NULL) {
        return;
    }

    if(heap->heap == heap->lastPosition) {
        free(heap->heap->data);
        heap->heap->data = NULL;
        free(heap->heap);
        heap->heap = NULL;
        return;
    }

    if(heap->lastPosition->parent->right!=NULL) {
        heap->lastPosition->parent->right = NULL;
    } else if(heap->lastPosition->parent->left!=NULL) {
        heap->lastPosition->parent->left = NULL;
    }

    heap->lastPosition->parent = NULL;

    if(heap->heap->left!=heap->lastPosition) {
        heap->lastPosition->left = heap->heap->left;
    } else {
        heap->lastPosition->left = NULL;
    }

    if(heap->heap->right!=heap->lastPosition) {
        heap->lastPosition->right = heap->heap->right;
    } else {
        heap->lastPosition->right = NULL;
    }

    heap->heap = heap->lastPosition;
    if(heap->heap->right!=NULL) {
        heap->heap->right->parent = heap->lastPosition; 
    }
    if(heap->heap->left!=NULL) {
        heap->heap->left->parent = heap->lastPosition;  
    }
    heap->heapSize--;

    heap->lastPosition = NthNode(heap->heap, heap->heapSize);

    free(temp->data);
    free(temp);

    fullHeapify(heap);
}

/**Function to rearrange a heap to maintain heap property. Starting at the min/max, each Node is compared with its
 *two children to determine the smallest/largest of the three. If the parent is smaller/larger than the child,
 *it is swapped. Heapify is then recursively called on the child in order to continue heapifying until it reaches the bottom of the heap.
 *@param heap Pointer to a heap to be heapified
 **/
void *getMinOrMax(Heap *heap) {
    if(heap!=NULL) {
        fullHeapify(heap);
        return heap->heap->data;
    };
}

/**Function to switch the type of heap from min-to-max or max-to-min. This changes the htype flag from MIN_HEAP
 *to MAX_HEAP and vice versa. Once the flag has been changed, heapify is called on the heap to rearrange it to 
 *fit the new heap property.
 *@param heap Pointer to a heap to switch from min-to-max or max-to-min.
 **/
void changeHeapType(Heap *heap) {
    if(heap!=NULL) {
        if(heap->type == MIN_HEAP) {
            heap->type = MAX_HEAP;
        } else {
            heap->type = MIN_HEAP;
        }

        fullHeapify(heap);
    }
}

/**Function delete a heap. This function calls deleteMinOrMax the same amount of times as the size of the
 *heap, which heapifies after each deletion. Finally, it frees the Heap structure.
 *@param heap Pointer of a heap to be deleted.
 **/
void deleteHeap(Heap *heap) {
    if(heap!=NULL) {
        int size = heap->heapSize;

        int i;
        for(i=0; i < size; i++) {
            deleteMinOrMax(heap);
        }

        free(heap);
    }
}

/*
 *
 */
void destroyDataFP(void *data) {
    Node *del = (Node*)data;
    free(del->data);
}

/**Function that prints the data found at a node
 *@param toBePrinted the node to be printed
 **/
void printNodeFP(void *toBePrinted) {
    if(toBePrinted!=NULL) {
        Node *nodeToPrint = (Node*)toBePrinted;
        int *printMe = (int*)nodeToPrint->data;
        printf("%02d", *printMe);
    } else {
        printf("-");
    }
}

/**Function compares two data nodes. Used for rearranging the heap in goal of maintaining the heap property.
 *@param first first void pointer to be compared to the other
 *@param second second void pointer to be compared to the other
 **/
int compareFP(const void *first, const void *second) {
    Node *n1 = (Node*)first;
    Node *n2 = (Node*)second;

    int *d1 = (int*)n1->data;
    int *d2 = (int*)n2->data;
    if(*d1>*d2) {
        return 1;
    } else {
        return 0;
    }
}

/**Function that prints out a visual representation of the heap
 *@param heap Pointer to the heap that will be printed
 **/
void printHeap(Heap *h) {
    if(h->heap==NULL) {
        printf("Empty heap. Could not print.\n");
        return;
    }

    int i;
    int rows = insertToRowN(h->heapSize);
    int row = 1;
    int printedPadding = 0;


    for(i=0;i<h->heapSize;i++) {
        if(printedPadding==0) {

            int j;
            for(j=0;j<=(pow(2,(rows-(row-1)))-2);j++) {
                printf(" ");
            }
            printedPadding = 1;
        }

        Node *print = NthNode(h->heap, i+1);
        h->printNode(print);

        int j;
        for(j=0;j<=(pow(2,(rows-(row-1)))-2);j++) {
            printf("  ");
        }

        if(((i+2) & (i+1)) == 0) {
            printf("\n");
            row++;
            printedPadding = 0;
        }
    }
    printf("\n");
}

/**Given the amount of nodes in the heap, determines which row the next insertion shall occur
 *@param numNodes The number of nodes in the heap
 *@return Returns the row N to which the next insertion should occur
**/
int insertToRowN(int numNodes) {
    return ceil(log10(numNodes+1)/log10(2)); /*Row 0 is the root row*/
}

/**Returns the node found at the nth position in the heap
 *@pre Heap must exist and have data allocated to it
 *@pre nth element must be present in the heap
 *@param root Pointer to the root of the heap
 *@param n The nth element in the heap that is being searched for
**/
Node* NthNode(Node* root, int n) {
    int bitIndex = 0;
    while(1) { /* Get larger power of two that's less than n */
        if(1 << (bitIndex + 1) > n) {
            break;
        }
        bitIndex++;
    }

    /* Back off the bit index by one.  We're going to use this to find the
     * path down.
     */
    bitIndex--;

    /* Read off the directions to take from the bits of n. */
    for(; bitIndex >= 0; bitIndex--) {
        int mask = (1 << bitIndex);
        if(n & mask) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return root;
}

/**Swaps a child node with it's parent
 *@pre Valid heap
 *@pre Valid child node
 *@param h Heap pointer
 *@param child Pointer to a child node in the heap
**/
void swapWithParent(Heap *h, Node *child) {
    if(child->parent==NULL) {
        return;
    }

    void *temp = child->data;
    child->data = child->parent->data;
    child->parent->data = temp;
}

/**Goes through the heap and enforces the heap property
 *@pre Heap must exist and have data allocated to it
 *@param h Heap pointer
**/
void fullHeapify(Heap *h) {
    int i;
    int j;
    for(i=0; i < 2; i++) {
        for(j=0; j <= h->heapSize; j++) {
            Node *bottomNode = NthNode(h->heap, j);
            reheapify(h, bottomNode);
        }
    }
}

/**Goes up through the parents of a child node and continously swaps nodes to keep the heap property
 *@pre Valid heap
 *@pre Valid node
 *@param h Heap pointer
 *@param newNode pointer to the node to start at
**/
void reheapify(Heap *h, Node *newNode) {
    if(h!=NULL && newNode!=NULL) {
        Node *childNode = (Node*)newNode;
        int *childVal;
        int *parentVal = NULL;

        childVal = (int*)childNode->data;
        if(childNode->parent!=NULL) {
            parentVal = (int*)childNode->parent->data;
        }

        if(childNode->parent!=NULL) {
            if(h->type==MAX_HEAP) {         
                if(*childVal>=*parentVal) {
                    swapWithParent(h, childNode);
                    reheapify(h, childNode->parent);
                }
            } else if(h->type==MIN_HEAP) {
                if(*childVal<=*parentVal) {
                    swapWithParent(h, childNode);
                    reheapify(h, childNode->parent);
                }
            }
        }
    }
}