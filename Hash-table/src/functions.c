/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

int hashFunction(size_t tableSize, int key) {
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;
    
    return key % tableSize;
}

void destroyData(void *data) {
    if(data==NULL) {
        return;
    }

    Node *temp = (Node*)data;
    while(temp!=NULL) {
        Node *freeMe = temp;
        temp = temp->next;
        free(freeMe);
    }
}

void myPrintData(void *toBePrinted) {
    int *print = (int*)toBePrinted;
    printf("%d", *print);
}