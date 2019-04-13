//
// Created by Margo on 20.12.2018.
//

#include "efficiency.h"
#include "tree.h"
#include "read_file.h"
#include <time.h>
#include <stdlib.h>
#include "hash.h"
#include "balance.h"
#include "search.h"

unsigned long int tick(void)
{
    unsigned long int d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

void efficiency()
{
    FILE *f = fopen(EFFICIENCY, "r+");

    if (f)
    {
        tnode *root = NULL, *balanced_root = NULL;
        int table_len = 20, nodes = 0, nodes_bal = 0, flag = 0, amount_ord = 0,
                amount_bal = 0, amount_hash = 0, amount_file = 0;
        unsigned long long t_ord, t_bal, time_hash, t_file;
        t_hash **hash = NULL;
        int start = time(NULL);
        srand((unsigned int) start);

        root = read_file(f, root);
        balanced_root = read_file_balanced(balanced_root, f);
        hash = create_table(f, &table_len);
        count_node(root, &nodes);
        count_node(balanced_root, &nodes_bal);
        int node_hash = count_node_table(hash, table_len);
        //printf("%d %d\n", nodes, nodes_bal);

        clock_t t1, t2;
        t1 = tick();
        for (int i = 0; i < 1000; i++)
        {
            search_in_tree(root, "youthe", &amount_ord, &flag);
        }
        //printf("%d\n", flag);
        t2 = tick();
        t_ord = (unsigned long long)(t2 - t1) / 1000;

        t1 = tick();
        for (int i = 0; i < 1000; i++)
        {
            search_in_tree(balanced_root, "youthe", &amount_bal, &flag);
        }
        //printf("%d\n", flag);
        t2 = tick();
        t_bal = (unsigned long long)(t2 - t1) / 1000;

        t1 = tick();
        for (int i = 0; i < 1000; i++)
        {
            search_in_hash(hash, "youthe", table_len, &amount_hash);
        }
        t2 = tick();
        time_hash = (unsigned long long)(t2 - t1) / 1000;

        t1 = tick();
        for (int i = 0; i < 1000; i++)
        {
            search_in_file(f, "youthe", &amount_file);
        }
        t2 = tick();
        t_file = (unsigned long long) (t2 - t1) / 1000;

        //int memory_tree = count_node*((sizeof(char*))*3);
        //int memory_bal_tree = count_node*((sizeof(char*))*3 + sizeof(int));
        printf("|-----------------|       Файл    |    ДДП  |   АВЛ   |   ХЭШ   |\n");
        printf("|---------------------------------------------------------------|\n");
        printf("|Память (в байтах)|%15.2d|%9d|%9d|%9d|\n", 1181, nodes * sizeof(tnode) + 1181 - nodes * sizeof(int),
               nodes_bal * sizeof(tnode) + 1181,
               node_hash + 1181);
        printf("|---------------------------------------------------------------|\n");
        printf("|Время      (в mc)|%15lf|%9lf|%9lf|%9lf|\n", (double)t_file / CLOCKS_PER_SEC,
               (double)t_ord / CLOCKS_PER_SEC,
               (double)t_bal / CLOCKS_PER_SEC,  (double)time_hash / CLOCKS_PER_SEC);
        printf("|---------------------------------------------------------------|\n");
        printf("|Колич. сраввнений|%15d|%9d|%9d|%9d|\n", amount_file / 1000, amount_ord / 1000,
               amount_bal / 1000, amount_hash / 1000);
    }
    else
    {
        puts("Ошибка в открытии файла!\n");
    }

    fclose(f);
}