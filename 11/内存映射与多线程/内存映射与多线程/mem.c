#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\QQindex8848.txt";

struct {
	char *pfilestart;
	char *pfileend;
	char *pindexfilestart;
	char *pindexfileend;
}infoall = { 0 };

void map1() {
	HANDLE hfile = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//��һ���ļ�
	
	if (hfile == INVALID_HANDLE_VALUE) {
		printf("���ļ�ʧ��");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//��ȡ�ļ���С
	
	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//��д
		0,
		GetFileSize(hfile, NULL) + 1,											//��С
		NULL);

	if (hmap == NULL) {
		printf("ӳ��ʧ��");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//����һ��ָ�룬�洢ӳ���Ժ���׵�ַ
	if (pvfile == NULL) {
		printf("ָ��ӳ��ʧ��");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("ӳ��ɹ�");
	char *pstart = pvfile;														//�׵�ַ
	char *pend = pstart + GetFileSize(hfile, NULL);								//������ַ

	infoall.pfileend = pend;													//�����ַ
	infoall.pfilestart = pstart;					

}

void map2() {
	HANDLE hfile = CreateFileA(indexpath, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//��һ���ļ�

	if (hfile == INVALID_HANDLE_VALUE) {
		printf("���ļ�ʧ��");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//��ȡ�ļ���С

	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//��д
		0,
		GetFileSize(hfile, NULL) + 1,											//��С
		NULL);

	if (hmap == NULL) {
		printf("ӳ��ʧ��");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//����һ��ָ�룬�洢ӳ���Ժ���׵�ַ
	if (pvfile == NULL) {
		printf("ָ��ӳ��ʧ��");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("ӳ��ɹ�");
	char *pstart = pvfile;														//�׵�ַ
	char *pend = pstart + GetFileSize(hfile, NULL);								//������ַ

	infoall.pindexfileend = pend;													//�����ַ
	infoall.pindexfilestart = pstart;
}

void main() {

	map1();
	map2();
	getchar();

}