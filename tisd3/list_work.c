#include <stdlib.h>
#include <stdio.h>
#include "headers.h"

void push(list_t** list, int nk, int i)
{
    list_t* node = malloc(sizeof(list_t));
    node->num_line = nk;
    node->first_in_line = i;
    node->next = *list;
    *list = node;
}

void print_from_head(const list_t *list)
{
    if (list) {
        printf("%d ", list->num_line);
        printf("%d\n", list->first_in_line);
        print_from_head(list->next);
    }
}

void print_from_tail(const list_t *list)
{
    if (list) {
        print_from_tail(list->next);
        printf("%d ", list->num_line);
        printf("%d\n", list->first_in_line);
    }
}