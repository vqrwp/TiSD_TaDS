//
// Created by Margo on 10.12.2018.
//

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>


tnode *create_node(char *val)
{
    tnode *node = malloc(sizeof(tnode));
    if (node)
    {
        strcpy(node->word, val);
        node->balance = 0;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void count_node(tnode *tree, int *sum)
{
    if (tree == NULL)
        return;

    *sum += 1;
    count_node(tree->left, sum);
    count_node(tree->right, sum);
}

tnode *ord_add_node(tnode *tree, tnode *node)
{
    //node_count++;
    if (tree == NULL)
    {
        return node;
    }

    if (strcmp(tree->word, node->word) == 0)
    {
        tree->balance++;
        free(node);
    }
    else if (strcmp(tree->word, node->word) < 0)
    {
        tree->left = ord_add_node(tree->left, node);
    }
    else
    {
        tree->right = ord_add_node(tree->right, node);
    }
    return tree;
}

// Функция удаления поддерева
void freemem(tnode *tree)
{
    if (tree!=NULL)
    {
        freemem(tree->left);
        freemem(tree->right);
        free(tree);
    }
}
// Функция вывода дерева
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%d %s\n", p->balance, p->word);
        treeprint(p->right);
    }
}