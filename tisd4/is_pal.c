#include "is_pal.h"
#include "structs.h"
#include "list_funcs.h"
#include "arr_funcs.h"
#include <stdio.h>
#include <malloc.h>

void ispoly(list_t *list, del_mem *list_del, int size, int size_del, char string[])
{
    if (size == 0)
    {
        puts("Стек пуст, нельзя определить, является палиндромом или нет!\n");
    }
    else
    {
        int i = 0, flag = 1, size1 = size;
        puts("Строка : ");
        print_from_head(list, size);
        char *word = calloc(size + 1, sizeof(char));
        while (size1)
        {
            word[size1 - 1] = arr_pop(&string, size1);
            size1--;
        }
        while (list)
        {
            char x = pop(&list, &list_del, &size, &size_del);
            char y = word[i];
            if (x != y)
            {
                flag = -1;
            }
            i++;
        }
        if (flag > 0)
        {
            printf("Данная строка - палиндром.\n");
        }
        else
        {
            printf("Данная строка не является палиндромом\n");
        }
    }
}