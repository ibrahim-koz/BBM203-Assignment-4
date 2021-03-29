//
// Created by x1 doa on 1/14/2020.
//
#include <stdio.h>
#include <string.h>
#include "Flow.h"
#include "Utils/Random.h"

void build_tree(NodePointer node_ptr, ParsedLines *op_file, ParsedLines *pre_op_file,
                ParsedLines *rel_op_file, ParsedLines *set_op_file, ParsedLines *var_file) {
    if (strcmp((char *) (node_ptr->iData), "cond") == 0) {
        int choice = randint(2);
        if (choice == 0) {
            create_branches(node_ptr, 3);

            (node_ptr->ptrBranches)[0] = new_node("cond", sizeof("cond"));
            (node_ptr->ptrBranches)[1] = new_node("set-op", sizeof("set-op"));
            (node_ptr->ptrBranches)[2] = new_node("cond", sizeof("cond"));

            build_tree((node_ptr->ptrBranches)[0], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[1], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[2], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
        } else if (choice == 1) {
            create_branches(node_ptr, 3);

            (node_ptr->ptrBranches)[0] = new_node("expr", sizeof("expr"));
            (node_ptr->ptrBranches)[1] = new_node("rel-op", sizeof("rel-op"));
            (node_ptr->ptrBranches)[2] = new_node("expr", sizeof("expr"));

            build_tree((node_ptr->ptrBranches)[0], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[1], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[2], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
        }
    } else if (strcmp((char *) (node_ptr->iData), "expr") == 0) {
        int choice = randint(3);
        if (choice == 0) {
            create_branches(node_ptr, 3);

            (node_ptr->ptrBranches)[0] = new_node("expr", sizeof("expr"));
            (node_ptr->ptrBranches)[1] = new_node("op", sizeof("op"));
            (node_ptr->ptrBranches)[2] = new_node("expr", sizeof("expr"));

            build_tree((node_ptr->ptrBranches)[0], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[1], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[2], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
        } else if (choice == 1) {
            create_branches(node_ptr, 2);

            (node_ptr->ptrBranches)[0] = new_node("pre-op", sizeof("pre-op"));
            (node_ptr->ptrBranches)[1] = new_node("expr", sizeof("expr"));

            build_tree((node_ptr->ptrBranches)[0], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
            build_tree((node_ptr->ptrBranches)[1], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
        } else if (choice == 2) {
            create_branches(node_ptr, 1);

            (node_ptr->ptrBranches)[0] = new_node("var", sizeof("var"));

            build_tree((node_ptr->ptrBranches)[0], op_file, pre_op_file,
                       rel_op_file, set_op_file, var_file);
        }
    } else if (strcmp((char *) (node_ptr->iData), "op") == 0) {
        int choice = randint(op_file->parsed_line_number);
        create_branches(node_ptr, 1);
        (node_ptr->ptrBranches)[0] = new_node((op_file->parsed_lines_)[choice].tokens[0],
                                              sizeof((op_file->parsed_lines_)[choice].tokens[0]));
    } else if (strcmp((char *) (node_ptr->iData), "pre-op") == 0) {
        int choice = randint(pre_op_file->parsed_line_number);
        create_branches(node_ptr, 1);
        (node_ptr->ptrBranches)[0] = new_node((pre_op_file->parsed_lines_)[choice].tokens[0],
                                              sizeof((pre_op_file->parsed_lines_)[choice].tokens[0]));
    } else if (strcmp((char *) (node_ptr->iData), "rel-op") == 0) {
        int choice = randint(rel_op_file->parsed_line_number);
        create_branches(node_ptr, 1);
        (node_ptr->ptrBranches)[0] = new_node((rel_op_file->parsed_lines_)[choice].tokens[0],
                                              sizeof((rel_op_file->parsed_lines_)[choice].tokens[0]));
    } else if (strcmp((char *) (node_ptr->iData), "set-op") == 0) {
        int choice = randint(set_op_file->parsed_line_number);
        create_branches(node_ptr, 1);
        (node_ptr->ptrBranches)[0] = new_node((set_op_file->parsed_lines_)[choice].tokens[0],
                                              sizeof((set_op_file->parsed_lines_)[choice].tokens[0]));
    } else if (strcmp((char *) (node_ptr->iData), "var") == 0) {
        int choice = randint(var_file->parsed_line_number);
        create_branches(node_ptr, 1);
        (node_ptr->ptrBranches)[0] = new_node((var_file->parsed_lines_)[choice].tokens[0],
                                              sizeof((var_file->parsed_lines_)[choice].tokens[0]));
    }
}

void print_alg(NodePointer node_ptr) {
    if (strcmp((char *) (node_ptr->iData), "cond") == 0) {
        print_alg((node_ptr->ptrBranches)[0]);
        print_alg((node_ptr->ptrBranches)[1]);
        print_alg((node_ptr->ptrBranches)[2]);
    } else if (strcmp((char *) (node_ptr->iData), "expr") == 0) {
        if (node_ptr->numBranches == 3){
            print_alg((node_ptr->ptrBranches)[0]);
            print_alg((node_ptr->ptrBranches)[1]);
            print_alg((node_ptr->ptrBranches)[2]);
        }
        else if (node_ptr->numBranches == 2){
            print_alg((node_ptr->ptrBranches)[0]);
            printf("(");
            print_alg((node_ptr->ptrBranches)[1]);
            printf(")");
        }
        else if (node_ptr->numBranches == 1){
            print_alg((node_ptr->ptrBranches)[0]);
        }
    } else if (strcmp((char *) (node_ptr->iData), "op") == 0) {
        printf("%s", (char *) ((node_ptr->ptrBranches)[0]->iData));
    } else if (strcmp((char *) (node_ptr->iData), "pre-op") == 0) {
        printf("%s", (char *) ((node_ptr->ptrBranches)[0]->iData));
    } else if (strcmp((char *) (node_ptr->iData), "rel-op") == 0) {
        printf("%s", (char *) ((node_ptr->ptrBranches)[0]->iData));
    } else if (strcmp((char *) (node_ptr->iData), "set-op") == 0) {
        printf("%s", (char *) ((node_ptr->ptrBranches)[0]->iData));
    } else if (strcmp((char *) (node_ptr->iData), "var") == 0) {
        printf("%s", (char *) ((node_ptr->ptrBranches)[0]->iData));
    }
}
