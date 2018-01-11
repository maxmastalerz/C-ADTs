/**
 * @file deleteList.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that deletes the list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the List-type dummy node
**/
void deleteList(List *list) {
    if(list==NULL) {
        return;
    }
    
    if(list==NULL) {
        return;
    }

    while(list->head != NULL) {
        Node *temp = list->head;
        list->head = list->head->next;
        list->deleteData(temp);
    }

    free(list);

    return;
}