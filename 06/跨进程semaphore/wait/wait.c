#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE hsem = OpenSemaphoreA(SEMAPHORE_ALL_ACCESS, TRUE, name);
	if (hsem == NULL) {
		printf("\n��ʧ��");
		system("pause");
		return;
	}
	printf("\n�ȴ�-----------");

	DWORD res = WaitForSingleObject(hsem, 20000);

	switch (res) {
	case WAIT_OBJECT_0:
		printf("\n�յ��ź�---------");
		break;

	case WAIT_TIMEOUT:
		printf("\n��ʱû���յ�---------");
		break;

	case WAIT_ABANDONED:
		printf("\n����һ������������ֹ---------");
		break;

	default:
		break;

	}

	CloseHandle(hsem);

	system("pause");
}