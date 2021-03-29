//
// Created by x1 doa on 1/13/2020.
//

#include "Tree.h"
#include <stdlib.h>
#include <stdint.h>

NodePointer new_node(pVoid InputData, int SizeofData){
    Node *result = malloc(sizeof(Node));
    result->iData = malloc(SizeofData);
    for (int iOffSet = 0; iOffSet < SizeofData; iOffSet++)
        *((uint8_t *) (result->iData + iOffSet)) = *((uint8_t *) (InputData + iOffSet));
    return result;
}


void create_branches(NodePointer nodePtr, int numBranches){
    nodePtr->ptrBranches = malloc(sizeof(NodePointer) * numBranches);
    nodePtr->numBranches = numBranches;
}