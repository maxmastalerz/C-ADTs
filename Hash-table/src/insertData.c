/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

void insertData(HTable *hashTable, int key, void *data) {
    if(hashTable==NULL || data==NULL) {
        return;
    }
    int tableSize = hashTable->size;

    if(hashTable!=NULL) {
        Node *insertMe = createNode(key, data);
        int index = hashTable->hashFunction(tableSize, key);

        if(hashTable->table[index] != NULL) {
            if(hashTable->table[index]->key == key) {
                insertMe->next = hashTable->table[index]->next;
                Node *temp = hashTable->table[index];
                hashTable->table[index] = insertMe;
                free(temp);
            } else {
                Node *temp = hashTable->table[index];
                while(temp->next != NULL) {
                    temp = temp->next;
                }

                temp->next = insertMe;
            }
        } else {
            hashTable->table[index] = insertMe;
        }
    }
}