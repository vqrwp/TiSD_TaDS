#include <stdio.h>
#include "scanf.h"
#include <stdlib.h>
#include "list_funcs.h"
#include "arr_funcs.h"
#include "is_pal.h"
#include <string.h>
#include "efficience.h"

/*
Создать программу работы со стеком,
выполняющую операции добавления,
удаления элементов и вывод текущего
состояния стека. Реализовать стек: а)
массивом; б) списком. Все стандартные
операции со стеком должны быть оформлены
подпрограммами. При реализации стека
списком в вывод текущего состояния стека
добавить просмотр адресов элементов стека
и создать свой список или массив свободных
областей (адресов освобождаемых
элементов) с выводом его на экран.

Special task:

Используя стек, определить, является ли строка
палиндромом.
*/

int main()
{
    int flag = 0, choise = 0, type = 0;
    list_t *list = NULL;
    del_mem *list_del = NULL;
    char *arr = calloc(MAX_SIZE_VEC, sizeof(char));
    int size = 0, size_del = 0;
    char elem = 0;
    printf("Данная программа производит работу со стеком.\n"
           "Стек реализуется двумя способами: \nа) с помощью вектора;\n"
           "б) с помощью односвязного списка.\n"
           "Тип данных при работе с обоими видами стека - char.\n"
           "Реализованы возможности удаления элемента из стека,\n"
           "добавления элемента в стек, показывания стека\n"
           "(в том числе вместе с адресами элементов),\n"
           "возможность вывода списка освобожденной памяти.\n"
           "Так же реализовано дополнительное задание - \n"
           "определяется, является ли строка, находящяяся в стеке,\n"
           "палиндромом.\n"
           "Введите, как вы хотите представлять стек: \n"
           "1. как вектор;\n"
           "2. как односвязный список.\n");
    while (type < 1 || type > 2)
    {
        puts("(нужно ввести либо 1, либо 2)\n");
        scan_int(&type);
    }
    while (flag == 0)
    {
        if (type == 2)
        {
            printf("\n------------------Меню------------------\n"
                   "1. Показать текущее состояние стека;\n"
                   "2. Добавить в стек элемент;\n"
                   "3. Удалить элемент из стека;\n"
                   "4. Показать освобожденные адреса;\n"
                   "5. Показать текущее состояние стека с адресами;\n"
                   "6. Определить, является ли строка палиндромом;\n"
                   "7. Эффективность;\n"
                   "8. Выход.\n"
                   "Введите пункт, который вы хотите исполнить:  ");
            while (choise < 1 || choise > 8)
            {
                puts("(нужно ввести число от 1 до 8)\n");
                scan_int(&choise);
            }
            switch (choise)
            {
                case 1:
                    print_from_head(list, size);
                    choise = 0;
                    break;
                case 2:
                    printf("Введите элемент стека (один символ ASCII): ");
                    scan_char(&elem);
                    arr_push(&arr, elem, size);
                    push(&list, elem, &size);
                    choise = 0;
                    break;
                case 3:
                    arr_pop(&arr, size);
                    pop(&list, &list_del, &size, &size_del);
                    choise = 0;
                    break;
                case 4:
                    print_from_head_mem(list_del, size_del);
                    choise = 0;
                    break;
                case 5:
                    printf("Символ Его адрес\n");
                    print_from_head_with_addresses(list, size);
                    choise = 0;
                    break;
                case 6:
                    //void ispoly(list_t *list, del_mem *list_del, int size, int size_del, vec arr);
                    ispoly(list, list_del, size, size_del, arr);
                    flag = 1;
                    choise = 0;
                    break;
                case 7:
                    efficience();
                    choise = 0;
                    break;
                case 8:
                    flag = 1;
                    puts("\nЗавершение работы программы!");
                    choise = 0;
                    break;
                default:
                    break;
            }
        }
        if (type == 1)
        {
            printf("\n------------------Меню------------------\n"
                   "1. Показать текущее состояние стека;\n"
                   "2. Добавить в стек элемент;\n"
                   "3. Удалить элемент из стека;\n"
                   "4. Определить, является ли строка палиндромом;\n"
                   "5. Эффективность;\n"
                   "6. Выход.\n"
                   "Введите пункт, который вы хотите исполнить:  ");
            while (choise < 1 || choise > 8)
            {
                puts("(нужно ввести число от 1 до 8)\n");
                scan_int(&choise);
            }
            switch (choise)
            {
                case 1:
                    print_arr(arr, size);
                    choise = 0;
                    break;
                case 2:
                    printf("Введите элемент стека (один символ ASCII): ");
                    scan_char(&elem);
                    arr_push(&arr, elem, size);
                    push(&list, elem, &size);
                    choise = 0;
                    break;
                case 3:
                    arr_pop(&arr, size);
                    pop(&list, &list_del, &size, &size_del);
                    choise = 0;
                    break;
                case 4:
                    ispoly(list, list_del, size, size_del, arr);
                    flag = 1;
                    choise = 0;
                    break;
                case 5:
                    efficience();
                    choise = 0;
                    break;
                case 6:
                    flag = 1;
                    puts("\nЗавершение работы программы!");
                    choise = 0;
                    break;
                default:
                    break;
            }
        }
    }
    free(arr);
    return 0;
}