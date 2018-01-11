/**
 * @file printBackwards.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that prints the list from tail to head
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Function to print list from tail to head. This will utilize the list's printData function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printBackwards(List *list) {
    if(list==NULL) {
        return;
    }
    Node *temp = list->tail;
    while(temp!=NULL) {
        list->printData(temp);
        temp = temp->previous;
    }
}