//
// Created by Margo on 19.12.2018.
//

#include "read_file.h"

tnode *read_file(FILE *f, tnode *root)
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
                tnode *node = create_node(s);
                root = ord_add_node(root, node);
            }
            i = 0;

        }
        else
        {
            i++;
        }
    }
    free(s);
    return root;
}