#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�ڴ�����

void main1() {
	time_t ts;
	unsigned int num = time(&ts);			//��ȡ���������
	srand(num);
	int a[100];

	for (int i = 0; i < 100; i++) {
		a[i] = rand() % 100;
	}

	FILE *pf = fopen("G:\\test.data", "wb");
	fwrite(a, sizeof(int), 100, pf);
	fclose(pf);

	system("pause");
}

int com(void*p1, void *p2) {
	int *pint1 = p1;
	int *pint2 = p2;
	if (*pint1>*pint2) {
		return 1;							//����
	}
	else if (*pint1 < *pint2) {
		return -1;							//С��
	}
	else {
		return 0;
	}
}


//��ȡ���ڴ棬Ȼ������
void memsort() {

	int *p = malloc(400);
	int *pread = malloc(400);

	FILE *pf = fopen("G:\\test.data", "rb+");
	fread(p, sizeof(int), 100, pf);

	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	fflush(pf);							//ˢ�� ��Ч

	qsort(p, 100, 4, com);				//����

	printf("sort later\n");

	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	rewind(pf);
	fwrite(p, sizeof(int), 100, pf);
	fflush(pf);							//ˢ�� ��Ч

	rewind(pf);
	fread(pread, sizeof(int), 100, pf);
	fflush(pf);							//ˢ�� ��Ч

	for (int i = 0; i < 100; i++) {
		printf("\npread=%d", pread[i]);
	}

	fclose(pf);
}

void main() {

	memsort();
	system("pause");

}