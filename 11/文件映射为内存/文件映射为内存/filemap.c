
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char path[256] = "G:\\BigDataSort.txt";

void main() {
	//·������д
	HANDLE hfile = CreateFileA(path,												//��һ���ļ�
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hfile == INVALID_HANDLE_VALUE) {
		printf("��ʧ��!");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));

	HANDLE hmap = CreateFileMappingA(hfile,
		NULL,
		PAGE_READWRITE | SEC_COMMIT,												//��д
		0,
		GetFileSize(hfile, NULL) + 1,												//��ȡ�ļ���С
		NULL);

	if (hmap == NULL) {
		printf("ӳ��ʧ��");
		CloseHandle(hfile);
		system("pause");
	}

	//����һ��ָ�룬�洢ӳ���Ժ���׵�ַ
	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (pvfile == NULL) {
		printf("ָ��ӳ��ʧ��");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("ӳ��ɹ�");

	char *pstart = pvfile;															//�׵�ַ
	char *pend = pstart + GetFileSize(hfile, NULL);									//������ַ

	system("pause");
	//for (int i = 0; i < 1000; i++) {
	//	putchar(*(pstart + i));
	//}

	char str[100] = "haihua love fang";
	memcpy(pstart, str, strlen(str));

	system("pause");
	UnmapViewOfFile(pvfile);														//���ӳ��
	CloseHandle(hmap);

	system("pause");
}