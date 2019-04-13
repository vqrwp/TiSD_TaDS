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
����ந�� ���, � ���設�� ���ண� ��室���� ᫮�� �� ⥪�⮢���
䠩��. �뢥�� ��� �� �࠭ � ���� ��ॢ�. �������஢��� ����祭���
��ॢ� � �뢥�� ��� �� �࠭. ����ந�� ��-⠡���� �� ᫮� ⥪�⮢���
䠩��. �ᯮ�짮���� ��⮤ 楯�祪 ��� ���࠭���� ��������. �����⢨��
���� ���������� ᫮�� � ���, � ᡠ����஢����� ��ॢ�, � ��-⠡��� �
� 䠩��. �ࠢ���� �६� ���᪠, ��ꥬ ����� � ������⢮ �ࠢ����� ��
�ᯮ�짮����� ࠧ����� (4-�) ������� ������. �᫨ ������⢮ �ࠢ�����
� ��-⠡��� ����� 㪠�������, � �ந����� �������ਧ��� ⠡����,
��ࠢ ����� �㭪��.
 */

int main()
{
    printf("��ਠ�� %d\n", 11 % 5);
    printf("����ந�� ���, � ���設�� ���ண� ��室���� ᫮�� �� ⥪�⮢���\n"
           "䠩��. �뢥�� ��� �� �࠭ � ���� ��ॢ�. �������஢��� ����祭���\n"
           "��ॢ� � �뢥�� ��� �� �࠭. ����ந�� ��-⠡���� �� ᫮� ⥪�⮢���\n"
           "䠩��. �ᯮ�짮���� ��⮤ 楯�祪 ��� ���࠭���� ��������. �����⢨��\n"
           "���� ���������� ᫮�� � ���, � ᡠ����஢����� ��ॢ�, � ��-⠡��� �\n"
           "� 䠩��. �ࠢ���� �६� ���᪠, ��ꥬ ����� � ������⢮ �ࠢ����� ��\n"
           "�ᯮ�짮����� ࠧ����� (4-�) ������� ������. �᫨ ������⢮ �ࠢ�����\n"
           "� ��-⠡��� ����� 㪠�������, � �ந����� �������ਧ��� ⠡����,\n"
           "��ࠢ ����� �㭪��.\n\n");
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
        printf("����: \n");
        printf("1) �������� ���筮� ��ॢ�\n");
        printf("2) �������� ᡠ����஢����� ��ॢ�\n");
        printf("3) ���� ᫮�� � ���\n");
        printf("4) ���� ᫮�� � ᡠ����஢����� ��ॢ�\n");
        printf("5) ����ந�� ���-⠡����\n");
        printf("6) �������� ���-⠡����\n");
        printf("7) ���� � ���-⠡���\n");
        printf("8) ���� � 䠩��\n");
        printf("9) ��䥪⨢�����\n");
        printf("0) ��室\n");
        printf("������ ����� �㭪� ����: ");
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
                puts("������ ᫮��:\n");
                scanf("%s", search_word);
                search_in_tree(root, search_word, &amount_ord, &flag_s);
                //search_bal(search_word, root, &done, &flag_s);
                if (flag_s != 1)
                {
                    puts("������ ᫮�� ���!\n");
                }
                if (flag_s == 1)
                {
                    //treeprint(root);
                    puts("����� ᫮�� ����!\n");
                }
                break;
            case 4:
                flag_s = 0; amount_bal = 0;
                puts("������ ᫮��:\n");
                scanf("%s", search_word);
                search_in_tree(balanced_root, search_word, &amount_bal, &flag_s);
                //printf("flag = %d", flag_s);
                if (flag_s != 1)
                {
                    puts("������ ᫮�� ���!\n");
                }
                if (flag_s == 1)
                {
                    puts("����� ᫮�� ����!\n");
                }
                break;
            case 5:
            {
                printf("������ ࠧ��� ���-⠡���� (楫�� �᫮): \n");
                int error = check_int(&table_len, -1, 1000);
                int copy = table_len;
                if (!error)
                {
                    f = fopen(FILENAME, "r+");
                    hash = create_table(f, &table_len);
                    fclose(f);
                    if (copy != table_len)
                    {
                        printf("���� ࠧ��� ���-⠡����: %d\n", table_len);
                    }
                }
                else
                {
                    printf("�訡�� �����!\n");
                }
                break;
            }
            case 6:
            {
                if (!hash)
                    printf("����� ⠡���\n");
                else
                {
                    printf("���-�������: \n");
                    print_table(hash, table_len);
                }
                break;
            }
            case 7:
            {
                if (table_len == 0)
                {
                    puts("���砫� ����ன� ⠡����!\n");
                }
                else
                {
                    flag_s = 0; amount_bal = 0;
                    puts("������ ᫮��:\n");
                    scanf("%s", search_word);
                    flag_s = search_in_hash(hash, search_word, table_len, &amount_hash);
                    //printf("flag = %d", flag_s);
                    if (flag_s != 1)
                    {
                        puts("������ ᫮�� ���!\n");
                    }
                    if (flag_s == 1)
                    {
                        puts("����� ᫮�� ����!\n");
                    }
                }
                break;
            }
            case 8:
            {
                flag_s = 0; amount_file = 0;
                puts("������ ᫮��:\n");
                scanf("%s", search_word);
                flag_s = search_in_file(f, search_word, &amount_file);
                if (flag_s != 1)
                {
                    puts("������ ᫮�� ���!\n");
                }
                if (flag_s == 1)
                {
                    puts("����� ᫮�� ����!\n");
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