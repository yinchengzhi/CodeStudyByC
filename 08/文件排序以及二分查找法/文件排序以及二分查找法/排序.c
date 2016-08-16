#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//文件排序
//内存排序

void main1x() {
	time_t ts;
	unsigned int num = time(&ts);									//获取随机数种子
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
		return 1;							//大于
	}
	else if (*pint1 < *pint2) {
		return -1;							//小于
	}
	else {
		return 0;
	}
}


//读取到内存，然后排序
void memsort() {
	int *p = malloc(400);
	int *pread = malloc(400);
	FILE *pf = fopen("G:\\1.data", "rb+");
	fread(p, sizeof(int), 100, pf);
	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	fflush(pf);											//刷新，生效
	qsort(p, 100, 4, com);								//排序
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
		fseek(pf, i * sizeof(int), SEEK_SET);							//i顺序，99-i是逆序
		fread(&num, sizeof(int), 1, pf);

		if (num == 3) {
			printf("%d", num);											//顺序查找	100
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
	int number = 0;														//记录二分查找的次数

	while (head <= tail) {
		number++;														//找的次数
		int middle = (head + tail) / 2;
		int middleData;

		fseek(pf, middle * sizeof(int), SEEK_SET);						//i顺序，99-i是逆序
		fread(&middleData, sizeof(int), 1, pf);

		if (findnum == middleData) {
			flag = 1;													//找到
			printf("找到%d\n", middleData);
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
		printf("找到了\n");
	}
	else {
		printf("没找到\n");
	}

	printf("找了%d次\n", number);

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
	printf("\n排序之前\n");

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