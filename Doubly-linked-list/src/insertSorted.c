/**
 * @file insertSorted.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that inserts a node in it's sorted position. Function must be used from start
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/** Uses the comparison function in the List struct to place the element in the appropriate position in the list.
*this is intended to be used from the beginning in order to keep the list completely sorted.
*@pre List exists and has memory allocated to it. Node to be added is valid.
*@post The node to be added will be placed immediately before or after the first occurrence of a related node
*@param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well 
as a pointer to the first and last element of the list.
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertSorted(List *list, void *toBeAdded) {
    if(list==NULL) {
        return;
    }

    Node* insertNode = initializeNode(toBeAdded);
    Node *temp = list->head;

    if(list->head==NULL) {    /*If empty initialized list*/
        insertBack(list, toBeAdded);
        return;
    }

    while(temp!=NULL) { /*Loop through list*/
        int *val1 = (int *)toBeAdded;
        int *val2 = (int *)temp->data;
        int *val3;
        if(temp->next!=NULL) { /*Protection from potential seg fault*/
            val3 = (int *)temp->next->data;
        } else {
            val3 = (int *)temp->data;
        }

        if((*val1-*val2)>=0 && (*val1-*val3)<0) { /*Find key location where to insert*/
            insertNode->previous = temp;
            insertNode->next = temp->next;
            temp->next->previous = insertNode;
            temp->next = insertNode;

            Node *iter = list->head;
            while(iter!=NULL) {
                list->tail = iter;
                iter = iter->next;
            }
            
            return;
        }
        if(temp==list->tail) { /*If key location isn't found, insert at either the head or tail*/
            int *val1 = (int *)list->tail->data;
            int *val2 = (int *)toBeAdded;
            if((*val2-*val1)>=0) {
                insertBack(list, toBeAdded);
            } else {
                insertFront(list, toBeAdded);
            }

            return;
        }

        temp = temp->next; /*Move the while loop along*/
    }
}