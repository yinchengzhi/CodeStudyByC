
#include"Queue.h"

void main() {

	Queue *phead = NULL;				//创建头节点
	phead = init(phead);

	phead = insertEnQueue(phead, 1, 1);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 2, 12);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 3, 13);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 4, 4);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 5, 15);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 6, 6);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 6, 0);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 7, 0);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 8, 0);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 9, 1);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 10, 0);
	printf("\n");
	printall(phead);

	phead = insertEnQueue(phead, 11, 19);
	printf("\n");
	printall(phead);



	while (phead != NULL) {				//不为空就继续
		//分配内存
		Queue *ptemp = (Queue *)malloc(sizeof(Queue));
		phead = DeQueue(phead, ptemp);
		printf("\n拉屎一次以后\n");
		printall(phead);
		printf("\n拉出来的是%d,%d\n", ptemp->num, ptemp->high);
	}

	system("pause");
}