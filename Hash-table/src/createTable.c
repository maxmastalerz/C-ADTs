/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printData)(void *toBePrinted)) {
    if(size==0) {
        return NULL;
    }

    HTable *myTable = malloc(sizeof(HTable));
    myTable->size = size;
    myTable->table = malloc(sizeof(Node*)*size);

    int i;
    for(i=0; i<size; i++) {
        myTable->table[i] = NULL;
    }

    myTable->hashFunction = hashFunction;
    myTable->destroyData = destroyData;
    myTable->printData = printData;

    return myTable;
}