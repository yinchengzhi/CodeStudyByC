#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define SIZE 4096
LPVOID lpdata = NULL;												//ָ���ʶ�ڴ���׵�ַ

void main() {

	if (lpdata != NULL) {
		puts("�����ڴ����");
	}

	HANDLE hmap = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL,
		PAGE_READWRITE | SEC_COMMIT, 0, SIZE, "yinchengzhimem");

	if (hmap == NULL) {
		puts("����ʧ��");
	}
	else {
		//ӳ���ļ���ָ��
		lpdata = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
		
		//char str[100] = "Hello World,hello China";
		//memcpy(lpdata, str, strlen(str) + 1);						//�����ڴ�

		int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
		memcpy(lpdata, a, 40);

	}

	system("pause");

	UnmapViewOfFile(lpdata);								    	//���
	CloseHandle(hmap);

	system("pause");
}