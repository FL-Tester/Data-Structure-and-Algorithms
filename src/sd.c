/* 顺序表
1. 建立堆空间 初始化Data_Enter
2. 确定堆空间的大小，初始化Size
3. 初始化当前使用量为0
*/


#include "sd.h"

//初始化顺序表
rank_list init_rank_list(){
    //创建一个结构体管理指针
    rank_list Ptr_Manager =  calloc(1, sizeof(Data));
    //申请堆空间来作为顺序表的存储空间
    Ptr_Manager->Data_Enter = calloc(LIST_SIZE, sizeof(Data_Type));
    //设置顺序表大小
    Ptr_Manager->Size = LIST_SIZE;
    //设置当前使用量 为0
    Ptr_Manager->Last = 0;

    return Ptr_Manager;
}
//数据插入 并排序
int list_insert(rank_list ptr, Data_Type data){
    //判断堆空间是否存在 和 列表是否已满
    if( ptr == NULL ||  ptr->Last == ptr->Size){
        printf("指向堆空间为空 或者 堆空间已经满了!\n");
        return -1;
    }
    //数据插入堆中空间  ptr->Last是一个具体下边 这里就像数组赋值
    int tmp = 0 ;
    if(!(ptr->Last == 0)){
        for (int i = 0; i < ptr->Last ; i++){
            if(data <= ptr->Data_Enter[i]){
                tmp = i ;
                for (int j = ptr->Last ; j > i   ; j--){
                    ptr->Data_Enter[j] = ptr->Data_Enter[j-1] ; //从后面 因为后面第一个是空的
                }
                // 把数据存放到顺序表的内存中
                ptr->Data_Enter[ tmp ]  = data;
                // 让顺序表的当前下标往后移动
                ptr->Last ++ ; 
                return ptr->Last ;
            }           
        }
    } 
    ptr->Data_Enter[ptr->Last]  = data ;    
    // 要不要直接插入玩后再排序呢
    //使用后+1
    (ptr->Last)++;
    //返回下表 是下一次插入的下表
    return ptr->Last;  //返回插入的坐标
}

//列表数据显示
int list_display(rank_list ptr){
    if ( ptr == NULL || ptr->Last == 0){
        printf("指向堆空间为空 或者 没有数据!\n");
        return -1;
    }

    //循环打印
    for(int i = 0; i < ptr->Last; i++){
        printf("Data[%d]:%d\n", i, *(ptr->Data_Enter + i));
    }
}


//列表删除
int list_del(rank_list ptr, Data_Type data){
    if(ptr == NULL || ptr->Last == 0 )
    {
        printf("顺序表为空！！！\n");
        return 0 ; // 下标为 size 
    }

    for (int i = 0; i < ptr->Last ; i++)// 遍历整个表
    {
        if(data == ptr->Data_Enter[i]) // 比较数据是否与新数据相同或大于
        {
            for (size_t j = i ; j < ptr->Last ; j++)
            {
                *(ptr->Data_Enter+j) = *(ptr->Data_Enter+j+1) ;
            }
            ptr->Last -- ;
        }
    }

    return 1 ;
}





