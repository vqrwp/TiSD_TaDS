//
// Created by Margo on 10.11.2018.
//
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

void sparse_mult()
{
    int line = 0, column = 0, type_input = 0;
    printf("Какой размер вы хотите задать матрице?\n"
           "ВНИМАНИЕ: здесь и далее, если программа повторно выводит сообщение о том,\n"
           "что требуется ввести число, то предыдущий ввод является некорректным!!\n");


    while (line == 0 || line > 10000)
    {
        printf("Введите число от 1 до 10000 - количество строк:\n ");
        scan_int(&line);
    }
    while (column == 0 || column > 10000)
    {
        printf("Введите число от 1 до 10000 - количество столбцов:\n ");
        scan_int(&column);
    }

    float *values = malloc((column * line + 1) * sizeof(float));
    int *columns= malloc((column * line + 1) * sizeof(int)), num_elems = 0, not_null_lines = 0;
    list_t *lines = NULL;

    float *values_str = malloc((line + 1) * sizeof(float));
    int *columns_str = malloc((line + 1) * sizeof(int)), num_elems_str = 0;
    list_t *lines_str = NULL;

    while (type_input != 1 && type_input != 2)
    {
        printf("Как вы хотите ввести матрицу? Введите 1, если автоматически, 2 если вручную.\n");
        scan_int(&type_input);
    }
    if (type_input == 1)
    {
        float proc = -1;

        while (proc > 1 || proc < 0.1)
        {
            printf("На сколько процентов необходимо заполнить матрицу? Введите целое число\n"
                   "от 0.1 до 1 - это будет процент заполненности матрицы: \n");
            scan_float(&proc);
        }
        num_elems = auto_input(values, columns, &lines, line, column, proc, &not_null_lines);
    }
    else
    {
        num_elems = hand_input_mtr(values, columns, &lines, line, column, &not_null_lines);
    }
    if (num_elems < 25)
    {
        printf("Values: \n");
        print_array_f(values, num_elems);
        printf("\nColumns: \n");
        print_array_i(columns, num_elems);
        printf("\nLines: \n");
        print_from_tail(lines);
    }

    type_input = 0;
    printf("Далее необходимо ввести вектор-строку, на которую будет умножаться наша матрица.\n"
           "Размер заранее известен, так как умножать строку-вектор на матрицу можно только тогда, \n"
           "когда в строке столько элементов, сколько в матрице строк.\n");
    while (type_input != 1 && type_input != 2)
    {
        printf("Как вы хотите ввести вектор-строку? Введите 1, если автоматически, 2 если вручную.\n");
        scan_int(&type_input);
    }
    if (type_input == 1)
    {
        float proc = -1;

        while (proc > 1 || proc < 0.1)
        {
            printf("На сколько процентов необходимо заполнить матрицу? Введите целое число\n"
                   "от 0.1 до 1 - это будет процент заполненности матрицы: \n");
            scan_float(&proc);
        }
        int extra = 0;
        num_elems_str = auto_input(values_str, columns_str, &lines_str, 1, line, proc, &extra);
    }
    else
    {
        num_elems_str = hand_input_str(values_str, columns_str, &lines_str, 1, line);
    }
    if (!lines_str)
    {
        push(&lines_str, 0, 0);
    }
    if (num_elems_str < 25)
    {
        printf("Values: \n");
        print_array_f(values_str, num_elems_str);
        printf("\nColumns: \n");
        print_array_i(columns_str, num_elems_str);
        printf("\nLines: \n");
        print_from_tail(lines_str);
    }

    float *values_res = malloc((column + 1) * sizeof(float));
    int *columns_res = malloc((column + 1) * sizeof(int)), num_elems_res = 0;
    list_t *lines_res = NULL;

    num_elems_res = mult_sparse_mtr(lines, columns, values, columns_str, values_str,
                                    &lines_res, columns_res, values_res, num_elems, num_elems_str, column,
                                    not_null_lines);
    if (lines_res)
    {
        if (num_elems_res < 100)
        {
            printf("\n\nANSWER\nValues:\n");
            print_array_f(values_res, num_elems_res);
            printf("\nColumns:\n");
            print_array_i(columns_res, num_elems_res);
            printf("\nLines: \n");
            print_from_tail(lines_res);
        }
        else
        {
            int flag = -1;
            printf("Ответ слишком большой для печати, нажмите 1 чтобы вывести его, 0 чтобы не выводить:   ");
            while (flag != 0 && flag != 1)
            {
                scan_int(&flag);
            }
            if (flag)
            {
                printf("\n\nANSWER\nValues:\n");
                print_array_f(values_res, num_elems_res);
                printf("\nColumns:\n");
                print_array_i(columns_res, num_elems_res);
                printf("\nLines: \n");
                print_from_tail(lines_res);
            }
        }
    }
    else
    {
        printf("В результате умножения получилась нулевая матрица.\n");
    }

    free(values_res);
    free(columns_res);
    free(values);
    free(values_str);
    free(columns);
    free(columns_str);
}
