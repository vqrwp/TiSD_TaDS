//
// Created by Margo on 05.11.2018.
//

#include <stdio.h>

void print_mtr(float **mtr, int line, int column)
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%f ", mtr[i][j]);
        }
        printf("\n");
    }
}

void print_array_f(float *array, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%f ", array[i]);
    }
}

void print_array_i(int *array, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%10d ", array[i]);
    }
}