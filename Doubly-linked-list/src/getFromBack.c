/**
 * @file getFromBack.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that gets the last Node's data
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Function to return the data at the back of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the tail of the list
 *@return pointer to the data located at the tail of the list
 **/
void *getFromBack(List *list) {
    if(list == NULL || list->head == list->tail) {
        return NULL;
    }

    Node *prev = list->head;
    Node *curr = list->head->next;

    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    return prev->data;
}