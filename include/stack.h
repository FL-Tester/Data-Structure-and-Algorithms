/*  栈
    链表实现 / （链表的应用）
    不管是删除函数增加 都是在链表的同一端
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define name_size 10

// 节点数据结构体
typedef struct person{
        char name[name_size];
        int age;
        float weight;
}Stack_Data_Type;

typedef struct stack{
    Stack_Data_Type data;
    struct stack *Next;
}Stack, *P_Stack;

P_Stack new_stack(Stack_Data_Type *data_init);      //节点创建
int stack_push(P_Stack stack, P_Stack new_stack);   //进栈
P_Stack stack_pop(P_Stack stack);                   //出栈