#include "main.h"

int main()
{
	rank_list list_1 = init_rank_list();
	for (int i = 1; i < 12; i++)  //插入的数为倒序
		list_insert(list_1, 12-i);
	list_display(list_1);

	list_del(list_1, 4);
	list_del(list_1, 5);

	list_display(list_1);

	free(list_1->Data_Enter);
    free(list_1);

	return (0);
}

