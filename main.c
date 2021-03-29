#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FileIO/parser.h"
#include "Utils/Tree.h"
#include "Flow.h"

int main() {
    ParsedLines *op_file = parse_lines();
    op_file->read_and_parse_lines(op_file, "op", "");

    ParsedLines *pre_op_file = parse_lines();
    pre_op_file->read_and_parse_lines(pre_op_file, "pre_op", " ");

    ParsedLines *rel_op_file = parse_lines();
    rel_op_file->read_and_parse_lines(rel_op_file, "rel_op", " ");

    ParsedLines *set_op_file = parse_lines();
    set_op_file->read_and_parse_lines(set_op_file, "set_op", " ");

    ParsedLines *var_file = parse_lines();
    var_file->read_and_parse_lines(var_file, "var", " ");

    srand(time(NULL));

    NodePointer root = new_node("cond", sizeof("cond"));
    build_tree(root, op_file, pre_op_file, rel_op_file, set_op_file, var_file);


    printf("if (");

    print_alg(root);

    printf(") { }");

    return 0;
}
