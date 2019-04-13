#ifndef TISD7_MATR_H
#define TISD7_MATR_H

#include <malloc.h>
#include <stdio.h>
#include <math.h>
#define INFINIT 10000
#define FILENAME "input_1.txt"

typedef struct matrix_t
{
    unsigned int size;            // The number of columns
    int **data;
}mtr_t;

mtr_t *floyd_warshall(const mtr_t *mtr);
mtr_t *create_matr(unsigned int n);
void create_mtr(mtr_t *matrix);
mtr_t *read_mtr(FILE *f);
void print_mtr(FILE *f, const mtr_t *mtr);
void free_matrix_rows(int **data, int n);
int **allocate_matrix_rows(size_t n);
mtr_t *copy_matr(const mtr_t *A);

#endif //TISD7_MATR_H
