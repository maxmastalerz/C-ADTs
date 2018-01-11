/**
 * @file listFunctions.h
 * @author Max Mastalerz
 * @date May 2017
 * @brief File containing the function definitions for the list's print, delete, & compare functionality
 */

#ifndef _LIST_FUNCTIONS_
#define _LIST_FUNCTIONS_

#include <stdio.h>
#include <stdlib.h>

/**Function to print void pointer as int
*@param toBePrinted void pointer to be printed as an int
*@pre toBePrinted must be a valid node
**/
void myPrintFunction(void *toBePrinted);

/**Function to delete a node with matched data
*@param toBeDeleted void pointer to be deleted
*@pre toBeDeleted must be a valid node
**/
void myDeleteFunction(void *toBeDeleted);

/**Function to print void pointer as int
*@param a void pointer to be compared
*@param b void pointer to be compared
*@pre a & b must be a valid void types that can be compared as ints
*@return integer to be used for comparison operations
**/
int myCompareFunction(const void *a, const void *b);

#endif