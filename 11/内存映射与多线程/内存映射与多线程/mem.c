#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

//���޵��ڴ�֮����ô�ɻ�
//���������ڴ棬���߳�
//����ӳ��Ϊ�ڴ�

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\QQindex8848.txt";

#define N 18175317

struct {
	char *pfilestart;
	char *pfileend;
	char *pindexfilestart;
	char *pindexfileend;
}infoall = { 0 };																//����ӳ��������ļ���ͷ��ַ��β��ַ

//ӳ���ļ����ļ��Ƕ�������
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

	infoall.pindexfileend = pend;										    	//�����ַ
	infoall.pindexfilestart = pstart;
}

//��ȡ�������ڴ�
struct index{
	int *pindex;																//��ַ
	int length;	
}allindex = { 0 };

void readmem() {
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));

	FILE *pfw = fopen(indexpath, "rb");
	fread(allindex.pindex, sizeof(int), N, pfw);
	fclose(pfw);
}



//  0 1 2 3 9
struct info {
	int *pstart;			//�������׵�ַ
	int length;				//����
	int id;					//���
	char findstr[20];		//���ҵ��ַ���
};

void run(void *p) {
	struct info *pi = p;
	for (int i = 0; i < pi->length - 1; i++) {								//�޶�

		char *start = infoall.pfilestart + pi->pstart[i];					//��ʼ��ַ
		char *end = infoall.pfilestart + pi->pstart[i + 1];					//������ַ

		char *str = calloc(500, 1);											//�����ڴ����ڿ����ַ������ļ����飬û��\0,��\n
		if (str != NULL) {													//����ɹ�
			strncpy(str, start, pi->pstart[i + 1] - pi->pstart[i]);			//�����ַ���
			if (str != NULL) {
				char *ps = strstr(str, pi->findstr);						//����
				if (ps != NULL) {
					printf("%s", str);
				}
			}

		}
		free(str);															//�ͷ�
	}
}

void test1() {
	printf("please input");
	char str[100];
	scanf("%s", str);
#define nthread 100
	struct info pthread[nthread] = { 0 };
	HANDLE hd[nthread] = { 0 };												//�̲߳���,�߳̾��
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			pthread[i].length = N / nthread;
			pthread[i].pstart = allindex.pindex + i*(N / nthread);
			strcpy(pthread[i].findstr, str);
			_beginthread(run, 0, &pthread[i]);
		}
	}
	else {
		for (int i = 0; i < nthread - 1; i++) {
			pthread[i].id = i;
			pthread[i].length = N / (nthread - 1);
			pthread[i].pstart = allindex.pindex + i*(N / (nthread - 1));
			strcpy(pthread[i].findstr, str);
			_beginthread(run, 0, &pthread[i]);
		}

		int i = nthread - 1;
		pthread[i].id = i;
		pthread[i].length = N % (nthread - 1);
		pthread[i].pstart = allindex.pindex + i*(N / (nthread - 1));
		strcpy(pthread[i].findstr, str);
		_beginthread(run, 0, &pthread[i]);

	}

	WaitForMultipleObjects(nthread, hd, TRUE, INFINITE);

	system("pause");
}



//  0 1 2 3 9
struct minfo {
	int *pstart;
	int length;
	int id;
	char findstr[20];
};

void mrun(void *p) {
	struct minfo *pi = p;
	for (int i = 0; i < pi->length - 1; i++) {
		char *start = infoall.pfilestart + pi->pstart[i];					//��ʼ��ַ
		char *end = infoall.pfilestart + pi->pstart[i + 1];					//������ַ
		char *str = calloc(500, 1);											//�����ڴ����ڿ����ַ���
		if (str != NULL) {													//����ɹ�
			strncpy(str, start, pi->pstart[i + 1] - pi->pstart[i]);			//�����ַ���
			if (str != NULL) {
				char *ps = strstr(str, pi->findstr);
				if (ps != NULL) {
					printf("%s", str);
				}
			}

		}
		free(str);															//�ͷ�
	}
}

void test2() {
	printf("please input");
	char str[100];
	scanf("%s", str);
#define nthread 100
	struct minfo pthread[nthread] = { 0 };
	HANDLE hd[nthread] = { 0 };												//�̲߳���,�߳̾��
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			pthread[i].length = N / nthread;
			pthread[i].pstart = infoall.pindexfilestart + i*(N / nthread);
			strcpy(pthread[i].findstr, str);
			_beginthread(mrun, 0, &pthread[i]);
		}
	}
	else {
		for (int i = 0; i < nthread - 1; i++) {
			pthread[i].id = i;
			pthread[i].length = N / (nthread - 1);
			pthread[i].pstart = (int*)allindex.pindex + i*(N / (nthread - 1));
			strcpy(pthread[i].findstr, str);
			_beginthread(mrun, 0, &pthread[i]);
		}

		int i = nthread - 1;
		pthread[i].id = i;
		pthread[i].length = N % (nthread - 1);
		pthread[i].pstart = (int*)allindex.pindex + i*(N / (nthread - 1));
		strcpy(pthread[i].findstr, str);
		_beginthread(mrun, 0, &pthread[i]);

	}

	WaitForMultipleObjects(nthread, hd, TRUE, INFINITE);

	system("pause");
}




void main() {

	readmem();
	map1();																//һ����ӳ�䣬�ļ�������
	map2();
	test1();
	//test2();

	getchar();

}