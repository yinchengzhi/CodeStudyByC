#include"linknode.h"
#include<Windows.h>


struct node *phead = NULL;

DWORD WINAPI builder(void *p) {
	int i = 0;
	while (++i) {
		if (phead == NULL) {
			phead = enq(phead, i);
			printf("\n生产者生产了  %4d\n", i);
		}
		Sleep(1000);
	}
	return 1;
}

DWORD WINAPI player(void *p) {
	int i = 0;
	while (++i) {
		MessageBoxA(0, "wait", "wait", 0);
		int num;
		phead = deq(phead, &num);					//取出数据
		printf("\n消费者消费了  %4d\n", num);
	}
	return 1;
}

void main() {

	CreateThread(NULL, 0, builder, NULL, 0, NULL);
	CreateThread(NULL, 0, player, NULL, 0, NULL);

	system("pause");
}


//
//
//
//void main1() {
//	
//	struct node *phead;
//	init(&phead);
//
//	for (int i = 0; i < 10; i++) {
//		phead = enq(phead, i);
//		show(phead);
//		fputc('\n', stderr);
//	}
//
//	while (phead != NULL) {
//		int num;
//		phead = deq(phead,&num);
//		printf("out is %4d\n", num);
//		show(phead);
//		fputc('\n', stderr);
//	}
//
//	system("pause");
//}