#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ȡ�����ݶ�����
//int a[N],����
//д�뵽�ļ�
//�����ļ������ڴ�
//�����

#define N 15186998

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\BigData_Index.txt";

struct index {
	int *pindex;				//��ַ
	int length;					//����
}allindex;

void init(char *path) {

	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));						//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");

	FILE *pf = fopen(path, "rb");									// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {

		int alllength = 0;

		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);

			allindex.pindex[i] = alllength;							//��λ , ��0��ʼ
			int length = strlen(str);
			alllength += length;
			allindex.pindex[i] = alllength;
		}
		fclose(pf);
	}

	printf("������ȡ\n");

	printf("��ʼд��\n");
	FILE *pfw = fopen(indexpath, "wb");								//д������
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("����д��\n");

	free(allindex.pindex);

	printf("��ʼ��ȡ\n");
	FILE *pfr1 = fopen(indexpath, "rb");							//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr1);
	fclose(pfr1);
	printf("������ȡ\n");

}

void quick() {
	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));						//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");
	FILE *pfr = fopen(indexpath, "rb");								//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr);
	fclose(pfr);
	printf("������ȡ\n");

}

int getN(char *path) {
	int i = -1;
	FILE *pf = fopen(path, "rb");									// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {
		i = 0;
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
		}
		fclose(pf);
		return i;
	}
}

void main1x() {

	//printf("%d", getN(path));
	//init(path);

	quick();

	FILE *pf = fopen(path, "rb");
	while (1) {
		printf("\n������Ҫ��ȡ������:");
		int num = 0;
		scanf("%d", &num);
		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf);										//��ȡ
		printf("%s", str);
	}

	fclose(pf);


	system("pause");
}

void main() {

	FILE *pf1 = fopen(indexpath, "rb");
	FILE *pf2 = fopen(path, "rb");

	while (1) {
		printf("\n������Ҫ��ȡ������:");
		int num = 0;
		scanf("%d", &num);

		int indexnum = 0;
		fseek(pf1, num * sizeof(int), SEEK_SET);
		fread(&indexnum, sizeof(int), 1, pf1);						//��������indexnum

		fseek(pf2, indexnum, SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf2);										//��ȡ
		printf("\n%s", str);
	}

	fclose(pf1);
	fclose(pf2);

	system("pause");
}

