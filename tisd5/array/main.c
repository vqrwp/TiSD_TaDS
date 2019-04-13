#include "init_automat.h"
#include "queue.h"
#include "time.h"
#include <windows.h>
#include "constants.h"
#include <math.h>

int main()
{
    printf("�������: ��� 1-�� � 2-�� ⨯�� ����㯠�� � \"墮���\" ᢮�� ��।�� ��\n"
           "��砩���� ������ � ���ࢠ���� �६��� �1 � �2, ࠢ����୮\n"
           "��।�����묨 �� 1 �� 5 � �� 0 �� 3 ������ �६��� (�.�.) ᮮ⢥��⢥���.\n"
           "� �� ��� ����㯠�� �� \"������\" ��।� �� ����� � ���㦨������ ⠪��\n"
           "ࠢ������⭮ �� �६��� �3 � �4, ��।������ �� 0 �� 4 �.�. � �� 0 �� 1\n"
           "�.�. ᮮ⢥��⢥���, ��᫥ 祣� �������� ��⥬�. (�� �६��� ?\n"
           "����⢥����� ⨯�) � ��砫� ����� � ��⥬� ��� ���.\n"
           "��� 2-�� ⨯� ����� ���� � ��, �᫨ � ��⥬� ��� ��� 1-�� ⨯�.\n"
           "�᫨ � ������ ���㦨����� ��� 2-�� ⨯� � ������ ��।� �室�� ���\n"
           "1-�� ⨯�, � ��� ���������� ����㯠�� �� ���㦨�����; ��ࠡ�⪠ ��� 2-\n"
           "�� ⨯� ���뢠���� � ��� �����頥��� � \"墮��\" ᢮�� ��।� (��⥬� �\n"
           "��᮫��� �ਮ��⮬ � ������ ���㦨������).\n\n");
    printf("�������஢��� ����� ���㦨����� ����� 1000 ��� 1-�� ⨯�,\n"
           "�뤠��� ��᫥ ���㦨����� ������ 100 ��� 1-�� ⨯� ���ଠ�� �\n"
           "⥪�饩 � �।��� ����� ������ ��।�, � � ���� ����� - ��饥 �६�\n"
           "������஢���� � ������⢥ ��襤�� � ��⥬� � ��襤�� �� ��� ���\n"
           "����� ⨯��, �।��� �६��� �ॡ뢠��� ��� � ��।�, ������⢥\n"
           "?���襭���? ��� ��ண� ⨯�. ���ᯥ��� �� �ॡ������ ���짮��⥫�\n"
           "�뤠�� �� �࠭ ���ᮢ ����⮢ ��।� �� 㤠����� � ����������\n"
           "����⮢. ��᫥����, ��������� �� �� �⮬ �ࠣ������ �����.\n\n\n");
    automat *a;
    queue_t *q1 = new_queue(ELEM, T1), *q2 = new_queue(ELEM, T2);
    a = init_auto();
    int len1 = 0, len2 = 0, j = 1;
    float stay1 = 0, stay2 = 0, t = 0, i = 0;
    double error;
    double duration = 0;
    clock_t t1, t2;

    srand((unsigned int) time(NULL));
    printf("|--------------������ ������----------------|\n\n\n");
    printf("|--------------�������������----------------|\n\n");
    while (a->left1 < TIME)
    {
        t1 = clock();
        t = get_time(q1, q2, a);
        t2 = clock();
        if (t == 0)
        {
            return 0;
        }
        duration = duration + (double) (t2 - t1) / CLOCKS_PER_SEC;

        if (a->left1 % MOD == 0 && i != a->left1)
        {
            i = a->left1;
            len1 += q1->num_of_elems;
            len2 += q2->num_of_elems;
            stay1 += q1->data_store[q1->front];
            stay2 += q2->data_store[q2->front];
            printf("|--------------�������������----------------|\n");
            printf("|����饥 �६�: %28.3f|\n", t);
            j++;
            printf("|������ ����� ��ࢮ� ��।�: %14d|\n"
                   "|������ ����� ��ன ��।�: %14d|\n", q1->num_of_elems, q2->num_of_elems);
            printf("|�।��� ����� ��ࢮ� ��।�:  %12d|\n", len1 /j);
            printf("|�।��� ����� ��ன ��।�:  %12d|\n", len2 /j);
            printf("|�।��� �६� ����� ��ࢮ� ��।�:  %.2f|\n", stay1 /j);
            printf("|�।��� �६� ����� ��ன ��।�:  %.2f|\n", stay2 /j);
            printf("|-------------------------------------------|\n");

        }
    }
    double t1min = T1_MIN, t1max = T1_MAX, t2min = T2_MIN, t2max = T2_MAX, t3min = T3_MIN, t3max = T3_MAX,
            t4min = T4_MIN, t4max = T4_MAX;
    double av_t_in1 = (t1min + t1max) / 2, av_t_out1 = (t3min + t3max) / 2, av_t_in2 = (t2max + t2min) / 2,
            av_t_out2 = (t4min + t4max) / 2;

    printf("%lf %lf %lf %lf\n", av_t_in1, av_t_out1, av_t_in2, av_t_out2);
    double total_t_in1 = TIME * av_t_in1;
    double total_t_out1 = TIME * av_t_out1;
    double amount = total_t_in1 / av_t_in2;
    double total_t_in2 = amount * av_t_in2;
    double total_t_out2 = amount * av_t_out2;// + total_t_in2;
    double total_in;
    if (av_t_in2 < av_t_out1)
    {
        total_in = total_t_in1 + total_t_in2;
    }
    else
    {
        total_in = total_t_in1;
    }
    double total_out = total_t_out1 + total_t_out2, t_modelling1;


    printf("�।��� �६� ��室� ��ࢮ� %f ��ன %f\n"
           "�।��� �६� ��ࠡ�⪨ ��ࢮ� %f ��ன %f\n", av_t_in1, av_t_in2, av_t_out1, av_t_out2);
    t_modelling1 = fmax(total_t_in1, total_t_out1);

    printf("\n\n|----------------�������� ���������-------------------|\n"
           "|�६� ������஢����: %32f|\n"
           "|�६� ࠡ��� ��: %36f|\n"
           "|�६� �����: %38f|\n"
           "|������⢮ ���, ��������� � ����� ��।�: %6d|\n"
           "|������⢮ ���, ��������� �� ����� ��।�: %5d|\n"
           "|������⢮ ��ࠡ�⠭��� ��� �� ��ࢮ� ��।�:%3d|\n"
           "|������⢮ ��ࠡ�⠭��� ��� �� ��ன ��।�: %3d|\n"
           "|������⢮ ���襭��� ��� �� ��ன ��।�: %4d|\n"
           "����⭮� �६� ������஢���� ��� ��ࢮ� ��।� �� �室�: %.3f\n"
           "����⭮� �६� ������஢���� ��� ��ன ��।� �� �室�: %.3f\n"
           "����⭮� �६� ������஢���� ��� ��ࢮ� ��।� �� ��室�: %.3f\n"
           "����⭮� �६� ������஢���� ��� ��ன ��।� �� ��室�: %.3f\n"
           "�業�筮� �६� ������஢����: %.3f\n\n", t, a->work, a->downtime,
            q1->summ_of_elems, q2->summ_of_elems,
           //a->left1,
           a->left1, a->left2, q2->summ_of_elems - a->left2,
           total_t_in1, total_t_in2,
           total_t_out1, total_t_out2, t_modelling1);
    printf("�ࠢ������ �業�筮� �६� � ����稢訬�� � १���� ࠡ��� �ணࠬ��\n...\n\n\n"
           "�஢�ઠ �ࠢ��쭮�� ࠡ��� ��⥬� �� �室�\n...\n\n");

    double appl1 = t / av_t_in1, appl2 = t / av_t_in2;
    //printf("%f %f %lf %lf\n", t, av_t_in1, appl1, appl2);
    error = fabs(((t - t_modelling1) / t_modelling1) * 100);
    double error1 = fabs(((q1->summ_of_elems - appl1) / appl1) * 100);
    double error2 = fabs(((q2->summ_of_elems - appl2) / appl2) * 100);

    printf("��業� ࠧ���� �業���� ����७�� � ॠ����: %lf %%.\n", error);
    printf("��業� ࠧ���� �業���� ����७�� � ॠ���� �� �室�, 1 ��।�: %lf %%.\n", error1);
    printf("��業� ࠧ���� �業���� ����७�� � ॠ���� �� �室�, 2 ��।�: %lf %%.\n\n", error2);

    printf("�ᯮ�짮������ ������: %d \n", sizeof(queue_t) * 2 + sizeof(automat) + ELEM * 2 * sizeof(float));
    printf("���⥫쭮���: %lf\n", duration);
    queue_free(q1);
    queue_free(q2);
    return 0;
}