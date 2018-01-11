/**
 * @file deleteDataFromList.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that deletes a node in the list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 
 *data structure. 
 *@pre List must exist and have memory allocated to it
 *@post toBeDeleted will have its memory freed if it exists in the list.
 *@param list pointer to the dummy head of the list containing deleteFunction function pointer
 *@param toBeDeleted pointer to data that is to be removed from the list
 *@return returns EXIT_SUCCESS on success, and EXIT_FAILURE when empty. Returns -1 when the node cannot be found.
 **/
int deleteDataFromList(List *list, void *toBeDeleted) {
    if(list==NULL || list->head==NULL || toBeDeleted==NULL) {
        return EXIT_FAILURE;
    }
 
    Node *temp = list->head;
    while(temp!=NULL) {
        if(temp->data == toBeDeleted) {
            if(temp==list->head) {
                list->head = temp->next;
                if(list->head!=NULL) {
                    list->head->previous = NULL;
                }
            } else if(temp==list->tail) {
                if(temp->previous != NULL) {
                    temp->previous->next = NULL;
                }
            } else {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
            }
            list->deleteData(temp);

            return EXIT_SUCCESS;
        }
        temp = temp->next;
    }

    return -1;
 }