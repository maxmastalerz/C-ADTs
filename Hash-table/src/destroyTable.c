/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

void destroyTable(HTable *hashTable) {
    if(hashTable!=NULL) {
        int tableSize = hashTable->size;

        int i;
        for(i=0; i<tableSize; i++) {
            if(hashTable->table[i]!=NULL) {
                Node *temp = hashTable->table[i];
                while(temp!=NULL) {
                    Node *delete = temp;
                    temp = temp->next;
                    free(delete);
                }
            }
        }
        free(hashTable->table);
        free(hashTable);
    }
}