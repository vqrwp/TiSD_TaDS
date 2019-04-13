//
// Created by Margo on 16.12.2018.
//

#ifndef TISD6_EXPORT_H
#define TISD6_EXPORT_H

#include "stdio.h"
#include "tree.h"

void export_to_dot(FILE *f, const char *tree_name, tnode *tree);
void apply_pre(tnode *tree, FILE *f);
void to_dot(tnode *tree, FILE *f);

#endif //TISD6_EXPORT_H
