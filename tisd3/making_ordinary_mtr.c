//
// Created by Margo on 09.11.2018.
//
#include "headers.h"
#include <stdio.h>

float **making_ord_mtr1(float **mtr, list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                       int elems, int line, int column, int not_null_lines)
{
    list_t *key = lines_mtr;
    int count = 0, count_2 = 0;
    int i = elems - 1;
    for (int j; count_2 < not_null_lines; count_2++)
    {
        if (count_2 != 0)
        {
            key = key->next;
        }
        if (key->next)
        {
            j = key->num_line;
            count = key->first_in_line;
        }
        else
        {
            j = key->num_line;
            count = 0;
        }
        while (i >= count)
        {
            mtr[j][columns_mtr[i]] = values_mtr[i];
            i--;
        }
    }
    return mtr;
}

float **making_ord_mtr(float **mtr, list_t *lines_mtr, const int *columns_mtr, const float *values_mtr,
                   int elems, int line, int column, int not_null_lines)
{
    list_t *key = lines_mtr;
    int count = 0, count_2 = 0;
    int i = elems - 1;
    for (int j; count_2 < not_null_lines; count_2++)
    {
        if (count_2 != 0)
        {
            key = key->next;
        }
        if (key->next)
        {
            j = key->num_line;
            count = key->first_in_line;
        }
        else
        {
            j = key->num_line;
            count = 0;
        }
        while (i >= count)
        {
            mtr[j][columns_mtr[i]] = values_mtr[i];
            i--;
        }
    }
    return mtr;
}

float *making_ord_vec(float *vec, const int *columns_vec, const float *values_vec, int elems)
{
    int i = 0;
    while (i < elems)
    {
        vec[columns_vec[i]] = values_vec[i];
        i++;
    }
    return vec;
}