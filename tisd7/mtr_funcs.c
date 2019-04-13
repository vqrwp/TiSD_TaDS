#include "mtr_funcs.h"

mtr_t *read_mtr(FILE *f)
{
    rewind(f);
    unsigned int n;
    if (fscanf(f, "%u", &n) != 1)
    {
        printf("Ошибка в считывании файла!\n");
        return NULL;
    }
    mtr_t *res = create_matr(n);
    int tmp = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(f, "%d", &tmp) != 1)
            {
                printf("Ошибка в считывании файла!\n");
                return NULL;
            }
            res->data[i][j] = tmp;
        }
    }
    return res;
}

void print_mtr(FILE *f, const mtr_t *mtr)
{
    if (mtr != NULL)
    {
        fprintf(f, " ");
        for (int i = 0; i < mtr->size; i++)
        {
            fprintf(f, " %5d", i);
        }
        fprintf(f, "\n---");
        for (int i = 0; i <= mtr->size * 5; i++)
        {
            fprintf(f, "-");
        }
        putc('\n', f);
        for (int i = 0; i < mtr->size; i++)
        {
            fprintf(f, "%d|", i);
            for (int j = 0; j < mtr->size; j++)
            {
                fprintf(f, "%5d ", mtr->data[i][j]);
            }
            putc('\n', f);
        }
    }
    else
        fprintf(f, "Она пустая!\n");
}

void create_mtr(mtr_t *matrix)
{
    if (matrix != NULL)
    {
        free_matrix_rows(matrix->data, matrix->size);
        free(matrix);
    }
}

mtr_t *copy_matr(const mtr_t *A)
{
    if (A != NULL)
    {
        mtr_t *C = create_matr(A->size);

        C->size = A->size;
        C->size = A->size;
        for (int i = 0; i < A->size; ++i)
            for (int j = 0; j < A->size; ++j)
                C->data[i][j] = A->data[i][j];
        return C;
    }
    else
    {
        return NULL;
    }
}



void free_matrix_rows(int **data, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(data[i]);
    }

    free(data);
}

int **allocate_matrix_rows(size_t n)
{
    size_t m = n;
    int **data = calloc(n, sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        data[i] = calloc(m, sizeof(int));
    }

    return data;
}

mtr_t *create_matr(unsigned int n)
{
    mtr_t *res = malloc(sizeof(mtr_t));
    res->data = allocate_matrix_rows(n);
    res->size = n;
    return res;
}


mtr_t *floyd_warshall(const mtr_t *mtr)
{
    mtr_t *res = copy_matr(mtr);
    for (int k = 0; k < mtr->size; k++)
    {
        for (int i = 0; i < mtr->size; i++)
        {
            for (int j = 0; j < mtr->size; j++)
            {
                if (i != j)
                {
                    if (res->data[i][j] > res->data[i][k] + res->data[k][j])
                    {
                        res->data[i][j] = res->data[i][k] + res->data[k][j];
                    }
                }
                else
                {
                    res->data[i][j] = 0;
                }
            }
        }
    }
    return res;
}