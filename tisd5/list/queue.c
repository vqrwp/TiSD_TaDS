#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "constants.h"

node_t *get_new_node(float time, type_t t)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node)
    {
        return new_node;
    }
    new_node->time = time;
    new_node->next = NULL;
    new_node->type = t;
    return new_node;
}

queue_t *init_queue()
{
    queue_t *new_node = (queue_t *)malloc(sizeof(queue_t));
    if (NULL == new_node)
    {
        return new_node;
    }
    new_node->pin = new_node->pout = NULL;
    new_node->num_of_elems = 0;
    new_node->summ_of_elems = 0;
    return new_node;
}

int add_elem(queue_t *queue, float time, type_t t)
{
    if (queue == NULL)
    {
        return FAIL;
    }

    node_t *new_node = get_new_node(time, t);
    if (new_node == NULL)
    {
        return FAIL;
    }
    if (queue->pin == NULL)
    {
        queue->pout =  new_node;
        queue->pin = new_node;
        queue->num_of_elems++;
        queue->summ_of_elems++;
        return SUCCESS;
    }
    queue->pout->next = new_node;
    queue->pout = new_node;
    queue->num_of_elems++;
    queue->summ_of_elems++;

    return SUCCESS;
}

float delete_elem(queue_t *queueptr)
{

    if (queueptr == NULL || queueptr->pin == NULL)
    {
        return FAIL;
    }
    node_t *temp = queueptr->pin;
    float time = temp->time;
    queueptr->pin = temp->next;
    free(temp);
    queueptr->num_of_elems--;
    return time;
}

void print_queue(queue_t *queueptr)
{
    node_t *temp = queueptr->pin;
    while (temp != NULL)
    {
        printf("%g \t", temp->time);
        temp=temp->next;
    }
}

void free_queue(queue_t *queueptr)
{
    queue_t *temp;
    for (; queueptr; queueptr = temp)
    {
        temp = queueptr;
        free(queueptr);
    }
}