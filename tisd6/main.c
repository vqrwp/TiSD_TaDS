#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "export.h"
#include "read_file.h"
#include "balance.h"
#include "hash.h"
#include "efficiency.h"
#include "search.h"

/*
Построить ДДП, в вершинах которого находятся слова из текстового
файла. Вывести его на экран в виде дерева. Сбалансировать полученное
дерево и вывести его на экран. Построить хеш-таблицу из слов текстового
файла. Использовать метод цепочек для устранения коллизий. Осуществить
поиск введенного слова в ДДП, в сбалансированном дереве, в хеш-таблице и
в файле. Сравнить время поиска, объем памяти и количество сравнений при
использовании различных (4-х) структур данных. Если количество сравнений
в хеш-таблице больше указанного, то произвести реструктуризацию таблицы,
выбрав другую функцию.
 */

int main()
{
    printf("Вариант %d\n", 11 % 5);
    printf("Построить ДДП, в вершинах которого находятся слова из текстового\n"
           "файла. Вывести его на экран в виде дерева. Сбалансировать полученное\n"
           "дерево и вывести его на экран. Построить хеш-таблицу из слов текстового\n"
           "файла. Использовать метод цепочек для устранения коллизий. Осуществить\n"
           "поиск введенного слова в ДДП, в сбалансированном дереве, в хеш-таблице и\n"
           "в файле. Сравнить время поиска, объем памяти и количество сравнений при\n"
           "использовании различных (4-х) структур данных. Если количество сравнений\n"
           "в хеш-таблице больше указанного, то произвести реструктуризацию таблицы,\n"
           "выбрав другую функцию.\n\n");
    FILE *f = fopen(FILENAME, "r+");
    tnode *root = NULL, *balanced_root = NULL;

    t_hash **hash = NULL;
    root = read_file(f, root);
    balanced_root = read_file_balanced(balanced_root, f);

    int flag = 1, table_len = 0, flag_s = 0, amount_ord = 0,
            amount_bal = 0, amount_hash = 0, amount_file = 0;
    char search_word[100];

    while (flag)
    {
        printf("Меню: \n");
        printf("1) Напечатать обычное дерево\n");
        printf("2) Напечатать сбалансированное дерево\n");
        printf("3) Поиск слова в ДДП\n");
        printf("4) Поиск слова в сбалансированном дереве\n");
        printf("5) Построить хэш-таблицу\n");
        printf("6) Напечатать хэш-таблицу\n");
        printf("7) Поиск в хэш-таблице\n");
        printf("8) Поиск в файле\n");
        printf("9) Эффективность\n");
        printf("0) Выход\n");
        printf("Введите номер пункта меню: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                FILE *fout_ord = fopen("output_ord.gv", "w+");
                export_to_dot(fout_ord, "My_tree", root);
                fclose(fout_ord);
                break;
            }
            case 2:
            {
                FILE *fout_bal = fopen("output_bal.gv", "w+");
                export_to_dot(fout_bal, "My_tree", balanced_root);
                fclose(fout_bal);
                break;
            }
            case 3:
                flag_s = 0; amount_ord = 0;
                puts("Введите слово:\n");
                scanf("%s", search_word);
                search_in_tree(root, search_word, &amount_ord, &flag_s);
                //search_bal(search_word, root, &done, &flag_s);
                if (flag_s != 1)
                {
                    puts("Такого слова нет!\n");
                }
                if (flag_s == 1)
                {
                    //treeprint(root);
                    puts("Такое слово есть!\n");
                }
                break;
            case 4:
                flag_s = 0; amount_bal = 0;
                puts("Введите слово:\n");
                scanf("%s", search_word);
                search_in_tree(balanced_root, search_word, &amount_bal, &flag_s);
                //printf("flag = %d", flag_s);
                if (flag_s != 1)
                {
                    puts("Такого слова нет!\n");
                }
                if (flag_s == 1)
                {
                    puts("Такое слово есть!\n");
                }
                break;
            case 5:
            {
                printf("Введите размер хэш-таблицы (целое число): \n");
                int error = check_int(&table_len, -1, 1000);
                int copy = table_len;
                if (!error)
                {
                    f = fopen(FILENAME, "r+");
                    hash = create_table(f, &table_len);
                    fclose(f);
                    if (copy != table_len)
                    {
                        printf("Новый размер хэш-таблицы: %d\n", table_len);
                    }
                }
                else
                {
                    printf("Ошибка ввода!\n");
                }
                break;
            }
            case 6:
            {
                if (!hash)
                    printf("Пустая таблица\n");
                else
                {
                    printf("ХЭШ-ТАБЛИЦА: \n");
                    print_table(hash, table_len);
                }
                break;
            }
            case 7:
            {
                if (table_len == 0)
                {
                    puts("Сначала постройте таблицу!\n");
                }
                else
                {
                    flag_s = 0; amount_bal = 0;
                    puts("Введите слово:\n");
                    scanf("%s", search_word);
                    flag_s = search_in_hash(hash, search_word, table_len, &amount_hash);
                    //printf("flag = %d", flag_s);
                    if (flag_s != 1)
                    {
                        puts("Такого слова нет!\n");
                    }
                    if (flag_s == 1)
                    {
                        puts("Такое слово есть!\n");
                    }
                }
                break;
            }
            case 8:
            {
                flag_s = 0; amount_file = 0;
                puts("Введите слово:\n");
                scanf("%s", search_word);
                flag_s = search_in_file(f, search_word, &amount_file);
                if (flag_s != 1)
                {
                    puts("Такого слова нет!\n");
                }
                if (flag_s == 1)
                {
                    puts("Такое слово есть!\n");
                }
                break;
            }
            case 9:
            {
                efficiency();
                break;
            }
            case 0:
            {
                flag = 0;
                break;
            }

            default:
                break;
        }
    }

    //treeprint(root);
    fclose(f);
    freemem(root);

    return 0;
}