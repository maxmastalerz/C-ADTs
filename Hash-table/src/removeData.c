/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

void removeData(HTable *hashTable, int key) {
    if(hashTable!=NULL) {
        int tableSize = hashTable->size;

        int index = hashTable->hashFunction(tableSize, key);
        if(hashTable->table[index]!=NULL) {
            Node *myNode = hashTable->table[index];
            Node *prev = NULL;
            Node *head = hashTable->table[index];

            while(myNode->key !=key) {
                prev = myNode;
                myNode = myNode->next;
            }

            if(myNode->key==key) {
                if(prev==NULL) {
                    hashTable->table[index] = head->next;
                    free(myNode);
                    if(hashTable->table[index]==NULL) {
                        hashTable->destroyData(hashTable->table[index]);
                        hashTable->table[index] = NULL;
                    }
                } else {
                    prev->next = myNode->next;
                    free(myNode);
                }
            }
        }
    }
}