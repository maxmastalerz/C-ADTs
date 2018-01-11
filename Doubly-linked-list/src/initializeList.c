/**
 * @file initializeList.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that initializes a doubly linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

List *initializeList(void (*printFunction)(void*toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void* first, const void* second)) {
    List *newList = malloc(sizeof(List));

    newList->head = NULL;
    newList->tail = NULL;
    newList->printData = printFunction;
    newList->deleteData = deleteFunction;
    newList->compare = compareFunction;

    return newList;
}