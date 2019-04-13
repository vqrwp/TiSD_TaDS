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

    printf("\n\n�६� %d-� 'push'\n"
           "1. �����吝� ᯨ᮪: %f\n"
           "2. �����: %f\n", count, tock1 - tick1, tock2 - tick2);

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

    printf("\n�६� %d-� 'pop'\n"
           "1. �����吝� ᯨ᮪: %f\n"
           "2. �����: %f\n", count, tock1 - tick1, tock2 - tick2);

    printf("\n������ �����吝��� ᯨ᪠ �� %d ����⮢:\n"
           "%d\n"
           "������ ����� �� %d ����⮢:\n"
           "%d\n", count, sizeof(list_t) * count, count, sizeof(char) * count);
    puts("---------------------------------------------------\n");
    free(string);
}

void efficience()
{
    if (MAX_SIZE_VEC < 100000)
    {
        printf("���誮� �����쪨� ���ᨬ���� ࠧ���, ���⠢�� ���ᨬ���� ࠧ��� �� 1000000\n");
    }
    else
    {
        print(10000);
        print(100000);
        print(MAX_SIZE_VEC);
    }

}