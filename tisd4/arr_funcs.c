#include "arr_funcs.h"
#include <stdio.h>
#include "structs.h"
#include "list_funcs.h"

void arr_push(char **string, char symb, const int size)
{
    if (size < MAX_SIZE_VEC)
    {
        *(*string + size) = symb;
    }
    else
    {
        puts("Стек заполнен!\n");
    }
}

char arr_pop(char **string, int size)
{
    if (size != 0)
    {
        char p = *(*string + size - 1);
        *(*string + size - 1) = '\0';
        return p;
    }
    else
    {
        //puts("Стек пуст!\n");
    }
}

void print_arr(char *string, int size)
{
    if (size == 0)
    {
        puts("Стек пуст, печатать нечего!\n");
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            printf("%c ", string[i]);
        }
        printf("\n");
    }
}