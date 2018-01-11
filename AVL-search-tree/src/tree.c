/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

/**
 * @file tree.c
 * @author Max Mastalerz
 * @date July 2017
 * @brief Main API function code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "balancedTreeAPI.h"
#include "tree.h"

/**Function to compare two nodes
 *@param data1 a void pointer to the first element being compared
 *@param data2 a void pointer to the second element being compared
 *@return Returns an integer -1, 0, or 1 depending on comparison results
 **/
int compareFunction(void *data1, void *data2) {
    if(data1==NULL || data2==NULL) {
        return 0;
    }

    int *one = (int*)((TreeNode*)data1)->data;
    int *two = (int*)((TreeNode*)data2)->data;
    
    if(*one > *two) {
        return 1;
    }
    if(*one <= *two) {
        return -1;
    } else {
        return 0;
    }
}

/**Function to free content
 *@param toBeDeleted A void pointer to the content being deleted
 **/
void destroyFunction(void *toBeDeleted) {
    free(toBeDeleted);
    return;
}

/**Function to duplicate a node
 *@param toBeCopy a void pointer to the content being duplicated
 *@return Returns the duplicate
 **/
void *copyFunction(void *toBeCopy) {
    if(toBeCopy==NULL) {
        return NULL;
    }

    TreeNode *toBeCopyNode = (TreeNode*)toBeCopy;
    TreeNode *copy = createBalancedBinNode(toBeCopyNode->data);
    return copy;
}

/**Function to print a node
 *@param toBePrinted the node being printed
 **/
void printFunction(void *toBePrinted) {
    TreeNode *printNode = (TreeNode*)toBePrinted;
    int *printNodeVal = (int*)printNode->data;
    printf("%d", *printNodeVal);
}

/**This function returns a pointer to a binary tree.  You must send pointers to the compare and destroy functions when you create the tree.
 *@param compareFP function pointer to allow for comparison between two generic data types
 *@param destroyFP function pointer to allow for pointer deletion. 
 *@param copyFP function pointer to a function that copies pointer data to a new pointer.
 *@return If successful, returns a pointer to a binary tree. Returns null if the memory allocation fails.
 **/
Tree *createBalancedBinTree(int (*compareFP) (void *data1, void *data2), void (*destroyFP) (void *toBeDeleted),void *(*copyFP)(void *toBeCopy)) {
    if(compareFP==NULL || destroyFP==NULL || copyFP==NULL) {
        return NULL;
    }

    Tree *newBalancedBinTree = malloc(sizeof(Tree));

    if(newBalancedBinTree==NULL) { /*Upon malloc failure, return NULL*/
        return NULL;
    }


    newBalancedBinTree->height = 0;
    newBalancedBinTree->numElements = 0;
    newBalancedBinTree->root = NULL;
    newBalancedBinTree->compareFP = compareFP;
    newBalancedBinTree->destroyFP = destroyFP;
    newBalancedBinTree->copyFP = copyFP;

    return newBalancedBinTree;
}

/**This function creates a tree node for a self-balancing binary tree.
 *@param data pointer to data that is to be added to a self-balancing binary tree.
 **/
TreeNode *createBalancedBinNode(void *data) {
    if(data==NULL) {
        return NULL;
    }

    TreeNode *newNode = malloc(sizeof(TreeNode));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

/**This function destroys a binary tree and all data that is in the tree
 *when destroy is called.
 *@param toBeDeleted pointer to binary tree created via createBalancedBinTree
 **/
void destroyBalancedBinTree(Tree *toBeDeleted) {
    if(toBeDeleted==NULL) {
        return;
    } else {
        if(toBeDeleted->root==NULL) {
            return;
        }

        TreeNode *top;
        int i;
        int numElements = toBeDeleted->numElements;
        for(i=0; i<numElements;i++) {
            top = (TreeNode*)toBeDeleted->root;
            treeDeleteNode(toBeDeleted, top);
        }
    }

    return;
}

/**Function to insert a node into a self-balancing binary tree.
 *@param theTree pointer to a self-balancing binary tree
 *@param toBeInserted pointer to generic data that is to be inserted into the self-balancing binary tree
 **/
void treeInsertNode(Tree *theTree, void *toBeInserted) {
    if(theTree==NULL || toBeInserted==NULL) {
        return;
    }

    TreeNode *nodeToInsert = (TreeNode*)toBeInserted;
    int *toInsertVal = (int*)nodeToInsert->data;
    TreeNode *insertAfter = theTree->root;

    if(theTree->numElements==0) {
        nodeToInsert->height = 0;
        theTree->root = nodeToInsert;
    } else {
        int *insertAfterVal = (int*)insertAfter->data;

        while(1) {
            if(*toInsertVal > *insertAfterVal) { /*move to right branch*/
                if(insertAfter->right!=NULL) {
                    insertAfter = insertAfter->right;
                }
            } else if(*toInsertVal < *insertAfterVal) { /*move to left branch*/
                if(insertAfter->left!=NULL) {
                    insertAfter = insertAfter->left;
                }
            }

            insertAfterVal = (int*)insertAfter->data;

            if(insertAfter->right==NULL && *toInsertVal > *insertAfterVal) {
                nodeToInsert->height = insertAfter->height+1;

                insertAfter->right = nodeToInsert;
                break;
            } else if(insertAfter->left==NULL && *toInsertVal < *insertAfterVal) {
                nodeToInsert->height = insertAfter->height+1;

                insertAfter->left = nodeToInsert;
                break;
            }
        }
        theTree->height = depth(theTree->root);
    }

    theTree->numElements++;

    balanceTree(theTree);

    return;
}

/**Function to balance out the tree if the balance factor is off
 *@param tree The tree to be balanced
 **/
void balanceTree(Tree *theTree) {
    TreeNode *root = balanceNode(theTree->root);

    if(root!=theTree->root) {
        theTree->root = root;
    }
}

/**Function to balance out the children of a node
 *@param node pointer to the node that is being used as the starting point for the balancing of children nodes
 **/
TreeNode *balanceNode(TreeNode *node) {
    if(node!=NULL) {
        TreeNode *root = NULL;

        if(node->right!=NULL) {
            node->right = balanceNode(node->right);
        }
        if(node->left!=NULL) {
            node->left  = balanceNode(node->left);
        }

        int balanceFactor = balanceFactorOfNode(node);

        if(balanceFactor < -1) {
            if(balanceFactorOfNode(node->right) < 1) {
                root = rightRotate(node);
            } else {
                root = rightLeftRotate(node);
            }
        } else if(balanceFactor > 1) {
            if(balanceFactorOfNode(node->left) > -1) {
                root = leftRotate(node);
            } else {
                root = leftRightRotate(node);
            }
        } else {
            return node;
        }

        return root;
    } else {
        return node;
    }
}

/**Function to determine the height of a node in a BST
 *@param node The node to be checked
 *@return Returns the height of the node
 **/
int nodeHeight(TreeNode *node) {
    int leftHeight = 0;
    int rightHeight = 0;

    if(node->left!=NULL) {
        leftHeight = nodeHeight(node->left);
    }
    if(node->right!=NULL) {
        rightHeight = nodeHeight(node->right);
    }

    if(rightHeight > leftHeight) {
        rightHeight++;
        return rightHeight;
    } else {
        leftHeight++;
        return leftHeight;
    }
}

/**Function to calculate the balance factor of a node
 *@param node The node to be checked
 *@return Returns the balance factor of the node
 **/
int balanceFactorOfNode(TreeNode *node) {
    int balanceFactor = 0;

    if(node->left!=NULL) {
        balanceFactor += nodeHeight(node->left);
    }
    if(node->right!=NULL) {
        balanceFactor -= nodeHeight(node->right);
    }

    return balanceFactor;
}

/**Function that performs a left rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *leftRotate(TreeNode *node) {
    TreeNode *tmp = node->left;
    node->left = node->left->right;
    tmp->right = node;

    return tmp;
}

/**Function that performs a right rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *rightRotate(TreeNode *node) {
    TreeNode *tmp = node->right;
    node->right = node->right->left;
    tmp->left = node;

    return tmp;
}

/**Function that performs a left-right rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *leftRightRotate(TreeNode *node) {
    TreeNode *tmp1 = node->left;
    TreeNode *tmp2 = node->left->right;
    
    node->left = tmp2->right;
    tmp1->right = tmp2->left; 
    tmp2->left = tmp1;
    tmp2->right = node;

    return tmp2;
}

/**Function that performs a right-left rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *rightLeftRotate(TreeNode *node) {
    TreeNode *tmp1 = node->right;
    TreeNode *tmp2 = node->right->left;
    
    node->right = tmp2->left;
    tmp1->left = tmp2->right;
    tmp2->right = tmp1;
    tmp2->left = node;

    return tmp2;
}


/**Function to delete a node from a self-balancing binary tree.
 *@param theTree pointer to a self-balancing binary tree
 *@param toBeDeleted pointer to generic data that is to be deleted from the self-balancing binary tree
 **/
void treeDeleteNode(Tree *theTree, void *toBeDeleted) {
    if(theTree==NULL || toBeDeleted==NULL) {
        return;
    }

    TreeNode *nodeToDelete = (TreeNode*)toBeDeleted;

    int *valToDelete = (int*)nodeToDelete->data;
    TreeNode *parent = getParent(theTree, toBeDeleted);
    
    int *parentLeftVal = NULL;
    int *parentRightVal = NULL;
    int deleted = 0;

    if(parent!=NULL) {
        if(parent->left!=NULL) {
            parentLeftVal = (int*)((TreeNode*)parent->left)->data;
        }
        if(parent->right!=NULL && deleted==0) {
            parentRightVal = (int*)((TreeNode*)parent->right)->data;
        }
    }

    if(nodeToDelete->left == NULL && nodeToDelete->right == NULL) { /*Deletion of leaf nodes*/
        if(parent!=NULL) {
            if(parentLeftVal!=NULL) {
                if(*parentLeftVal == *valToDelete) {
                    parent->left = NULL;
                    deleted = 1;
                }
            }
            if(parentRightVal!=NULL && deleted==0) {
                if(*parentRightVal == *valToDelete) {
                    parent->right = NULL;
                }
            }

        } else {
            theTree->root = NULL;
        }
    } else if(nodeToDelete->left!=NULL && nodeToDelete->right==NULL) { /*Only has left child*/        
        if(parent==NULL) {
            theTree->root = theTree->root->left;
        } else {
            if(parentLeftVal!=NULL) {
                if(*parentLeftVal == *valToDelete) {
                    parent->left = nodeToDelete->left;
                    deleted = 1;
                }
            }
            if(parentRightVal!=NULL && deleted==0) {
                if(*parentRightVal == *valToDelete) {
                    parent->right = nodeToDelete->left;
                }
            }
        }
    } else if(nodeToDelete->right!=NULL && nodeToDelete->left==NULL) { /*Only has right child*/
        if(parent==NULL) {
            theTree->root = theTree->root->right;
        } else {    
            if(parentLeftVal!=NULL) {
                if(*parentLeftVal == *valToDelete) {
                    parent->left = nodeToDelete->right;
                    deleted = 1;
                }
            }
            if(parentRightVal!=NULL && deleted==0) {
                if(*parentRightVal == *valToDelete) {
                    parent->right = nodeToDelete->right;
                }
            }
        }
    } else {
        TreeNode *succ = nodeToDelete->right;
        TreeNode *succParent = nodeToDelete;
        TreeNode *tmp = nodeToDelete;

        if(succ->left == NULL) {
            TreeNode *succParentParent = getParent(theTree, succParent);
            
            if(succParentParent!=NULL) {
                int *succParentParentLeftVal = (int*)succParentParent->left->data;
                int *succParentParentRightVal = (int*)succParentParent->right->data;

                succ->left = succParent->left;
                if(*succParentParentLeftVal==*valToDelete) {
                    succParentParent->left = succ;
                } else if(*succParentParentRightVal==*valToDelete) {
                    succParentParent->right = succ;
                }
            } else {
                succ->left = succParent->left;
                theTree->root = succ;
            }

            free(tmp);
            theTree->numElements--;
            theTree->height = depth(theTree->root)+1;
            balanceTree(theTree);
            return;
        }

        while(succ->left!=NULL) {
            succParent = succ;
            succ = succ->left;
        }

        TreeNode *nodeToDeleteParent = getParent(theTree, nodeToDelete);

        succ->left = nodeToDelete->left;
        TreeNode *tmpSuccRight = succ->right;
        succ->right = nodeToDelete->right;
        nodeToDelete = succ;
        
        succParent->left = tmpSuccRight;
        
        if(nodeToDeleteParent!=NULL) {
            int *nodeToDeleteParentLeftVal = (int*)nodeToDeleteParent->left->data;
            int *nodeToDeleteParentRightVal = (int*)nodeToDeleteParent->right->data;
            if(*nodeToDeleteParentLeftVal == *valToDelete) {
                nodeToDeleteParent->left = succ;
            } else if(*nodeToDeleteParentRightVal == *valToDelete) {
                nodeToDeleteParent->right = succ;
            }
            //nodeToDeleteParent->left = succ;
        } else {
            theTree->root = succ;
        }

        free(tmp);
        theTree->numElements--;
        theTree->height = depth(theTree->root)+1;
        balanceTree(theTree);
        return;
    }

    free(nodeToDelete);
    theTree->numElements--;
    theTree->height = depth(theTree->root)+1;
    balanceTree(theTree);

    return;
}

/**Function to determine if a binary tree is empty.
 *@param theTree pointer to a self-balancing binary tree
 *@return If tree is empty, return 1. Otherwise, return 0.
 **/
int treeIsEmpty(Tree *theTree) {
    if(theTree!=NULL) {
        if(theTree->root==NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

/**Function to determine if a binary tree node has two children.
 *@param root pointer to a self-balancing binary tree's root
 *@return If tree is empty, or does not exist, return 1. Otherwise, return 0.
 **/
int treeHasTwoChildren(TreeNode *root) {
    if(root==NULL) {
        return 0;
    }
    if(root->left!=NULL && root->right!=NULL) {
        return 1;
    } else {
        return 0;
    }
}

/**Function to return a given value in the tree, dependant on the compare function pointer parameters.
 *Compares nodes, until compare function returns zero, or the tree is exhausted.
 *@param theTree pointer to a self-balancing binary tree's root
 *@return pointer to the data found. If tree is empty or data is not found, return NULL.
 **/
void *treeFindNode(Tree *theTree, void *data) {
    if(theTree==NULL || data==NULL) {
        return NULL;
    }

    TreeNode *dataNode = createBalancedBinNode(&data);
    int *findVal = (int*)((TreeNode*)dataNode)->data;

    TreeNode *tmp = (TreeNode*)theTree->root;

    while(1) {
        if(theTree->compareFP(dataNode, tmp)==1) {
            int *tmpVal;
            if(tmp!=NULL) {
                tmpVal = (int*)tmp->data;
                if(*tmpVal == *findVal) {
                    free(dataNode);
                    return tmp;
                }
            }

            tmp = tmp->right;
        } else if(theTree->compareFP(dataNode, tmp)==-1) {
            int *tmpVal;
            if(tmp!=NULL) {
                tmpVal = (int*)tmp->data;
                if(*tmpVal == *findVal) {
                    free(dataNode);
                    return tmp;
                }
            }

            tmp = tmp->left;
        } else {
            free(dataNode);
            return NULL;
        }


    }
    
    free(dataNode);
    return NULL;
}

/**Function to return the smallest value of a tree, dependant on the compare function pointer parameters.
 *@param theTree pointer to a self-balancing binary tree's root
 *@return pointer to the min found. If tree is empty, return NULL.
 **/
void *treeFindMin(Tree *theTree) {
    if(theTree==NULL) {
        return NULL;
    } else if(theTree->root==NULL) {
        return NULL;
    }

    TreeNode *tmp = (TreeNode*)theTree->root;
    while(tmp->left!=NULL) {
        tmp = tmp->left;
    }

    return (int*)tmp->data;
}

/**Function to return the largest value of a tree, dependant on the compare function pointer parameters.
 *@param theTree pointer to a self-balancing binary tree's root
 *@return pointer to the maximum value found. If tree is empty, return NULL.
 **/
void* treeFindMax(Tree *theTree) {
    if(theTree==NULL) {
        return NULL;
    } else if(theTree->root==NULL) {
        return NULL;
    }

    TreeNode *tmp = (TreeNode*)theTree->root;
    while(tmp->right!=NULL) {
        tmp = tmp->right;
    }

    return (int*)tmp->data;
}

/**Function to print the BST in order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printInorder(TreeNode* node, void (*printNodeFP) (void *data)) {
     if(node == NULL) {
          return;
     }

     printInorder(node->left, printNodeFP);
     printNodeFP(node);
     printf(" -> ");
     printInorder(node->right, printNodeFP);
}
/**function to print a tree in-order. EG 
 *              A
 *            /    \
 *          B       C
 *         / \     / \
 *        D   F   G   E
 *would print nodes thusly: D->B->F->A->G->C->E
 *@param theTree pointer to a self-balancing binary tree
 *@param printNodeFP pointer to a function to print void pointer data.
 **/
void treeInOrderPrint(Tree *theTree, void (*printNodeFP) (void *data)) {
    if(theTree==NULL || printNodeFP==NULL) {
        return;
    }

    TreeNode *start = (TreeNode*)theTree->root;
    printInorder(start, printNodeFP);
    printf("\n");
}

/**Function to print the BST pre order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printPreorder(TreeNode* node, void (*printNodeFP) (void *data)) {
     if(node == NULL) {
          return;
     }

     printNodeFP(node);
     printf(" -> ");
     printPreorder(node->left, printNodeFP);
     printPreorder(node->right, printNodeFP);
}
/**Function to print a tree pre-order. EG 
 *              A
 *            /   \
 *          B       C
 *         / \     / \
 *        D   F   G   E
 *would print nodes thusly: A->B->D->F->C->G->E
 *@param theTree pointer to a self-balancing binary tree
 *@param printNodeFP pointer to a function to print void pointer data.
 **/
void treePreOrderPrint(Tree *theTree, void (*printNodeFP) (void *data)) {
    if(theTree==NULL || printNodeFP==NULL) {
        return;
    }

    TreeNode *start = (TreeNode*)theTree->root;
    printPreorder(start, printNodeFP);
    printf("\n");
}

/**Function to print the BST post order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printPostorder(TreeNode* node, void (*printNodeFP) (void *data)) {
     if(node == NULL) {
          return;
     }

     printPostorder(node->left, printNodeFP);
     printPostorder(node->right, printNodeFP);
     printNodeFP(node);
     printf(" -> ");
}
/**Function to print a tree in post-order. EG 
 *              A
 *            /   \
 *          B       C
 *         / \     / \
 *        D   F   G   E
 *would print nodes thusly: D->F->B->G->C->E->A
 *@param theTree pointer to a self-balancing binary tree's root
 *@param printNodeFP pointer to a function to print void pointer data.
 **/
void treePostOrderPrint(Tree *theTree, void (*printNodeFP) (void *data)) {
    if(theTree==NULL || printNodeFP==NULL) {
        return;
    }

    TreeNode *start = (TreeNode*)theTree->root;
    printPostorder(start, printNodeFP);
    printf("\n");
}

void printTree(Tree *theTree) {
    if(theTree->root==NULL) {
        printf("Empty root. Could not print.\n");
        return;
    }

    int i;
    int rows = depth(theTree->root);
    int row = 1;
    int printedPadding = 0;

    int upTil;
    if(theTree->height==0) {
        upTil = 1;
    } else {
        upTil = pow(2, theTree->height-1)-1;
    }

    for(i=0;i<upTil;i++) {
        if(printedPadding==0) {

            int j;
            for(j=0;j<=(pow(2,(rows-(row-1)))-2);j++) {
                printf(" ");
            }
            printedPadding = 1;
        }

        TreeNode *print = NthNode(theTree->root, i+1);
        if(print!=NULL) {
            int *valToPrint = (int*)print->data;
               printf("%02d", *valToPrint);
        } else {
            printf("--");
        }

        int j;
        for(j=0;j<=(pow(2,(rows-(row-1)))-2);j++) {
            printf("  ");
        }

        if(((i+2) & (i+1)) == 0) {
            printf("\n");
            row++;
            printedPadding = 0;
        }
    }
    printf("\n");
}

TreeNode *getParent(Tree *theTree, void *node) {
    TreeNode *childNode = (TreeNode*)node;
    int *valToFind = (int*)childNode->data;

    int i;
    for(i=0; i<pow(2, theTree->height); i++) {
        TreeNode *currNode = NthNode(theTree->root, i);
        if(currNode!=NULL) {
            int *currNodeVal = (int*)currNode->data;
            if(*currNodeVal == *valToFind) {
                if(i==0) {
                    return NULL; /*Because the root has no parent*/
                }
                return NthNode(theTree->root, (i/2));
            }
        }
    }
    return NULL;
}

TreeNode* NthNode(TreeNode *root, int n) {
    int bitIndex = 0;
    while(1) { 
        if(1 << (bitIndex + 1) > n) {
            break;
        }
        bitIndex++;
    }
    bitIndex--;

    for(; bitIndex >= 0; bitIndex--) {
        int mask = (1 << bitIndex);
        if(n & mask) {
            if(root->right!=NULL) {
                root = root->right;
            } else {
                return NULL;
            }
        } else {
            if(root->left!=NULL) {
                root = root->left;
            } else {
                return NULL;
            }
        }
    }
    return root;
}

int MAX(int a, int b) {
    if(a>b) {
        return a;
    } else {
        return b;
    }
}

int depth(TreeNode *n) {
    if(n == NULL) {
        return 0;
    } else {
        return MAX(depth(n->left), depth(n->right)) + 1;
    }
}