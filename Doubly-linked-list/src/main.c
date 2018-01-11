/**
 * @file main.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A program that tests the doubly linked list API extensively
 */

#include <stdlib.h>
#include <stdio.h>
#include "../include/LinkedListAPI.h"
#include "../include/ListFunctions.h"

int main(void) {
    int num0 = 0;
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    printf("\n===================================\n");

    /*LIST CREATION*/
    printf("Initializing list");
    List *myList = initializeList(myPrintFunction, myDeleteFunction, myCompareFunction); /*Valgrind 40bytes*/
    printf("\n===================================\n");

    /*LIST DELETION*/
    printf("Deleting list");
    deleteList(myList);                                                                  /*Successful free*/
    printf("\n===================================\n");

    List *newList = initializeList(myPrintFunction, myDeleteFunction, myCompareFunction);

    /*NODE INITIALIZATION & TESTING*/
    Node * nodeNum0 = initializeNode(&num0);                                             /*Valgrind 24 bytes*/
    if(nodeNum0->previous==NULL) {
        printf("success: null node prev\n");
    }
    if(nodeNum0->previous==NULL) {
        printf("success: null node next\n");
    }
    int *nodeNum0Data = (int *)nodeNum0->data;
    if(*nodeNum0Data==0) {
    	printf("success: data is 0 for node 0\n");
    }
    free(nodeNum0);                                                                      /*Successful free*/
    printf("\n===================================\n");

    /*FRONT INSERTION & TESTING*/
    printf("Inserting front 1..2..3..\n");
    insertFront(newList, &num1);
    insertFront(newList, &num2);
    insertFront(newList, &num3);
    printf("Printing values from head to tail:\n");
    newList->printData(newList->head);
    newList->printData(newList->head->next);
    newList->printData(newList->head->next->next);
    printf("Printing values from tail to head:\n");
    newList->printData(newList->tail);
    newList->printData(newList->tail->previous);
    newList->printData(newList->tail->previous->previous);
    printf("===================================\n");

    /*DATA DELETION & TESTING*/
    printf("List after deleting 3:\n");
    deleteDataFromList(newList, &num3);
    printForward(newList);
    printf("List after deleting 1:\n");
    deleteDataFromList(newList, &num1);
    printForward(newList);
    printf("List after deleting 2:\n");
    deleteDataFromList(newList, &num2);
    printForward(newList);
    printf("===================================\n");


    /*BACK INSERTION & TESTING*/
    printf("Inserting back 1..2..3..\n");
    insertBack(newList, &num1);
    insertBack(newList, &num2);
    insertBack(newList, &num3);
    printf("Printing values from head to tail:\n");
    newList->printData(newList->head);
    newList->printData(newList->head->next);
    newList->printData(newList->head->next->next);
    printf("Printing values from tail to head:\n");
    newList->printData(newList->tail);
    newList->printData(newList->tail->previous);
    newList->printData(newList->tail->previous->previous);
    printf("===================================\n");

    /*GET FROM FRONT & TESTING*/
    int *frontResult = (int *)getFromFront(newList);
    int *headResult = (int *)newList->head->data;
    if(*frontResult==1 && *headResult==*frontResult) {
    	printf("get from front successfully returned a head of %d\n", *frontResult);
    }
    printf("===================================\n");

    /*GET FROM BACK & TESTING*/
    int *backResult = (int *)getFromBack(newList);
    int *tailResult = (int *)newList->tail->data;
    if(*backResult==3 && *tailResult==*backResult) {
    	printf("get from back successfully returned a tail of %d\n", *backResult);
    }
    printf("===================================\n");
    deleteList(newList);                                                                /*Successful free*/

    /*SORTED INSERTION & TESTING*/
    List *aList = initializeList(myPrintFunction, myDeleteFunction, myCompareFunction); /*Valgrind 40bytes*/
    printf("sorted insert of 1..2..3\n");
    insertSorted(aList, &num3);
    insertSorted(aList, &num1);
    insertSorted(aList, &num2);
    printf("Printing forwards: \n");
    printForward(aList);
    printf("Printing backwards: \n");
    printBackwards(aList);
    deleteList(aList);
    printf("===================================\n");
    printf("FINISHED TESTING\n");

    return 0;
}