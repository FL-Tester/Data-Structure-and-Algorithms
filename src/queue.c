/* 
    环形队列
    一个管理结构体指针 指向堆
        一个指针 指向堆 队列
        队列大小
        队头index
        队尾index
    操作
        出列
        入列
    边界条件
        空 front = rear
        满 rear = front
        queue->rear = (queue->rear + 1) % queue->size;
        queue->front = (queue->front + 1) % queue->size;
        队列1前面一个位置不能用
*/
#include "queue.h"
/* 
    循环队列管理结构体
*/
Queue_Ptr queue_init(int size){
    Queue_Ptr queue = calloc(1, sizeof(Queue));
    queue->enter = calloc(size, sizeof(Data_Type));
    queue->size = size;
    queue->front = 1;
    queue->rear = 1; 
    return queue;
}
//入列 从队尾出列
bool queue_add(Queue_Ptr queue, Data_Type data){
    if(queue_is_full(queue)){
        printf("queue is full!\n");
        return false;
    }
    queue->enter[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->size; 
    return true ;
}
//出列 从队头出列
Data_Type queue_eixt(Queue_Ptr queue){
   
    if(queue_is_empty(queue)){
        printf("queue is empty!\n");
        return -1;
    }
    Data_Type temp = queue->enter[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return temp;
}
//队列判空
bool queue_is_empty(Queue_Ptr queue){
    if(queue->rear == queue->front)
        return true;
    else
        return false;
}
//队列判满
bool queue_is_full(Queue_Ptr queue){
    if((queue->rear + 1) % queue->size == queue->front)
        return true;
    else
        return false;
}

