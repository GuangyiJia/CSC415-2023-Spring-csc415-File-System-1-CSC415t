/**************************************************************
* Class:  CSC-415
* Names: Jaime Guardado, Guangyi Jia, Renee Sewak, Daniel Moorhatch
* Student IDs: 920290979, 920757003, 920875901, 922033512
* Project: Basic File System 
*
* File: helperFunctions.h
*
* Description: 
*	This file contains helper functions needed to execute commands
*   such as checking and setting the bits in our bitmap, getting
*   the number of bytes needed, and allocating free space.
*
**************************************************************/


#include "mfs.h"

uint64_t allocateFreeSpace_Bitmap(uint64_t block_ToBeAllocated);
int setUsed(uint64_t, int * freespace);
int setBitFree(uint64_t, int * freespace);
int checkBit(uint64_t, int * freespace);
int convertBitToBytes();