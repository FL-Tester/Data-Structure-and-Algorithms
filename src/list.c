/*  链表
1. 单向链表
2. 双向链表
3. 单向循环链表
4. 双向循环链表
*/
#include "list.h"

List_single_Ptr init_list(void){
    //头节点申请
    List_single_Ptr head = calloc(1, sizeof(List_single)); 
    head->Data = 0;     //头节点数据域无用
    head->Next = NULL;  //默认没有指向

    return head;
}

List_single_Ptr new_node(Data_Type data){
    //头节点申请
    List_single_Ptr head = calloc(1, sizeof(List_single)); 
    head->Data = data;     //头节点数据域无用
    head->Next = NULL;  //默认没有指向
    return head;
}

//节点插入 并非数据插入
int List_single_add(List_single_Ptr list, const List_single_Ptr node){
    //分析情况 链表为空 但是链表不可能为满
    if(list == NULL){
        printf("链表为空");
        return -1;
    }
    //拼接一下 这里是插入的位置是 第一个数据节点
    node->Next = list->Next; //新节点直线原来的第一个数据节点
    list->Next = node; //头结点指向新节点

    return 0;
}

//链表遍历 一只指向想去 直到为空
List_single_Ptr List_single_display(List_single_Ptr list, Data_Type *num){
    if(list == NULL){
        printf("链表为空");
        return NULL;
    }

    List_single_Ptr temp = list->Next;

    while( temp->Next != NULL ) {
        if(num == NULL ){
            printf("data:%d\n" , temp->Next->Data);
        }
        else{
            if(temp->Next->Data == *num){
                return temp;
            }
        }
        temp = temp->Next ; 
    }   
    return NULL;
}

//末尾插入
int List_single_add_last(List_single_Ptr list, const List_single_Ptr node){

    if( list == NULL ){
        printf("链表头异常！！！\n");
        return -1 ;
    }
    //不修改传进来的指针 不影响调用者
    List_single_Ptr temp = list;
    //找到最后的Next
    for(temp = list; temp->Next != NULL;  temp = temp->Next)    
        ;
    //新节点 指向链表最后一个next
    temp->Next = node;

    return 0;
}

//s