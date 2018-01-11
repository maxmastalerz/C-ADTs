/**
 * @file initializeNode.c
 * @author Max Mastalerz
 * @date May 2017
 * @brief A function that creates a node storing void data
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedListAPI.h"

/**Function for creating a node for a linked list. This node contains generic data and may be connected to 
other notes in a list.
*@pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
*data must be cast to void pointer before being added.
*@post data is valid to be added to a linked list
*@return On success returns a node that can be added to a linked list. On failure, returns NULL.
*@param data - is a generic pointer to any data type.
**/

Node *initializeNode(void *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}