#pragma once

#include <stdio.h>
#include <stdlib.h>


//单向链表 
typedef int Data_Type;
typedef struct list_single{
    Data_Type Data;     //数据域
    struct list_single *Next;  //指针域
}List_single, *List_single_Ptr;

//单向链表 函数声明
List_single_Ptr init_list(void);
List_single_Ptr new_node(Data_Type data);
List_single_Ptr List_single_display(List_single_Ptr list, Data_Type *num);
int List_single_add(List_single_Ptr list, const List_single_Ptr node);
int List_single_add_last(List_single_Ptr list, const List_single_Ptr node);
