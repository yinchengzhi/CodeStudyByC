#include"linknode.h"
#include<Windows.h>


struct node *phead = NULL;

DWORD WINAPI builder(void *p) {

	phead = enq(phead, 0);
	int i = 0;
	while (++i) {
		HANDLE event = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isok");
		WaitForSingleObject(event, INFINITE);

		phead = enq(phead, i);
		printf("\n生产者生产了  %4d\n", i);
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
		HANDLE event = OpenEvent(EVENT_ALL_ACCESS, TRUE, "isok");
		SetEvent(event);

	}
	return 1;
}

void main() {

	HANDLE event = CreateEvent(NULL, FALSE, FALSE, "isok");
	CreateThread(NULL, 0, builder, NULL, 0, NULL);
	CreateThread(NULL, 0, player, NULL, 0, NULL);

	system("pause");
	CloseHandle(event);
}
