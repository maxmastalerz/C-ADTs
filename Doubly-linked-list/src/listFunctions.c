/**
 * @file listFunctions.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A group of functions to print, delete, & compare data in the list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"
#include "../include/ListFunctions.h"

/** When called, this function will print out the data associated with a node
*@pre A valid node to be printed
*@post Data will be printed
*@param toBePrinted a pointer to data that is to be printed from the linked list
**/
void myPrintFunction(void *toBePrinted) {
    Node *printMe = (Node *)toBePrinted;
    int *numToPrint = (int*)printMe->data;
    printf("%d\n", *numToPrint);
}

/** When called, this function will delete the specified node from the list
*@pre A valid node to be deleted
*@post The node will be deleted
*@param toBeDeleted a pointer to the node that is to be deleted from the linked list
**/
void myDeleteFunction(void *toBeDeleted) {
    Node *deleteMe = (Node *)toBeDeleted;
    deleteMe->previous = NULL;
    deleteMe->next = NULL;
    deleteMe->data = NULL;
    free(deleteMe->data);
    free(deleteMe);

    toBeDeleted = NULL;
    free(toBeDeleted);
}

/** When called, this function will compare two void values as integers
*@pre valid void pointers that can be compared
*@post Data will be compared
*@param a a void pointer to be compared as an int against b
*@param b a void pointer to be compared as an int against a
**/
int myCompareFunction(const void *a, const void *b) {
    int *num1 = (int *)a;
    int *num2 = (int *)b;
    return *num2 - *num1;
}