
#include"Queue.h"

void main() {

	Queue *phead = NULL;				//����ͷ�ڵ�
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



	while (phead != NULL) {				//��Ϊ�վͼ���
		//�����ڴ�
		Queue *ptemp = (Queue *)malloc(sizeof(Queue));
		phead = DeQueue(phead, ptemp);
		printf("\n��ʺһ���Ժ�\n");
		printall(phead);
		printf("\n����������%d,%d\n", ptemp->num, ptemp->high);
	}

	system("pause");
}