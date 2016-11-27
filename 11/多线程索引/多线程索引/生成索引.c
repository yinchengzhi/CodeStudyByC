#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\IndexBigData.txt";

#define N 20161124

struct index {
	int *pindex;											//�����ڴ��׵�ַ
	int length;												//����
}allindex = { 0 };

void init(char *path) {

	printf("\n��ʼ����");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));				//��ʼ������
	printf("\n��������");

	printf("\n��ʼ����");

	FILE *pf = fopen(path, "rb");
	if (pf == NULL) {
		puts("file open fail");
	}
	else {
		int all_length = 0;
		for (int i = 0; i < N; i++) {
			char str[1500] = { 0 };
			fgets(str, 1500, pf);							//��ȡ�ַ���
			allindex.pindex[i] = all_length;
			int length = strlen(str);
			all_length += length;							//����λ��

		}
		fclose(pf);
	}

	printf("\n��������");

	//д������
	printf("\n��ʼд��");
	FILE *pfw = fopen(indexpath, "wb");
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("\n����д��");
}

void quick() {
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));				//��ʼ������

	FILE *pfw = fopen(indexpath, "rb");
	fread(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
}

struct info{
	int *pstart;											//��ʼλ��
	int length;												//����
	char findstr[20];										//Ҫ����
	int id;													//

};

void runmem(void *p) {
	FILE *pf = fopen(path, "rb");
	struct info *pi = p;									//ָ������ת��
	for (int i = 0; i < pi->length; i++) {
		int tempnum = pi->pstart[i];						//�ֶ�
		fseek(pf, allindex.pindex[tempnum], SEEK_SET);		//����ƫ�ƶ��ļ�
		char str[512] = { 0 };
		fgets(str, 512, pf);
		char *px = strstr(str, pi->findstr);				//����

		if (px != NULL) {
			printf("\n%d�߳��ҵ�%s", pi->id, pi->findstr);	//��ӡ�ҵ�������
		}

	}

	fclose(pf);
}

void main() {
	quick();												//�����ڴ�
	printf("�������ѯ��");
	char str[100] = { 0 };
	scanf("%s", str);

#define nthread 100
	struct info pthread[nthread];							//�����߳�ʹ����Ϣ����

	//100 10*10 9 8*12+4
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			strcpy(pthread[i].findstr, str);
			pthread[i].length = N / nthread;
		}
	}
	else {

	}

	system("pause");
}


void main() {

	quick();

	//init(path);

	FILE *pf = fopen(path, "rb");
	while (1) {
		puts("input\n");
		int num = 0;
		scanf("%d", &num);

		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[512] = { 0 };
		fgets(str, 512, pf);
		puts(str);										//��ʾ
		//printf("\n%s",str);
	}

	system("pause");
}