/**
 * @file functions.h
 * @author Max Mastalerz
 * @date June 2017
 * @brief File containing the function definitions of a hash table
 */

#ifndef _FUNCTIONS_API_
#define _FUNCTIONS_API_

#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"

int hashFunction(size_t tableSize, int key);

void destroyData(void *data);

void myPrintData(void *toBePrinted);

#endif