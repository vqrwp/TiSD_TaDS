#include "efficience.h"
#include "structs.h"
#include "list_funcs.h"
#include "arr_funcs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int count)
{
    puts("---------------------------------------------------\n");
    list_t *list = NULL;
    char *string = calloc(MAX_SIZE_VEC, sizeof(char));
    del_mem *list_del = NULL;
    int size1 = 0, size2 = 0, size_del = 0;
    srand((unsigned int)time(NULL));

    double tick1 = (double)clock() / CLOCKS_PER_SEC;

    for (int i = 0; i < count; i++)
    {
        push(&list, 'a', &size1);
    }

    double tock1 = (double)clock() / CLOCKS_PER_SEC;

    double tick2 = (double)clock() / CLOCKS_PER_SEC;

    for (int i = 0; i < count; i++)
    {
        arr_push(&string, 'a', size2);
        size2++;
    }

    double tock2 = (double)clock() / CLOCKS_PER_SEC;

    printf("\n\nВремя %d-чи 'push'\n"
           "1. односвязный список: %f\n"
           "2. вектор: %f\n", count, tock1 - tick1, tock2 - tick2);

    tick1 = (double)clock() / CLOCKS_PER_SEC;

    for (int i = 0; i < count; i++)
    {
        pop(&list, &list_del, &size1, &size_del);
    }

    tock1 = (double)clock() / CLOCKS_PER_SEC;

    tick2 = (double)clock() / CLOCKS_PER_SEC;

    for (int i = 0; i < count; i++)
    {
        arr_pop(&string, size2);
        size2--;
    }

    tock2 = (double)clock() / CLOCKS_PER_SEC;

    printf("\nВремя %d-чи 'pop'\n"
           "1. односвязный список: %f\n"
           "2. вектор: %f\n", count, tock1 - tick1, tock2 - tick2);

    printf("\nРазмер односвязного списка из %d элементов:\n"
           "%d\n"
           "Размер вектора из %d элементов:\n"
           "%d\n", count, sizeof(list_t) * count, count, sizeof(char) * count);
    puts("---------------------------------------------------\n");
    free(string);
}

void efficience()
{
    if (MAX_SIZE_VEC < 100000)
    {
        printf("Слишком маленький максимальный размер, поставьте максимальный размер от 1000000\n");
    }
    else
    {
        print(10000);
        print(100000);
        print(MAX_SIZE_VEC);
    }

}