/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

void *lookupData(HTable *hashTable, int key) {
    if(hashTable!=NULL) {
        int tableSize = hashTable->size;
        int index = hashTable->hashFunction(tableSize, key);

        if(hashTable->table[index]==NULL) {
            return NULL;
        }
        
        Node *tmpNode = hashTable->table[index];
        while(tmpNode!=NULL) {

            if(tmpNode->key==key) {
                return tmpNode->data;
            }
            tmpNode = tmpNode->next;
        }
    }

    return NULL;
}
