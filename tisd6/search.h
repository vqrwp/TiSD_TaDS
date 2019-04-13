#ifndef TISD6_SSARCH_H
#define TISD6_SSARCH_H

#include "tree.h"
#include "hash.h"

tnode * search_in_tree(tnode *tree, char *word, int *amount, int *flag);
//tnode* search_bal(tnode *root, char *word, int *flag);
t_hash *looking_in_list(t_hash *head, char *word, int *amount);
int search_in_hash(t_hash **table, char *word, int table_len, int *amount);
int search_in_file(FILE *f, char *word, int *amount);

#endif //TISD6_SSARCH_H
