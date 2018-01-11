/**
 * @file insertBack.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that inserts a node at the tail of a list
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the dummy head of the list
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertBack(List *list, void *toBeAdded) {
    if(list==NULL) {
        return;
    }

    Node *newNode = initializeNode(toBeAdded);

    if(list->head == NULL) {
        list->head = newNode;

        Node *iter = list->head;
        while(iter!=NULL) {
            list->tail = iter;
            iter = iter->next;
        }

        return;
    }

    Node *temp = list->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->previous = temp;

    /*update tail*/
    Node *iter = list->head;
    while(iter!=NULL) {
        list->tail = iter;
        iter = iter->next;
    }
    /*end update*/
}