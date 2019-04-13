#include "init_automat.h"
#include "queue.h"
#include "time.h"
#include <math.h>
#include <time.h>
#include "constants.h"
//#define CHECK_FRAGMENTATION

int main()
{
    printf("УСЛОВИЕ: Заявки 1-го и 2-го типов поступают в \"хвосты\" своих очередей по\n"
           "случайному закону с интервалами времени Т1 и Т2, равномерно\n"
           "распределенными от 1 до 5 и от 0 до 3 единиц времени (е.в.) соответственно.\n"
           "В ОА они поступают из \"головы\" очереди по одной и обслуживаются также\n"
           "равновероятно за времена Т3 и Т4, распределенные от 0 до 4 е.в. и от 0 до 1\n"
           "е.в. соответственно, после чего покидают систему. (Все времена ?\n"
           "вещественного типа) В начале процесса в системе заявок нет.\n"
           "Заявка 2-го типа может войти в ОА, если в системе нет заявок 1-го типа.\n"
           "Если в момент обслуживания заявки 2-го типа в пустую очередь входит заявка\n"
           "1-го типа, то она немедленно поступает на обслуживание; обработка заявки 2-\n"
           "го типа прерывается и она возвращается в \"хвост\" своей очереди (система с\n"
           "абсолютным приоритетом и повторным обслуживанием).\n\n");
    printf("Смоделировать процесс обслуживания первых 1000 заявок 1-го типа,\n"
           "выдавая после обслуживания каждых 100 заявок 1-го типа информацию о\n"
           "текущей и средней длине каждой очереди, а в конце процесса - общее время\n"
           "моделирования и количестве вошедших в систему и вышедших из нее заявок\n"
           "обоих типов, среднем времени пребывания заявок в очереди, количестве\n"
           "?выброшенных? заявок второго типа. Обеспечить по требованию пользователя\n"
           "выдачу на экран адресов элементов очереди при удалении и добавлении\n"
           "элементов. Проследить, возникает ли при этом фрагментация памяти.\n\n\n");
    automat *a;
    srand((unsigned int) time(NULL));
    queue_t *q1 = init_queue(), *q2 = init_queue();
    a = init_auto();
#ifdef CHECK_FRAGMENTATION
    printf("|----ПРОВЕРЯЕМ ФРАГМЕНТИРОВАНИЕ------|\n\n");
#endif
    int len1 = 0, len2 = 0, j = 1;
    float stay1 = 0, stay2 = 0, t = 0, i = 0;
    double error, duration = 0;

    while (a->left1 <= TIME)
    {
        double t1 = clock();
        t = get_time(q1, q2, a);
        double t2 = clock();

        duration = duration + (double) (t2 - t1) / CLOCKS_PER_SEC;
        if (a->left1 % 100 == 0 && i != a->left1)
        {
            i = a->left1;
            len1 += q1->num_of_elems;
            len2 += q2->num_of_elems;
            stay1 += q1->pout->time;
            stay2 += q2->pout->time;
            printf("|------------Промежуточное № %2d------------|\n", j);
            printf("|Текущее время: %28.3f|\n", t);
            j++;
            printf("|Теперь длина первой очереди: %14d|\n"
                   "|Теперь длина второй очереди: %14d|\n", q1->num_of_elems, q2->num_of_elems);
            printf("|Средняя длина первой очереди:  %12d|\n", len1 / j);
            printf("|Средняя длина второй очереди:  %12d|\n", len2 / j);
            printf("|Среднее время простоя первой очереди:  %2.2f|\n", stay1 / j);
            printf("|Среднее время простоя первой очереди:  %2.2f|\n", stay2 / j);
            printf("|-------------------------------------------|\n");

        }
    }

    double t1min = T1_MIN, t1max = T1_MAX, t2min = T2_MIN, t2max = T2_MAX, t3min = T3_MIN, t3max = T3_MAX,
            t4min = T4_MIN, t4max = T4_MAX;
    double av_t_in1 = (t1min + t1max) / 2, av_t_out1 = (t3min + t3max) / 2, av_t_in2 = (t2max + t2min) / 2,
            av_t_out2 = (t4min + t4max) / 2;

    double total_t_in1 = TIME * av_t_in1;
    double total_t_out1 = TIME * av_t_out1;
    double amount = total_t_in1 / av_t_in2;
    printf("Ожидаемое среднее количество заявок второго типа %lf\n", amount);
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

    printf("Среднее время прихода первой %f второй %f\n"
           "Среднее время обработки первой %f второй %f\n", av_t_in1, av_t_in2, av_t_out1, av_t_out2);
    if (av_t_in1 + av_t_in2 > av_t_out1 + av_t_out2)
    {
        printf("here1\n");
        t_modelling1 = total_in;
    }
    else
    {
        printf("here2\n");
        t_modelling1 = total_out;
    }
    t_modelling1 = fmax(total_t_in1, total_t_out1);


    printf("\n\n|----------------Итоговый результат-------------------|\n\n"
           "Время моделирования: %f\n"
           "Время работы ОА: %f\n"
           "Время простоя ОА: %f\n"
           "Количество вошедших заявок первой очереди: %d\n"
           "Количество вошедших заявок второй очереди: %d\n"
           "Количество обработанных заявок первой очереди: %d\n"
           "Количество обработанных заявок второй очереди: %d\n"
           "Количество выброшенных заявок во второй очереди: %d\n"
           "Расчетное время моделирования на входе: %.3f\n"
           //"Расчетное время моделирования для второй очереди на входе: %.3f\n"
           "Расчетное время моделирования для первой очереди на выходе: %.3f\n"
           "Расчетное время моделирования для второй очереди на выходе: %.3f\n"
           "Оценочное время моделирования: %.3f\n\n", t,  a->work, a->downtime,
           q1->summ_of_elems,  q2->summ_of_elems, q1->summ_of_elems - q1->num_of_elems,
           a->left2, q2->num_of_elems, total_t_in1, //total_t_in2,
           total_t_out1, total_t_out2, t_modelling1);
    printf("Сравниваем оценочное время с получившимся в результате работы программы\n...\n\n\n"
           "Проверка правильности работы системы на входе\n...\n\n");

    double appl1 = t / av_t_in1, appl2 = t / av_t_in2;
    //printf("%f %f %lf %lf\n", t, av_t_in1, appl1, appl2);
    error = fabs(((t - t_modelling1) / t_modelling1) * 100);
    double error1 = fabs(((q1->summ_of_elems - appl1) / appl1) * 100);
    double error2 = fabs(((q2->summ_of_elems - appl2) / appl2) * 100);

    printf("Процент различия оценочных измерений и реальных: %lf %%.\n", error);
    printf("Процент различия оценочных измерений и реальных по входу, 1 очередь: %lf %%.\n", error1);
    printf("Процент различия оценочных измерений и реальных по входу, 2 очередь: %lf %%.\n\n", error2);

    printf("Использованная память: %d \n", sizeof(queue_t) * 2 + sizeof(automat) +
                                 sizeof(node_t) * q1->summ_of_elems + sizeof(node_t) * q2->summ_of_elems);
    printf("\nДлительноссть: %lf", duration);

    //DestroyQueue(q1);
    //DestroyQueue(q2);
    return 0;

}