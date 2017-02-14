#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char path[512] = "G:\\BigData.txt";
char pathsortbypass[512] = "G:\\QQpasswordsort.txt";
char pathsortbyci[512] = "G:\\QQpasswordsortci.txt";

#define N 15186998

struct info{
	char str[17];
};

int com(void *p1,void *p2) {
	struct info *pinfo1 = p1;
	struct info *pinfo2 = p2;
	return strcmp(pinfo1->str, pinfo2->str);						//����ĺ���
}

struct info *pall = NULL;

void writetofile() {
	FILE *pf = fopen(pathsortbypass, "w");
	for (int i = 0; i < N; i++) {
		int j = 1;													//����һ��
		while (strcmp(pall[i].str, pall[i + 1].str) == 0) {
			i++;													//ѭ��ǰ��
			j++;													//����
		}
	}

	fclose(pf);
}


void writetofile_test() {
	//int a[10] = { 1,2,3,1,2,1,3,2,4,1 };
	int a[10] = { 1,1,1,1,2,2,2,3,3,4 };

	//	1111 222 33 4
	//1 4
	//2 3
	//3 2
	//4 1
	for (int i = 0; i < 10; i++) {
		printf("%d", a[i]);
		int j = 1;
		while (a[i] == a[i + 1]) {
			i++;								//ѭ����ȥ
			j++;								//����
		}
		printf("%d\n", j);
	}

}

void sort() {
	time_t start, end;
	time(&start);

	qsort(pall, N, sizeof(struct info), com);

	time(&end);
	printf("�ļ���ȡ����%f��", difftime(end, start));

}

void init() {

	time_t start, end;
	time(&start);

	pall = calloc(N, sizeof(struct info));					//�����ڴ�
	if (pall == NULL) {
		puts("calloc fail!");
		return;
	}
	FILE *pf = fopen(path, "r");
	for (int i = 0; i < N; i++) {
		char str[50] = { 0 };
		fgets(str, 50, pf);
		char *pfind = strstr(str, "----");
		//45342543----qwrereres
		if (pfind != NULL) {
			int length = strlen(pfind + 4);
			if (length < 17) {								//ˢ���Ƿ�����
				strcpy(pall[i].str, pfind + 4);
			}
		}
	}

	fclose(pf);
	time(&end);
	printf("�ļ���ȡ����%f��", difftime(end, start));
}


int getN(char *path) {
	int i = 0;
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
		}
		fclose(pf);
		return i;
	}
}

void main() {
	//printf("%d", getN(path));
	writetofile();
	system("pause");
}
