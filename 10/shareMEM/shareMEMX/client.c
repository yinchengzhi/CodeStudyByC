#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void main() {

	HANDLE hmapfile = OpenFileMappingA(FILE_MAP_READ, FALSE, "yinchengzhimem");
	if (hmapfile == NULL) {
		printf("����ʧ��");
	}

	//����ָ�룬ָ����Ƭ�ڴ�
	LPVOID lpbase = MapViewOfFile(hmapfile, FILE_MAP_READ, 0, 0, 0);
	if (lpbase == NULL) {
		printf("openʧ��");
	}

	//printf("%s", (char*)lpbase);								//��ȡ�ַ���

	int *p = lpbase;
	for (int i = 0; i < 10; i++) {
		printf("%d\n", p[i]);
	}

	UnmapViewOfFile(lpbase);									//���
	CloseHandle(hmapfile);

	system("pause");
}