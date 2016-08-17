#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//内存排序

void main1() {
	time_t ts;
	unsigned int num = time(&ts);			//获取随机数种子
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

void main() {
	int *p = malloc(400);
	FILE *pf = fopen("G:\\test.data", "rb");
	fread(p, sizeof(int), 100, pf);
	fclose(pf);

	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	system("pause");

}