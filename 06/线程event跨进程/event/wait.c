#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char name[100] = "haihualovefang";

void main() {

	HANDLE event = OpenEventA(EVENT_ALL_ACCESS, TRUE, name);			//���¼�
	if (event == NULL) {
		printf("\n��ʧ��");
		system("pause");
		return;
	}
	printf("\n�ȴ�-----------");

	DWORD res = WaitForSingleObject(event, 20000);

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

	CloseHandle(event);


	system("pause");
}