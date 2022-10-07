#include "stack.h"

P_Stack new_stack(Stack_Data_Type *data_new){
    //栈空间指针 指向堆空间内存
    P_Stack stack_new = calloc(1, sizeof(Stack));
    //如果传入data_new不为NULL 则赋值
    if(data_new != NULL){
        strncpy(stack_new->data.name, data_new->name, 10);  //只能用strncpy赋值
        stack_new->data.age     =   data_new->age;
        stack_new->data.weight  =   data_new->weight;
    }
    stack_new->Next = NULL;
    //返回指针
    return stack_new;
}

int stack_push(P_Stack stack, P_Stack new_stack){
    if(stack == NULL || new_stack == NULL){
        return -1;
    }
    //插入头处  通过指针修改栈空间地址上面的值
    P_Stack temp = stack;
    new_stack->Next = temp->Next;
    temp->Next = new_stack;

    return 0;
}

P_Stack stack_pop(P_Stack stack){
    if(stack->Next == NULL){
        printf("空栈\n");
        return NULL;
    }
    P_Stack temp = stack->Next;
    stack->Next = temp->Next;
    temp->Next = NULL;


    return temp;
}