/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

/**
 * @file testing.c
 * @author Max Mastalerz
 * @date July 2017
 * @brief Testing/Main file for the BBST ADT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "balancedTreeAPI.h"
#include "tree.h"


int main(void) {
    int successCount = 0;
    int failCount = 0;

    /*===================================================================================
     *  Initialization of nodes to be used in testing. Checking for successful creation
     *===================================================================================*/

    int num5 = 5;
    int num10 = 10;
    int num15 = 15;
    int num20 = 20;
    int num25 = 25;
    int num30 = 30;
    int num35 = 35;
    int num40 = 40;
    int num45 = 45;
    int num50 = 50;
    int num55 = 55;
    int num60 = 60;
    int num65 = 65;
    int num70 = 70;
    int num75 = 75;
    int num80 = 80;
    int num85 = 85;
    int num90 = 90;
    int num95 = 95;

    TreeNode *nodeNULL = createBalancedBinNode(NULL);

    TreeNode *node5  = createBalancedBinNode(&num5);
    TreeNode *node10 = createBalancedBinNode(&num10);
    TreeNode *node15 = createBalancedBinNode(&num15);
    TreeNode *node20 = createBalancedBinNode(&num20);
    TreeNode *node25 = createBalancedBinNode(&num25);
    TreeNode *node30 = createBalancedBinNode(&num30);
    TreeNode *node35 = createBalancedBinNode(&num35);
    TreeNode *node40 = createBalancedBinNode(&num40);
    TreeNode *node45 = createBalancedBinNode(&num45);
    TreeNode *node50 = createBalancedBinNode(&num50);
    TreeNode *node55 = createBalancedBinNode(&num55);
    TreeNode *node60 = createBalancedBinNode(&num60);
    TreeNode *node65 = createBalancedBinNode(&num65);
    TreeNode *node70 = createBalancedBinNode(&num70);
    TreeNode *node75 = createBalancedBinNode(&num75);
    TreeNode *node80 = createBalancedBinNode(&num80);
    TreeNode *node85 = createBalancedBinNode(&num85);
    TreeNode *node90 = createBalancedBinNode(&num90);
    TreeNode *node95 = createBalancedBinNode(&num95);

    if(nodeNULL==NULL) {
        printf("[SUCESS]: createBalancedBinNode declined creation with null input\n");
        successCount++;
    } else {
        printf("[FAIL]: A node was created with null input\n");
        failCount++;
    }

    if(node5!=NULL && *((int*)(TreeNode*)node5->data)==5) {
        printf("[SUCESS]: createBalancedBinNode successfully created a node with a size of %lu bytes\n", sizeof(*node5));
        successCount++;
    } else {
        printf("[FAIL]: createBalancedBinNode failed.\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing tree creation with nulled function pointers. All tree creation should fail
     *===================================================================================*/
    Tree *exTree1 = createBalancedBinTree(NULL, &destroyFunction, &copyFunction);
    Tree *exTree2 = createBalancedBinTree(&compareFunction, NULL, &copyFunction);
    Tree *exTree3 = createBalancedBinTree(&compareFunction, &destroyFunction, NULL);
    Tree *exTree4 = createBalancedBinTree(NULL, NULL, &copyFunction);
    Tree *exTree5 = createBalancedBinTree(&compareFunction, NULL, NULL);
    Tree *exTree6 = createBalancedBinTree(NULL, NULL, NULL);

    if(exTree1==NULL && exTree2==NULL && exTree3==NULL && exTree4==NULL && exTree5==NULL && exTree6==NULL) {
        printf("[SUCESS]: Trees denied being created with null function pointers\n");
        successCount++;
    } else {
        printf("[FAIL]: Trees were created with null function pointers\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing proper tree creation(With compare, destroy, & copy function pointers)
     *===================================================================================*/
    Tree *myTree = createBalancedBinTree(&compareFunction, &destroyFunction, &copyFunction);
    if(myTree!=NULL) {
        printf("[SUCESS]: Tree successfully created with a size of %lu bytes\n", sizeof(*myTree));
        successCount++;
    } else {
        printf("[FAIL]: Trees was not created\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing treeIsEmpty function with empty trees.
     *===================================================================================*/
    int isEmpty = treeIsEmpty(NULL);
    if(isEmpty) {
        printf("[SUCESS]: treeIsEmpty returned proper value\n");
        successCount++;
    } else {
        printf("[FAIL]: treeIsEmpty failed\n");
        failCount++;
    }

    isEmpty = treeIsEmpty(myTree);

    if(isEmpty) {
        printf("[SUCESS]: treeIsEmpty returned proper value\n");
        successCount++;
    } else {
        printf("[FAIL]: treeIsEmpty failed\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing treeInsertNode && treeIsEmpty(with inserts)
     *===================================================================================*/
    treeInsertNode(NULL, NULL);
    treeInsertNode(myTree, NULL);
    treeInsertNode(NULL, node5);

    isEmpty = treeIsEmpty(myTree);
    if(isEmpty) {
        printf("[SUCESS]: treeInsertNode did not pass anything into the tree\n");
        successCount++;
    } else {
        printf("[FAIL]: treeInsertNode inserted into the tree\n");
        failCount++;
    }

    treeInsertNode(myTree, node30);
    treeInsertNode(myTree, node45);
    treeInsertNode(myTree, node15);
    treeInsertNode(myTree, node95);
    treeInsertNode(myTree, node5);
    treeInsertNode(myTree, node85);
    treeInsertNode(myTree, node10);
    treeInsertNode(myTree, node90);
    treeInsertNode(myTree, node20);
    treeInsertNode(myTree, node25);
    treeInsertNode(myTree, node35);
    treeInsertNode(myTree, node40);
    treeInsertNode(myTree, node55);
    treeInsertNode(myTree, node60);
    treeInsertNode(myTree, node65);
    treeInsertNode(myTree, node50);
    treeInsertNode(myTree, node70);
    treeInsertNode(myTree, node75);
    treeInsertNode(myTree, node80);

    /*===================================================================================
     *  Testing treeInOrderPrint & treePreOrderPrint & treePostOrderPrint
     *===================================================================================*/

    printf("Printing tree:\n");
    printTree(myTree); /*My custom print function*/

    printf("In order print:   ");
    treeInOrderPrint(NULL, NULL);
    treeInOrderPrint(NULL, &printFunction);
    treeInOrderPrint(myTree, NULL);
    treeInOrderPrint(myTree, &printFunction);

    printf("Pre order print:  ");
    treePreOrderPrint(NULL, NULL);
    treePreOrderPrint(NULL, &printFunction);
    treePreOrderPrint(myTree, NULL);
    treePreOrderPrint(myTree, &printFunction);

    printf("Post order print: ");
    treePostOrderPrint(NULL, NULL);
    treePostOrderPrint(NULL, &printFunction);
    treePostOrderPrint(myTree, NULL);
    treePostOrderPrint(myTree, &printFunction);

    printf("[SUCESS]: Tree was printed properly in all cases\n");
    successCount+=3;

    /*===================================================================================
     *  Testing node deletion
     *===================================================================================*/
    treeDeleteNode(NULL, NULL);
    treeDeleteNode(NULL, node55);
    treeDeleteNode(myTree, NULL);

    successCount++;

    printf("[SUCESS]: Tree was not altered after improper calls to treeDeleteNode\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    
    treeDeleteNode(myTree, node55); /*Deletion from root*/
    node55 = NULL;
    printf("[SUCESS]: Successful deletion from root. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node30); /*Deletion from left branch*/
    node30 = NULL;
    printf("[SUCESS]: Successful deletion from left branch. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node85); /*Deletion from right branch*/
    node85 = NULL;
    printf("[SUCESS]: Successful deletion from right branch. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node85); /*Trying to delete 85 again*/
    node85 = NULL;
    printf("[SUCESS]: Properly handled the deletion of a not found node. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node25); /*Deleting a leaf node*/
    node25 = NULL;
    printf("[SUCESS]: Deleted a leaf node. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node65); /*Deleting a that only has a right child*/
    node65 = NULL;
    printf("[SUCESS]: Deleted a node with one right child. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    treeDeleteNode(myTree, node20); /*Deleting a that only has a left child*/
    node20 = NULL;
    printf("[SUCESS]: Deleted a node with one left child. See Below:\n");
    printf("In order print:   ");
    treeInOrderPrint(myTree, &printFunction);

    successCount+=8;

    /*===================================================================================
     *  Testing treeHasTwoChildren function
     *===================================================================================*/
    int hasTwoChildren = treeHasTwoChildren(NULL);
    if(hasTwoChildren==0) {
        printf("[SUCESS]: treeHasTwoChildren correctly returned negative when given NULL value\n");
        successCount++;
    } else {
        printf("[FAIL]: treeHasTwoChildren did not work correctly.\n");
        failCount++;
    }

    hasTwoChildren = treeHasTwoChildren(myTree->root);
    if(hasTwoChildren==1) {
        printf("[SUCESS]: treeHasTwoChildren correctly returned positive\n");
        successCount++;
    } else {
        printf("[FAIL]: treeHasTwoChildren did not work correctly.\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing treeFindNode
     *===================================================================================*/
    TreeNode *found1 = treeFindNode(NULL, NULL);
    TreeNode *found2 = treeFindNode(NULL, (int*)55);
    TreeNode *found3 = treeFindNode(myTree, NULL);

    if(found1==NULL && found2==NULL && found3==NULL) {
        printf("[SUCESS]: treeFindNode correctly returned no match when given NULL values\n");
        successCount++;
    } else {
        printf("[FAIL]: treeFindNode did not work as planned\n");
        failCount++;
    }

    TreeNode *found = treeFindNode(myTree, (int*)55);
    if(found==NULL) {
        printf("[SUCESS]: treeFindNode correctly returned no match\n");
        successCount++;
    } else {
        printf("[FAIL]: treeFindNode did not work as planned\n");
        failCount++;
    }

    found = treeFindNode(myTree, (int*)90);
    if(found!=NULL && *(int*)found->data==90) {
        printf("[SUCESS]: treeFindNode correctly found a match for the number %d\n", *(int*)found->data);
        successCount++;
    } else {
        printf("[FAIL]: treeFindNode did not work as planned\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing treeFindMin
     *===================================================================================*/

    int *smallest = treeFindMin(NULL);
    if(smallest==NULL) {
        printf("[SUCESS]: treeFindMin correctly was unable to find a smallest value\n");
        successCount++;
    } else {
        printf("[FAIL]: treeFindMin did not work as planned\n");
        failCount++;
    }

    smallest = treeFindMin(myTree);
    if(smallest!=NULL && *smallest == 5) {
        printf("[SUCESS]: treeFindMin correctly was able to find a smallest value (%d)\n", *smallest);
        successCount++;
    } else {
        printf("[FAIL]: treeFindMin did not work as planned\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing treeFindMax (Pretty much the same as treeFindMin)
     *===================================================================================*/

    int *largest = treeFindMax(NULL);
    if(largest==NULL) {
        printf("[SUCESS]: treeFindMax correctly was unable to find a largest value\n");
        successCount++;
    } else {
        printf("[FAIL]: treeFindMax did not work as planned\n");
        failCount++;
    }

    largest = treeFindMax(myTree);
    if(largest!=NULL && *largest == 95) {
        printf("[SUCESS]: treeFindMax correctly was able to find a largest value (%d)\n", *largest);
        successCount++;
    } else {
        printf("[FAIL]: treeFindMax did not work as planned\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing tree->compare function
     *===================================================================================*/
    int compareNullCase1 = myTree->compareFP(NULL, NULL);
    int compareNullCase2 = myTree->compareFP(NULL, node50);
    int compareNullCase3 = myTree->compareFP(node40, NULL);

    if(compareNullCase1==0 && compareNullCase2==0 && compareNullCase3==0) {
        printf("[SUCESS]: comparison returned 0 when null was passed in\n");
        successCount++;
    } else {
        printf("[FAIL]: comparison failure.\n");
        failCount++;
    }

    int comparisonResult = myTree->compareFP(node40, node50);
    if(comparisonResult==-1) {
        printf("[SUCESS]: comparison proved that node40 < node50\n");
        successCount++;
    } else if(comparisonResult==1) {
        printf("[FAIL]: comparison failure.\n");
        failCount++;
    }

    comparisonResult = myTree->compareFP(node50, node40);
    if(comparisonResult==1) {
        printf("[SUCESS]: comparison proved that node50 > node40\n");
        successCount++;
    } else if(comparisonResult==-1) {
        printf("[FAIL]: comparison failure.\n");
        failCount++;
    }

    /*===================================================================================
     *  Testing tree->destroy function
     *===================================================================================*/
    myTree->destroyFP(NULL);
    int *test = malloc(sizeof(int));
    myTree->destroyFP(test);

    printf("[SUCESS]: myTree->destroy freed data\n");
    successCount++;

    /*===================================================================================
     *  Testing tree copy function
     *===================================================================================*/

    TreeNode *nullCopy = myTree->copyFP(NULL);
    if(nullCopy==NULL) {
        printf("[SUCESS]: Copy correctly not attempted\n");
        successCount++;
    } else {
        printf("[FAIL]: CopyFP did not work as planned\n");
        failCount++;
    }

    TreeNode *aCopy = myTree->copyFP(node70);
    if(myTree->compareFP(aCopy, node70)==-1) {
        printf("[SUCESS]: Successfully copied node\n");
        successCount++;
    } else {
        printf("[FAIL]: Copy failed\n");
        failCount++;
    }
    free(aCopy);


    /*===================================================================================
     *  Testing tree deletion (This also tests node deletion due to calls)
     *===================================================================================*/
    destroyBalancedBinTree(NULL);
    destroyBalancedBinTree(myTree);
    free(myTree);
    myTree = NULL;

    if(myTree==NULL) {
        printf("[SUCESS]: destroyBalancedBinTree deleted the tree successfully\n");
        successCount++;
    } else {
        printf("[FAIL]: destroyBalancedBinTree failed\n");
        failCount++;
    }

    printf("====================\nVALGRIND REPORT\n");
    printf("==15737==\n==15737== HEAP SUMMARY:\n==15737==     in use at exit: 0 bytes in 0 blocks\n==15737==   total heap usage: 23 allocs, 23 frees, 1,736 bytes allocated\n==15737== \n==15737== All heap blocks were freed -- no leaks are possible\n==15737== \n==15737== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)\n==15737== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)\n");
    printf("====================\nFINISHED\nTests passed: %d\nTests failed: %d\n====================\n", successCount, failCount);

    return 0;
}
