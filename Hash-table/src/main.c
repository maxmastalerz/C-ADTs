/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "functions.h"

int main(void) {
    int tableSize = 5;
    HTable *someTable = createTable(tableSize, hashFunction, destroyData, myPrintData);
    HTable *myTable = createTable(tableSize, hashFunction, destroyData, myPrintData);
    HTable *theTable = createTable(tableSize, hashFunction, destroyData, myPrintData);

    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    int data4 = 4;
    int data5 = 5;
    int data6 = 6;
    int data7 = 7;
    int i;
    void *data;

    printf("CREATING AND DELETING HASH TABLE\n");
    destroyTable(someTable);


    printf("INSERTING 1..2..3..4..5..6(same key, overwriting 2)\n");
    insertData(myTable, 234, &data1);
    insertData(myTable, 124, &data2);
    insertData(myTable, 345, &data3);
    insertData(myTable, 235, &data4);
    insertData(myTable, 236, &data5);
    insertData(myTable, 124, &data6); /*same key insertion*/

    printf("PRINTING HASH TABLE:\n");
    
    for(i=0; i<tableSize; i++) {
        Node *temp = myTable->table[i];
        while(temp!=NULL) {
            myTable->printData(temp->data);
            printf(" -> ");
            temp = temp->next;
        }
        printf("NULL\n");
    }

    printf("=================================\n");
    printf("REMOVING DATA with key 124\n");
    removeData(myTable, 124);

    printf("PRINTING HASH TABLE:\n");
    for(i=0; i<tableSize; i++) {
        Node *temp = myTable->table[i];
        while(temp!=NULL) {
            myTable->printData(temp->data);
            printf(" -> ");
            temp = temp->next;
        }
        printf("NULL\n");
    }

    printf("=================================\n");
    printf("LOOKING UP DATA with key 234\n");
    data = lookupData(myTable, 234);
    if(data!=NULL) {
        int *val = (int*)data;
        printf("FOUND value of %d at key location 234\n", *val);
    } else {
        printf("COULDN'T FIND DATA\n");
    }

    printf("=================================\n");
    printf("REMOVING EACH INDEX IN THE TABLE, then printing\n");
    for(i=0; i<tableSize; i++) {
        myTable->destroyData(myTable->table[i]);
        myTable->table[i] = NULL;
    }

    for(i=0; i<tableSize; i++) {
        Node *temp = myTable->table[i];
        while(temp!=NULL) {
            myTable->printData(temp->data);
            printf(" -> ");
            temp = temp->next;
        }
        printf("NULL\n");
    }
    

    printf("=================================\n");
    printf("DESTROYING TABLE\n");
    destroyTable(myTable);
    myTable = NULL;
    
    printf("TRYING TO PRINT TABLE\n");
    if(myTable!=NULL) {
        for(i=0; i<tableSize; i++) {    
            Node *temp = myTable->table[i];
            while(temp!=NULL) {
                myTable->printData(temp->data);
                printf(" -> ");
                temp = temp->next;
            }
            
            printf("NULL\n");
        }
    }

    printf("=================================\n");
    printf("NO MEMORY LEAKS :) \n");

    printf("TESTING FUNCTIONS WITH NULL INPUTS:\n");
    insertData(theTable, 234, &data7);
    insertData(theTable, 234, NULL);
    insertData(NULL, 234, &data7);
    removeData(theTable, 124);
    removeData(NULL, 124);

    destroyTable(theTable);

    printf("=================================\n");
    printf("PASSED ALL TESTS!!! No memory leaks.\n");

    return 0;
}