//
// Created by Margo on 10.11.2018.
//
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

void ord_mult()
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

    printf("\n\n");
    float **mtr = calloc((size_t) (line * column + 1), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = calloc((size_t) (column + 1), sizeof(float));
    }
    mtr = making_ord_mtr(mtr, lines, columns, values, num_elems, line, column, not_null_lines);
    //print_mtr(mtr, line, column);
    printf("\n\n");

    float *str = calloc((size_t) (line + 1), sizeof(float));
    str = making_ord_vec(str, columns_str, values_str, num_elems_str);
    //print_array_f(str, line);

    printf("\n\nANSWER:\n");

    float *str_res = calloc((size_t)(column + 1), sizeof(float));
    str_res = mult_ord_mtr(mtr, str, line, column, str_res);
    if (column == 0)
    {
        printf("Результирующая матрица пустая!\n");
    }
    else if (column * line < 20)
    {
        print_array_f(str_res, column);
    }
    else
    {
        int first, count = 0, not_null_line = 0, elems = 0;
        int *columnss = malloc(column * sizeof(int));
        float *valuess = malloc(column * sizeof(float));
        list_t *liines = NULL;
        for (int i = 0; i < column; i++)
        {
            if (rounding(str_res[i], 6) != 0.000000)
            {
                elems++;
                columnss[count] = i;
                valuess[count] = str_res[i];
                count++;
            }
        }
        push(&liines, 0, 0);
        if (count == 0)
        {
            printf("Результирующая матрица пустая!\n");
        }
        else
        {
            printf("\n\nValues:\n");
            print_array_f(valuess, count);
            printf("\nColumns:\n");
            print_array_i(columnss, count);
            printf("\nLines: \n");
            print_from_tail(liines);
        }
    }


    for (int i = 0; i < line; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
    free(str);
    free(values);
    free(values_str);
    free(columns);
    free(columns_str);
}

