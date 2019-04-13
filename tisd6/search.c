//
// Created by Margo on 19.12.2018.
//

#include "search.h"
#include "tree.h"
#include "balance.h"
#include "hash.h"

tnode * search_in_tree(tnode *tree, char *word, int *amount, int *flag)
{
    //node_count++;
    //printf("-%s- -%s-\n", word, tree->word);
    if (tree == NULL)
    {
        *flag = -1;

        return tree;
    }
    *amount = *amount + 1;
    if (strcmp(tree->word, word) == 0)
    {
        *flag = 1;
        return tree;
    }
    else if (strcmp(tree->word, word) < 0)
    {
        tree->left = search_in_tree(tree->left, word, amount, flag);
    }
    else
    {
        tree->right = search_in_tree(tree->right, word, amount, flag);
    }
}

int search_in_hash(t_hash **table, char *word, int table_len, int *amount)
{
    int index = what_index(word, table_len);
    t_hash *head = table[index];
    if (looking_in_list(head, word, amount) == NULL)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

t_hash *looking_in_list(t_hash *head, char *word, int *amount)
{
    //printf("-%s- -%s-", head->word, word);
    *amount = *amount + 1;
    if (head == NULL)
    {
        return NULL;
    }
    if (strcmp(head->word, word) == 0)
    {
        return head;
    }
    else
    {
        looking_in_list(head->next, word, amount);
    }
}

int search_in_file(FILE *f, char *word, int *amount)
{
    rewind(f);
    int i = 0;
    char *s = calloc(100, sizeof(char));
    while (!feof(f))
    {
        fscanf(f, "%c", &s[i]);
        if (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '.' || feof(f))
        {
            s[i] = '\0';
            if (strcmp(s, " ") != 0 && strcmp(s, "\n") != 0 && i != 0)
            {
                *amount = *amount + 1;
                if (strcmp(word, s) == 0)
                {
                    return 1;
                }
            }
            i = 0;

        }
        else
        {
            i++;
        }
    }
    free(s);
    return -1;
}