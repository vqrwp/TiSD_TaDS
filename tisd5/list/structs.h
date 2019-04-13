#ifndef LIST_STRUCTS_H
#define LIST_STRUCTS_H

typedef enum req_type
{
    NONE,
    T1,
    T2
}type_t;

typedef struct qnode
{
    struct qnode *next;
    enum req_type type;
    float time;
} node_t;

typedef struct queue
{
    struct qnode *pin;
    struct qnode *pout;
    int num_of_elems;
    int summ_of_elems;
} queue_t;

typedef struct automat
{
    node_t *now;
    type_t prev;
    float work_time;
    float downtime;
    float work;
    int left1;
    int left2;
} automat;

#endif //LIST_STRUCTS_H
