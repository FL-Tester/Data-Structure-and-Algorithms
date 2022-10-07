#include "main.h"

int main(){	


	

#if 0

	//栈
	P_Stack stack = new_stack(NULL);
	Stack_Data_Type data; 				  //定义一个入栈的结构体数据
	strncpy(data.name, "fengle", 10);
	data.age = 18;
	data.weight = 49.95;
	P_Stack stack_2 = new_stack(&data);	  //定义一个入栈新节点 
	stack_push(stack, stack_2);			  //入栈
	printf("%d\n", stack->Next->data.age);//数据测试

	//出栈 返回出栈的节点
	P_Stack pop_2 = stack_pop(stack);
	printf("%d\n", pop_2->data.age);
	//由于出栈 原来靠链表实现的栈 已经无法指向出栈节点的堆空间内存 
	//也就是说此时 只有pop_2才能指向出栈的堆空间地址 需要释放吊 还有 
	free(pop_2);

	//delete p 之后，p指向地址可覆盖，但是p仍然指向原来的地址，
	//随着程序的运行，原本内存可能被使用，p指向可能内容改变。
	//所以为了安全起见，将p指向null。避免p不小心再次被使用。
	pop_2 = NULL;

	//疯狂入栈
	char *temp[5] ={
		"zhangsan",
		"lisi",
		"wangwu",
		"nima",
		"keyide"
	};
	for(int i = 0; i < 5; i++){
		data.age = i;
		data.weight = 50.1+i;
		strncpy(data.name, temp[i], name_size);
		P_Stack stack_new = new_stack(&data);
		stack_push(stack, stack_new);
	}
	//疯狂出栈
	for(int i = 0; i < 5; i++){
		P_Stack pop_new = stack_pop(stack);
		printf("name:%s, age:%d, weigt:%f\n", pop_new->data.name, pop_new->data.age, pop_new->data.weight);
		free(pop_new);
		pop_new = NULL;
	}

	//单向链表
	//链表初始化头节点
	List_single_Ptr List_single = init_list();

	//循环插入 
	for(int i = 0; i < 12 ; i++){
		//新的数据节点的创建
		List_single_Ptr newnode = new_node(12-i);
		//将节点插入头节点后面，插入哪 由List_single_add决定
		List_single_add(List_single, newnode);
	}
	for(int i = 0; i < 12 ; i++){
		//新的数据节点的创建
		List_single_Ptr newnode = new_node(12-i);
		//将节点插入头节点后面，插入哪 由List_single_add决定
		List_single_add_last(List_single, newnode);
	}
	//链表遍历显示
	List_single_display(List_single, NULL);


	//顺序表初始化
	rank_list list_1 = init_rank_list();
	//插入
	for (int i = 1; i < 12; i++)  //插入的数为倒序
		list_insert(list_1, 12-i);
	list_display(list_1);
	//删除
	list_del(list_1, 4);
	list_del(list_1, 5);
	//按顺序打印列表
	list_display(list_1);
	//释放堆空间
	free(list_1->Data_Enter);
    free(list_1);


	
#endif	

	return (0);
}

