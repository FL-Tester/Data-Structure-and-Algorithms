#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef int Data_Type;

typedef struct queue{
    Data_Type *enter;//入口地址
    int front;             //队头index
    int rear;              //队尾index
    int size;              //队列大小
}Queue, *Queue_Ptr;


Queue_Ptr queue_init(int size);
bool queue_add(Queue_Ptr queue, Data_Type data);
Data_Type queue_eixt(Queue_Ptr queue);
bool queue_is_empty(Queue_Ptr queue);
bool queue_is_full(Queue_Ptr queue);
bool queue_display(Queue_Ptr queue);


