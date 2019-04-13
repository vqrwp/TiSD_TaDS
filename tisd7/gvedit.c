#include "gvedit.h"


void show_matr_gv(const mtr_t *a)
{
    if (a == NULL)
    {
        return;
    }
    FILE *f = fopen("output.gv", "w");
    fprintf(f, "digraph My_graph {\n");
    for (int i = 0; i < a->size; i++)
    {
        for (int j = 0; j < a->size; j++)
        {
            if (a->data[i][j] < INFINIT && a->data[i][j] != 0)
                fprintf(f, "%d -> %d [label=\"%d km\"];\n", i, j, a->data[i][j]);
        }
    }
    fprintf(f, "}\n");
    fclose(f);
    system("output.gv");
}

void show_best_gv(const mtr_t *a, const mtr_t *not_best)
{
    if (a == NULL)
        return;
    FILE *f = fopen("output_best.gv", "w");
    fprintf(f, "digraph My_graph {\n");
    for (int i = 0; i < a->size; i++)
        for (int j = 0; j < a->size; j++)
        {
            if (a->data[i][j] < INFINIT && a->data[i][j] != 0 && a->data[i][j] >= not_best->data[i][j])
                fprintf(f, "%d -> %d [label=\"%d km\"];\n", i, j, a->data[i][j]);
        }
    fprintf(f, "}\n");
    fclose(f);
    system("output_best.gv");
}
