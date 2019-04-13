#ifndef QUEUE_H
#define QUEUE_H

#include "structs.h"

node_t *get_new_node(float, enum req_type);
queue_t *init_queue();
int add_elem(queue_t *, float, enum req_type t);
float delete_elem(queue_t *);
void print_queue(queue_t *);
void free_queue(queue_t *queueptr);

#endif // QUEUE_H