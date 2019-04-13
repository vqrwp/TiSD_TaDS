//
// Created by Margo on 19.12.2018.
//

#include "balance.h"
#include <string.h>

// рассчет высоты узла
int height(tnode* p)
{
    return p ? p->balance : 0;
}

// новый узел в сбалансированном дереве
tnode* read_file_balanced(tnode *root, FILE *f)
{
    rewind(f);
    int i = 0;
    char *s = calloc(100, sizeof(char));
    while (!feof(f))
    {
        fscanf(f, "%c", &s[i]);
        //puts(s);
        if (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '.' || feof(f))
        {
            s[i] = '\0';
            //puts(s);
            if (strcmp(s, " ") != 0 && strcmp(s, "\n") != 0 && i != 0)
            {
                tnode *node = create_node(s);
                root = bal_add_node(root, node);
            }
            i = 0;

        }
        else
        {
            i++;
        }
    }
    //treeprint(root);
    free(s);
    return root;
}

// проверка узла на сбалансированность
int bfactor(tnode* p)
{
    if (height(p->right) == 1 && !p->left)
    {

        return 2;
    }
    else if (height(p->left) == 1 && !p->right)
    {
        return -2;
    }
    else
    {
        return height(p->right) - height(p->left);
    }
}

// балансировка дерева
tnode* balance(tnode* p) // балансировка узла p
{
    fixheight(p);
    if( bfactor(p) == 2 )
    {
        if(bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p) == -2 )
    {
        if (bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}


// вставка узла в сбалансированное дерево
tnode* bal_add_node(tnode *root, tnode *node)
{
    int cmp;

    if (root == NULL)
    {
        return node;
    }
    if (strcmp(node->word, root->word) > 0)
    {
        root->left = bal_add_node(root->left, node);
        //fixheight(root);
        root = balance(root);
    }
    else if (strcmp(node->word, root->word) < 0)
    {
        root->right = bal_add_node(root->right, node);
        //fixheight(root);
        root = balance(root);
    }
    root = balance(root);
    return root;
}

// пересчет высоты узла после балансировки
void fixheight(tnode* p)
{
    int hl = height(p->left);
    int hr = height(p->right);
    p->balance = (hl > hr ? hl : hr) + 1;
    //if (!p->left && !p->right)
    //     p->balance = hl;
    //printf("%s %d %d %d\n", p->word, hl, hr, p->balance);
}

// правый поворот
tnode* rotateright(tnode* p) // правый поворот вокруг p
{
    tnode* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}


// левый поворот
tnode* rotateleft(tnode* q) // левый поворот вокруг q
{
    tnode* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}