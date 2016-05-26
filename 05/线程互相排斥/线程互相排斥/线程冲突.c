#include<stdio.h>
#include<Windows.h>

HANDLE mutex = NULL;											//指针
int num = 0;

DWORD WINAPI add(void *p) {
	WaitForSingleObject(mutex, INFINITE);
	for (int i = 0; i < 100000; i++) {
		num++;
	}
	ReleaseMutex(mutex);
}

void main() {

	mutex = CreateMutex(NULL, FALSE, NULL);						//创建互斥
	if (mutex == NULL) {
			//创建失败
	}

	HANDLE hd[64];												//线程互斥,同一个互斥量，只能解决64个（家用电脑限制）
	for (int i = 0; i < 64; i++) {
		hd[i] = CreateThread(NULL, 0, add, NULL, 0, NULL);
		if (hd[i] == NULL) {
			//创建失败
		}
	}

	WaitForMultipleObjects(64, hd, TRUE, INFINITE);
	printf("%d\n", num);

	for (int i = 0; i < 64; i++) {
		CloseHandle(hd[i]);										//关闭每一个线程资源
	}

	system("pause");
}