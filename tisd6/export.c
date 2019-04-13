//
// Created by Margo on 16.12.2018.
//

#include "export.h"
#include "stdio.h"
#include "tree.h"

// обход дерева
void apply_pre(tnode *tree, FILE *f)
{
    if (tree == NULL)
    {
        return;
    }

    to_dot(tree, f);
    apply_pre(tree->left, f);
    apply_pre(tree->right, f);
}

void export_to_dot(FILE *f, const char *tree_name, tnode *tree)
{
    fprintf(f, "digraph %s {\n", tree_name);

    apply_pre(tree, f);

    fprintf(f, "}\n");
}

void to_dot(tnode *tree, FILE *f)
{

    if (tree->left)
    {
        fprintf(f, "\"%s \" -> \"%s \";\n", tree->word, tree->left->word);
    }

    if (tree->right)
    {
        fprintf(f, "\"%s \" -> \"%s \";\n", tree->word, tree->right->word);
    }
}