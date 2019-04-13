
#ifndef TREE_HASH_H
#define TREE_HASH_H

#include "tree.h"

typedef struct node_table
{
    char word[SIZE_WORD];
    struct node_table *next;
}t_hash;

int len_list(t_hash *head);
int next_prime_number(int number);
t_hash* add_end(t_hash *head, t_hash *elem);
t_hash* create_hash_node(char *word);
int what_index(char *word, int len_table);
t_hash **insert_in_hash_table(t_hash **table, int *len_table, t_hash *node, int max_len);
void print_table(t_hash **table, int len_table);
int count_node_table(t_hash **table, int len_table);
t_hash **create_table(FILE *f, int *len_table);
int check_int(int *number, int min, int max);

#endif //TREE_HASH_H
