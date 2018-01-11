/*
Maksymilian Mastalerz(0956502)
mmastale@mail.uoguelph.ca
*/

/**
 * @file tree.h
 * @author Max Mastalerz
 * @date July 2017
 * @brief File containing additional function prototypes for the BST
 */

#ifndef STUDENT_TREE_API_
#define STUDENT_TREE_API_
#include "balancedTreeAPI.h"

/*You may add anything to this .h file that you need to add to your tree ADT*/

//YOU MUST LEAVE THESE TYPEDEFS AS IS. 
/**typedef for struct name*/
typedef struct BalancedBinTreeNode TreeNode;

/**typedef for struct name*/
typedef struct BalancedBinTree Tree;




/*complete the struct definitions.  You can change the existing parts if you wish.
*/
struct BalancedBinTree {
  //define your tree here.  You can change these if you need to but your tree must be abstract.
    int height;
    int numElements;
    TreeNode *root; ///< pointer to generic data that is to be stored in the tree
    int (*compareFP) (void *data1, void *data2); ///< function pointer to a comparison function for the purpose of inserting and deleting elements
    void (*destroyFP) (void *data); ///< function pointer to a function to free a single pointer that is deleted from the tree
    void *(*copyFP)(void *toBeCopy); ///< function pointer to a function that copies pointer data

};

struct BalancedBinTreeNode {
    void *data; ///< pointer to generic data that is to be stored in the heap
    TreeNode *left; ///< pointer to left tree node of current node. Null if empty.
    TreeNode *right; ///< pointer to right tree node of current node. Null if empty.
    
    //Add additional structure elements here
    int height;
};

/**Function to compare two nodes
 *@param data1 a void pointer to the first element being compared
 *@param data2 a void pointer to the second element being compared
 *@return Returns an integer -1, 0, or 1 depending on comparison results
 **/
int compareFunction(void *data1, void *data2);

/**Function to free content
 *@param toBeDeleted A void pointer to the content being deleted
 **/
void destroyFunction(void *toBeDeleted);

/**Function to duplicate a node
 *@param toBeCopy a void pointer to the content being duplicated
 *@return Returns the duplicate
 **/
void *copyFunction(void *toBeCopy);

/**Function to print a node
 *@param toBePrinted the node being printed
 **/
void printFunction(void *toBePrinted);

/**Function to print the BST in order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printInorder(TreeNode* node, void (*printNodeFP) (void *data));

/**Function to print the BST pre order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printPreorder(TreeNode* node, void (*printNodeFP) (void *data));

/**Function to print the BST post order
 *@param node the node to start printing from(recursive)
 *@param printNodeFP a pointer to a function that can print nodes
 **/
void printPostorder(TreeNode* node, void (*printNodeFP) (void *data));

/**Function to print the BST in a visually appealing manner
 *@param theTree the Tree that is being printed
 **/
void printTree(Tree *theTree);

/**Function to get the parent of a node in a BST
 *@param theTree the Tree that is in question
 *@param node the node whose parent is being looked for
 *@return Returns the parent of the node if it exists
 **/
TreeNode *getParent(Tree *theTree, void *node);

/**Function to retreive a node found at position n
 *@param root The root of the BST from which the search will start
 *@param n The nth node that is being searched for
 *@return Returns the node found at the nth position in a BST
 **/
TreeNode *NthNode(TreeNode *root, int n);

/**Function that returns the max of two values
 *@param a first digit being compared
 *@param b second digit being compared
 *@return Returns the max of the values
 **/
int MAX(int a, int b);

/**Function to determine the depth at which node n sits
 *@param n
 *@return Returns the depth of the node
 **/
int depth(TreeNode *n);

/**Function to balance out the tree if the balance factor is off
 *@param tree The tree to be balanced
 **/
void balanceTree(Tree *tree);

/**Function that returns the location of the newly balanced node
 *@param tree The node from which the balancing wil begin
 *@return Returns a balanced node.
 **/
TreeNode *balanceNode(TreeNode *node);

/**Function to determine the height of a node in a BST
 *@param node The node to be checked
 *@return Returns the height of the node
 **/
int nodeHeight(TreeNode *node);

/**Function to calculate the balance factor of a node
 *@param node The node to be checked
 *@return Returns the balance factor of the node
 **/
int balanceFactorOfNode(TreeNode *node);

/**Function that performs a left rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *leftRotate(TreeNode *node);

/**Function that performs a right rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *rightRotate(TreeNode *node);

/**Function that performs a left-right rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *leftRightRotate(TreeNode *node);

/**Function that performs a right-left rotation to maintain the AVL tree property
 *@param node The node to be the pivot for the rotation
 *@return Returns the new node position
 **/
TreeNode *rightLeftRotate(TreeNode *node);

#endif