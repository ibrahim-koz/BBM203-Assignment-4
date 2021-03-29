//
// Created by x1 doa on 1/13/2020.
//

#ifndef ASSIGNMENT4_TREE_H
#define ASSIGNMENT4_TREE_H
//Creating a new type
typedef void * pVoid;
// Creating Node
struct Node_Structure
{
    // We use pVoid to point every type of data.
    pVoid iData;
    // We use pointer
    struct Node_Structure **ptrBranches;
    int numBranches;
};



// Define the new type Node and Node pointer
typedef struct Node_Structure Node, * NodePointer;

NodePointer new_node(pVoid InputData, int SizeofData);

void create_branches(NodePointer nodePtr, int numBranches);
#endif //ASSIGNMENT4_TREE_H
