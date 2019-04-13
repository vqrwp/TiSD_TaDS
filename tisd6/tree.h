//
// Created by Margo on 10.12.2018.
//

#ifndef TISD6_TREE_H
#define TISD6_TREE_H

#include <stdio.h>
#include <string.h>
#define SIZE_WORD 100
#define SUCCESS 0
#define MAX_LEN_LIST 4
#define EFFICIENCY "efficiency.txt"
#define FILENAME "words.txt"
#define FILENAME2 "data2.txt"

typedef struct tnode
{                // узел дерева
    char word[SIZE_WORD];                  // указатель на строку (слово)
    int balance;                   // число вхождений
    struct tnode *left;          // левый потомок
    struct tnode *right;         // правый потомок
}tnode;

tnode *create_node(char *val);
void treeprint(struct tnode *p);
void freemem(tnode *tree);
void count_node(tnode *tree, int *sum);
tnode *ord_add_node(tnode *tree, tnode *node);

#endif //TISD6_TREE_H
