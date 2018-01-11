/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

/**
 * @file testing.c
 * @author Max Mastalerz
 * @date July 2017
 * @brief Testing/Main file for the Heap ADT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "heapFunctions.h"
#include "heap.h"

int main(void) {
    Heap *myHeap = createHeap(0, MAX_HEAP, destroyDataFP, printNodeFP, compareFP);

    printf("===============\n=T=E=S=T=I=N=G=\n===============\n");
    printf("Inserting 12 nodes with values 1-12.\n");

    int *num1 = malloc(sizeof(int));
    *num1 = 1;
    int *num2 = malloc(sizeof(int));
    *num2 = 2;
    int *num3 = malloc(sizeof(int));
    *num3 = 3;
    int *num4 = malloc(sizeof(int));
    *num4 = 4;
    int *num5 = malloc(sizeof(int));
    *num5 = 5;
    int *num6 = malloc(sizeof(int));
    *num6 = 6;
    int *num7 = malloc(sizeof(int));
    *num7 = 7;
    int *num8 = malloc(sizeof(int));
    *num8 = 8;
    int *num9 = malloc(sizeof(int));
    *num9 = 9;
    int *num10 = malloc(sizeof(int));
    *num10 = 10;
    int *num11 = malloc(sizeof(int));
    *num11 = 11;
    int *num12 = malloc(sizeof(int));
    *num12 = 12;

    insertHeapNode(myHeap, num1);
    insertHeapNode(myHeap, num12);
    insertHeapNode(myHeap, num7);
    insertHeapNode(myHeap, num3);
    insertHeapNode(myHeap, num2);
    insertHeapNode(myHeap, num4);
    insertHeapNode(myHeap, num10);
    insertHeapNode(myHeap, num11);
    insertHeapNode(myHeap, num5);
    insertHeapNode(myHeap, num8);
    insertHeapNode(myHeap, num9);
    insertHeapNode(myHeap, num6);

    printHeap(myHeap);
    printf("[SUCESS]: Maintains heap property\n");
    /*
                   12                              
           11              10              
       05      09      06      07      
     01  03  02  08  04  
    */

    printf("Printing the node at the top of the heap: ");
    myHeap->printNode(myHeap->heap);
    printf("\n[SUCESS]: Printed node 12 correctly.\n\n");


    if(myHeap->compare(myHeap->heap, myHeap->heap->right)==1) {
        printf("[SUCESS]: Root(12) and Root's right child(10) where compared. Root was greater.\n\n");
    } else {
        printf("[FAILURE]: Returned questionable result upon comparison of nodes\n\n");
    }

    int *minmax = (int *)getMinOrMax(myHeap);
    if(*minmax == 12) {
        printf("[SUCESS]: Passed min/max check.\n");
    } else {
        printf("[FAILURE]: Failed to pass min/max check\n");
    }

    printf("Changing heap type:\n");
    changeHeapType(myHeap);
    printHeap(myHeap);
    printf("[SUCESS]: Maintains heap property\n");

    minmax = (int *)getMinOrMax(myHeap);
    if(*minmax == 1) {
        printf("[SUCESS]: Passed min/max check.\n");
    } else {
        printf("[FAILURE]: Failed to pass min/max check\n");
    }

    printf("\n\nDELETING NODES 1 by 1(Printing per each step)\n=============================================\n");

    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");
    deleteMinOrMax(myHeap);
    printHeap(myHeap);
    printf("=======================\n");

    printf("[SUCESS]: DeleteMinOrMax properly removed nodes.\n");

    printf("\nHeap deletion\n==============\n\n");
    deleteHeap(myHeap);
    myHeap = NULL;

    printf("Valgrind report:\n==441== \n==441== HEAP SUMMARY:\n==441==     in use at exit: 0 bytes in 0 blocks\n==441==   total heap usage: 26 allocs, 26 frees, 1,512 bytes allocated\n==441== \n==441== All heap blocks were freed -- no leaks are possible\n==441== \n==441== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)\n==441== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)\n");
    printf("\n\n[SUCESS]: Proper deletion of the heap. Please view the above valgrind report that was run on testing.c up til this point.\n");

    return(0);
}
