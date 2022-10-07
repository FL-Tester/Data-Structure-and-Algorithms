#pragma once 
#include <stdio.h>
#include <stdlib.h>


#define LIST_SIZE 10
typedef int Data_Type;



typedef struct data{
    Data_Type * Data_Enter; //入口地址
    int Size;               //大小
    int Last;               //当前使用量
}Data, *rank_list;


rank_list init_rank_list();
int list_insert(rank_list ptr, Data_Type data);
int list_display(rank_list ptr);
int list_del(rank_list ptr, Data_Type data);





