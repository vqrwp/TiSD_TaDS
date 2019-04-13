#include "time_search.h"
#include "mtr_funcs.h"
#include "gvedit.h"
#include "scan_int.h"

/*
Задана система двусторонних дорог. Для
        каждой пары городов найти длину кратчайшего
        пути между ними.
*/

int main(void)
{
    FILE *fin = fopen(FILENAME, "r");
    unsigned long long t1, t2;

    int menu = 0, flag = 1;
    mtr_t *graph = read_mtr(fin);
    if (graph == NULL)
    {
        return 0;
    }
    mtr_t *best = NULL;
    while (flag)
    {
        puts("\nМЕНЮ:");
        puts("1) Показать граф");
        puts("2) Вывести информацию о построении наиболее "
             "коротких маршрутов, построить их");
        puts("3) Показать матрицу графа");
        puts("4) Показать матрицу лучших маршрутов");
        puts("5) Показать граф лучших маршрутов");
        puts("6) Выход");
        menu = scan_int();
        switch (menu)
        {
            case 1:
                show_matr_gv(graph);
                break;
            case 2:
                create_mtr(best);
                t1 = tick();
                best = floyd_warshall(graph);
                t2 = tick();
                printf("Время вычисления: %d ms\n", (int) (t2 - t1) / CLOCKS_PER_SEC);
                printf("Обьем, занимаемый графом: %d bytes\n", sizeof(int) * best->size
                                                               * best->size + sizeof(unsigned int));
                break;
            case 3:
                print_mtr(stdout, graph);
                break;
            case 4:
                print_mtr(stdout, best);
                break;
            case 5:
                show_best_gv(best, graph);
                break;
            case 6:
                flag = 0;
                break;
            default:
                puts("Неверный ввод.");
                break;
        }
    }

    create_mtr(graph);
    create_mtr(best);
    fclose(fin);
    return 0;
}