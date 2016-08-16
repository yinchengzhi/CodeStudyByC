#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//�ļ�����
//�ڴ�����

void main1x() {
	time_t ts;
	unsigned int num = time(&ts);									//��ȡ���������
	srand(num);

	int a[100];
	for (int i = 0; i < 100; i++) {
		a[i] = rand() % 100;
	}

	FILE *pf = fopen("G:\\1.data", "wb");
	fwrite(a, sizeof(int), 100, pf);
	fclose(pf);
	system("pause");
}


int com(void *p1, void *p2) {
	int *pint1 = p1;
	int *pint2 = p2;
	if (*pint1 > *pint2) {
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
	FILE *pf = fopen("G:\\1.data", "rb+");
	fread(p, sizeof(int), 100, pf);
	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	fflush(pf);											//ˢ�£���Ч
	qsort(p, 100, 4, com);								//����
	printf("\nsort later\n");
	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	rewind(pf);
	fwrite(p, sizeof(int), 100, pf);
	fflush(pf);

	rewind(pf);
	fread(pread, sizeof(int), 100, pf);
	fflush(pf);

	for (int i = 0; i < 100; i++) {
		printf("\npread=%d", pread[i]);
	}

	fclose(pf);
}


void fileread() {
	FILE *pf = fopen("G:\\1.data", "rb");
	for (int i = 0; i < 100; i++) {
		int num;
		fseek(pf, i * sizeof(int), SEEK_SET);							//i˳��99-i������
		fread(&num, sizeof(int), 1, pf);

		if (num == 3) {
			printf("%d", num);											//˳�����	100
		}
		printf("\nnum=%d", num);
	}
	fclose(pf);
}

void binsearch(int findnum) {
	FILE *pf = fopen("G:\\1.data", "rb");
	int head = 0;
	int tail = 99;
	int flag = 0;
	int number = 0;														//��¼���ֲ��ҵĴ���

	while (head <= tail) {
		number++;														//�ҵĴ���
		int middle = (head + tail) / 2;
		int middleData;

		fseek(pf, middle * sizeof(int), SEEK_SET);						//i˳��99-i������
		fread(&middleData, sizeof(int), 1, pf);

		if (findnum == middleData) {
			flag = 1;													//�ҵ�
			printf("�ҵ�%d\n", middleData);
			break;
		}
		else if (findnum > middleData) {
			head = middleData + 1;
		}
		else {
			tail = middleData - 1;
		}
	}

	if (flag) {
		printf("�ҵ���\n");
	}
	else {
		printf("û�ҵ�\n");
	}

	printf("����%d��\n", number);

	fclose(pf);

}

void main3x() {

	//memsort();
	fileread();

	while (1) {
		int findnum;
		scanf("%d", &findnum);
		binsearch(findnum);
	}

	system("pause");
}

void showfile() {
	int *p = malloc(400);
	FILE *pf = fopen("G:\\sort.data", "rb");
	fread(p, sizeof(int), 100, pf);
	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	fclose(pf);
}


void main() {
	
	showfile();
	printf("\n����֮ǰ\n");

	FILE *pf = fopen("G:\\sort.data", "rb+");
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1; j++) {
			int dataj = 0;
			fseek(pf, sizeof(int)*j, SEEK_SET);
			fread(&dataj, sizeof(int), 1, pf);

			int dataj1 = 0;
			fseek(pf, sizeof(int)*(j + 1), SEEK_SET);
			fread(&dataj1, sizeof(int), 1, pf);

			if (dataj < dataj1) {
				fseek(pf, sizeof(int)*(j + 1), SEEK_SET);
				fwrite(&dataj, 4, 1, pf);
				fseek(pf, sizeof(int)*j, SEEK_SET);
				fwrite(&dataj1, 4, 1, pf);
			}

			/*
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
			*/

		}
	}

	fclose(pf);

	showfile();

	system("pause");
}