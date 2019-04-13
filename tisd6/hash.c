#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include"hash.h"


int len_list(t_hash *head)
{
    int len = 0;
    for ( ; head; head = head->next)
    {
        len++;
    }
    return len;
}

int next_prime_number(int number)
{
    while (1)
    {
        int count_del = 0;
        number++;
        for (int i = 2; i < number - 1; i++)
        {
            if (!(number % i))
            {
                count_del++;
            }
        }

        if (!count_del)
        {
            return number;
        }
    }
}
t_hash* add_end(t_hash *head, t_hash *elem)
{
    t_hash *cur = head;
    if (!head)
    {
        return elem;
    }
    for (; cur->next; cur = cur->next)
    {
        //printf("%s %s\n", cur->word, elem->word);
        if (!strcmp(cur->word, elem->word))
        {
            return head;
        }
    }
    if (!strcmp(cur->word, elem->word))
    {
        return head;
    }
    cur->next = elem;
    return head;
}

t_hash* create_hash_node(char *word)
{
    t_hash *node = malloc(sizeof(t_hash));

    if (node && word)
    {
        strcpy(node->word, word);
        node->next = NULL;
    }

    return node;
}

int what_index(char *word, int len_table)
{
    int len = strlen(word);
    //int cur_step = 1;
    int sum = 0;
    for (int i = len - 1; i > -1; i--)
    {
        sum += (word[i] - 96);
        //sum += cur_step*(word[i] - OFFSET);
        //cur_step *= LEN_ALPH;
    }
    //int i = sum%len_table;
    return sum % len_table;
}

t_hash **insert_in_hash_table(t_hash **table, int *len_table, t_hash *node, int max_len)
{
    int new_len;
    //printf("MAx_len = %d\n", max_len);
    t_hash **new_table;
    int index = what_index(node->word, *len_table);
    table[index] = add_end(table[index], node);
    int len = len_list(table[index]);
    //printf(" L %d\n", len);

    while (len > max_len)
    {
        new_len = next_prime_number(*len_table);
        //printf("len %d\n", new_len);
        new_table = calloc((size_t) new_len, sizeof(t_hash*));

        char *word = malloc((SIZE_WORD + 1) * sizeof(char));
        for (int i = 0; i < *len_table; i++)
        {
            for (t_hash *j = table[i]; j; j = j->next)
            {
                word = strcpy(word, j->word);
                node = create_hash_node(word);
                index = what_index(node->word, new_len);
                new_table[index] = add_end(new_table[index], node);
            }
        }

        len = 0;
        for (int i = 0; i < new_len; i++)
        {
            if (len_list(new_table[i]) > len)
            {
                len = len_list(new_table[i]);
            }
        }

        free(table);
        *len_table = new_len;
        table = new_table;
    }
    return table;
}

void print_table(t_hash **table, int len_table)
{
    for (int i = 0; i < len_table; i++)
    {
        printf("%d ", i);
        t_hash *cur= table[i];
        for ( ; cur; cur = cur->next)
        {
            printf (" -> %s", cur->word);
        }
        printf(" -> NULL\n");
    }
    printf("\n");
}


int count_node_table(t_hash **table, int len_table)
{
    int sum = 0;
    for (int i = 0; i < len_table; i++)
    {
        t_hash *cur= table[i];
        for ( ; cur; cur = cur->next)
        {
            sum += sizeof(char*) * 2;
        }
        sum += sizeof(t_hash*);
    }
    return sum;
}


t_hash **create_table(FILE *f, int *len_table)
{
    rewind(f);
    t_hash **table = NULL;
    t_hash *node;
    table = calloc((size_t) *len_table, sizeof(t_hash*));
    int i = 0, max_len = 0;
    char *s = calloc(100, sizeof(char));
    fgets(s, 100, f);
    if (strcmp("efficiency\n", s) == 0)
    {
        max_len = 5;
    }
    else
    {
        max_len = 3;
    }
    rewind(f);
    while (!feof(f))
    {
        fscanf(f, "%c", &s[i]);
        if (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '.')
        {
            s[i] = '\0';
            if (strcmp(s, " ") != 0 && strcmp(s, "\n") != 0 && i != 0)
            {
                node = create_hash_node(s);
                table = insert_in_hash_table(table, len_table, node, max_len);
            }
            i = 0;

        }
        else
        {
            i++;
        }
    }
    free(s);
    return table;
}

int check_int(int *number, int min, int max)
{
    int rc, num, error;
    char tmp;
    rc = scanf("%d%c", &num, &tmp);
    if (rc == 2 && (tmp == '\n' || tmp == ' '))
    {
        if ((num > min) && (num < max))
        {
            *number = num;
            error = SUCCESS;
        }
        else
        {
            error = -1;
        }

        if (!min && !max && error == -1)
        {
            *number = num;
            error = SUCCESS;
        }
        return error;
    }
    else if (tmp != '\n')
    {
        while(tmp != '\n')
        {
            scanf("%c", &tmp);
        }
        return -2;
    }
    else
    {
        return -2;
    }

    return SUCCESS;
}




