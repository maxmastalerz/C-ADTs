/**
 * @file getFromFront.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that gets the data at the head of a list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Function to return the data at the front of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the head of the list
 *@return pointer to the data located at the head of the list
 **/
void *getFromFront(List *list) {
    if(list == NULL || list->head == list->tail) {
        return NULL;
    }
    return list->head->data;
}