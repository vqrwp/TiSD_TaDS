#ifndef ARRAY_STRUCTS_H
#define ARRAY_STRUCTS_H

typedef enum req_type
{
    NONE, T1, T2
}type_t;


typedef struct queue
{
    float* data_store;
    int front;
    int max_size;
    int num_of_elems;
    int summ_of_elems;
    type_t type;
} queue_t;

typedef struct alarm
{
    float time;
}alarm_t;

typedef struct automat
{
    float now;
    enum req_type now_t;
    enum req_type prev;
    float work_time;
    int left1;
    int left2;
    float downtime;
    float work;
} automat;

#endif //ARRAY_STRUCTS_H
