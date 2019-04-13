//
// Created by Margo on 19.12.2018.
//

#ifndef NASTYA_TREE_FUNCS_H
#define NASTYA_TREE_FUNCS_H

#include "tree.h"
#include <malloc.h>
#include <stdio.h>

tnode* rotateleft(tnode* q);
tnode* rotateright(tnode* p);
void fixheight(tnode* p);
tnode* bal_add_node(tnode *root, tnode *node);
tnode* balance(tnode* p);
tnode* read_file_balanced(tnode *root, FILE *f);
int height(tnode* p);
int bfactor(tnode* p);

#endif //NASTYA_TREE_FUNCS_H
