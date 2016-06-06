//#include"linknode.h"
//#include<Windows.h>
//
//
//struct node *phead = NULL;
//
//DWORD WINAPI builder(void *p) {
//
//	phead = enq(phead, 0);
//	int i = 0;
//	while (++i) {
//		HANDLE sem = OpenSemaphoreA(SEMAPHORE_ALL_ACCESS, TRUE, "fang");
//		WaitForSingleObject(sem, INFINITE);
//		phead = enq(phead, i);
//		printf("\n生产者生产了  %4d\n", i);
//	}
//	return 1;
//}
//
//DWORD WINAPI player(void *p) {
//	int i = 0;
//	while (++i) {
//		MessageBoxA(0, "wait", "wait", 0);
//		int num;
//		phead = deq(phead, &num);					//取出数据
//		printf("\n消费者消费了  %4d\n", num);
//		HANDLE sem = OpenSemaphoreA(SEMAPHORE_ALL_ACCESS, TRUE, "fang");
//		ReleaseSemaphore(sem, 1, NULL);
//	}
//	return 1;
//}
//
//void main() {
//
//	HANDLE sem = CreateSemaphoreA(NULL, 0, 1, "fang");
//	CreateThread(NULL, 0, builder, NULL, 0, NULL);
//	CreateThread(NULL, 0, player, NULL, 0, NULL);
//
//	system("pause");
//	CloseHandle(sem);
//}
