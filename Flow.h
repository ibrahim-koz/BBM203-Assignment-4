//
// Created by x1 doa on 1/14/2020.
//

#ifndef ASSIGNMENT4_FLOW_H
#define ASSIGNMENT4_FLOW_H
#include "Utils/Tree.h"
#include "FileIO/parser.h"

void build_tree(NodePointer node_ptr, ParsedLines *op_file, ParsedLines *pre_op_file,
                ParsedLines *rel_op_file, ParsedLines *set_op_file, ParsedLines *var_file);

void print_alg(NodePointer node_ptr);
#endif //ASSIGNMENT4_FLOW_H
