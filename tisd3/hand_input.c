//
// Created by Margo on 04.11.2018.
//
#include "headers.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_float(float *x, float *y)
{
    float tmp = *x;
    *x = *y;
    *y = tmp;
}


void bubble_sort(int *array, int *array1, float *array2, int elems)
{
    int i = 0;
    char swap_cnt = 0;
    while (i < elems)
    {
        if (i + 1 != elems && array[i] > array[i + 1])
        {
            swap_int(&array[i], &array[i + 1]);
            swap_int(&array1[i], &array1[i + 1]);
            swap_float(&array2[i], &array2[i + 1]);
            swap_cnt = 1;
        }
        i++;
        if (i == elems && swap_cnt == 1)
        {
            swap_cnt = 0;
            i = 0;
        }
    }
}

int hand_input_mtr(float *values, int *columns, list_t **lines, int line, int column, int *not_null_lines)
{
    int num_elems = line * column;
    int elems = 0;
    printf("Введите количество ненулевых элементов матрицы: \n");
    while (elems <= 0 || elems > num_elems)
    {
        printf("Оно должно быть больше 0, но меньше заданного размера матрицы:  ");
        scan_int(&elems);
    }
    int *liines = (int*)malloc(elems * sizeof(int));
    for (int i = 0; i < elems; i++)
    {
        liines[i] = line;
    }
    for (int i = 0; i < elems; i++)
    {
        columns[i] = column;
        values[i] = 0.0;
    }
    float **mtr = (float**)calloc((size_t) (line * column), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = (float*)calloc((size_t)column, sizeof(float));
    }
    printf("Вам предстоит ввести %d тройки значений, первое из которых вещественное:\n"
           "это элемент матрицы, второе и третье - целые, это номер столбца и строки матрицы.\n", elems);
    for (int i = 0; i < elems; i++)
    {
        values[i] = 0.000000;
        columns[i] = column;
        liines[i] = line;
        while (1)
        {
            printf("Введите значение:\n");
            scan_float(&values[i]);
            if (rounding(values[i], 6) != 0.000000)
            {
                break;
            }
        }
        while (columns[i] >= column || columns[i] < 0)
        {
            printf("Введите номер столбца с 0 до %d:\n", column - 1);
            scan_int(&columns[i]);
        }
        while (liines[i] >= line || liines[i] < 0)
        {
            printf("Введите номер строки с 0 do %d:\n", line - 1);
            scan_int(&liines[i]);
        }
        if (rounding(mtr[liines[i]][columns[i]], 6) == 0.000000)
        {
            printf("Успешно!\n");
            mtr[liines[i]][columns[i]] = values[i];
        }
        else
        {
            printf("Эта ячейка уже занята, попробуйте еще раз!");
            i -= 1;
        }
    }
    if (line < 10 && column < 10)
    {
        print_mtr(mtr, line, column);
    }
    bubble_sort(liines, columns, values, elems);
    int first, count = 0;
     for (int i = 0; i < line; i++)
     {
         first = -1;
         for (int j = 0; j < column; j++)
         {
             if (rounding(mtr[i][j], 6) != 0.000000)
             {
                 count++;
                 for (int k = 0; k < elems; k++)
                 {
                     if (columns[k] == j && liines[k] == i && first == -1)
                     {
                         first = count - 1;
                         break;
                     }
                 }
             }
         }
         if (first != -1)
         {
             push(lines, i, first);
             *not_null_lines += 1;
         }
     }
    for (int i = 0; i < elems; i++)
    {
        //printf("%f %d\n", values[i], columns[i]);
    }
    //printf("\n");
    //print_from_tail(lines);
    for (int i = 0; i < line; i++)
    {
        free(mtr[i]);
    }
    free(liines);
    free(mtr);
    return elems;
}

int hand_input_str(float *values, int *columns, list_t **lines, int line, int column)
{
    int *liines = (int*)malloc(column * sizeof(int));
    for (int i = 0; i < column; i++)
    {
        liines[i] = line;
    }
    for (int i = 0; i < column; i++)
    {
        columns[i] = column;
        values[i] = 0.0;
    }
    float **mtr = (float**)calloc((size_t) (line * column), sizeof(float));
    for (int i = 0; i < line; i++)
    {
        mtr[i] = (float*)calloc((size_t)column, sizeof(float));
    }
    int tmp = column;
    column = 0;
    printf("Введите количество ненулевых элементов матрицы: \n");
    while (column <= 0 || column > tmp)
    {
        printf("Введите значение меньше %d:\n", tmp + 1);
        scan_int(&column);
    }
    printf("Вам предстоит ввести %d тройки значений, первое из которых вещественное:\n"
           "это элемент матрицы, второе и третье - целые, это номер столбца и строки матрицы.\n", column);
    for (int i = 0; i < column; i++)
    {
        values[i] = 0.000000;
        columns[i] = -1;
        liines[i] = line;
        while (1)
        {
            printf("Введите значение:\n");
            scan_float(&values[i]);
            if (rounding(values[i], 6) != 0.000000)
            {
                break;
            }
        }
        while (columns[i] >= tmp || columns[i] < 0)
        {
            printf("Введите номер столбца с 0 до %d:\n", tmp - 1);
            scan_int(&columns[i]);
        }
        liines[i] = 0;
        if (rounding(mtr[liines[i]][columns[i]], 6) == 0.000000)
        {
            printf("Успешно!\n");
            mtr[liines[i]][columns[i]] = values[i];
        }
        else
        {
            printf("Эта ячейка уже занята, попробуйте еще раз!");
            i -= 1;
        }
    }
    if (line < 10 && tmp < 10)
    {
        print_mtr(mtr, line, tmp);
    }
    bubble_sort(liines, columns, values, column);
    int first, count = 0;
    for (int i = 0; i < line; i++)
    {
        first = -1;
        for (int j = 0; j < column; j++)
        {
            if (rounding(mtr[i][j], 6) != 0.000000)
            {
                count++;
                for (int k = 0; k < column; k++)
                {
                    if (columns[k] == j && liines[k] == i && first == -1)
                    {
                        first = count - 1;
                        break;
                    }
                }
            }
        }
        if (first != -1)
        {
            push(lines, i, first);
        }
    }
    for (int i = 0; i < column; i++)
    {
        //printf("%f %d\n", values[i], columns[i]);
    }
    //printf("\n");
    //print_from_tail((const list_t *) lines);
    for (int i = 0; i < line; i++)
    {
        free(mtr[i]);
    }
    free(mtr);
    free(liines);
    return column;
}