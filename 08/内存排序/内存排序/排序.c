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

int com(void*p1, void *p2) {
	int *pint1 = p1;
	int *pint2 = p2;
	if (*pint1>*pint2) {
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

	FILE *pf = fopen("G:\\test.data", "rb+");
	fread(p, sizeof(int), 100, pf);

	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	fflush(pf);							//刷新 生效

	qsort(p, 100, 4, com);				//排序

	printf("sort later\n");

	for (int i = 0; i < 100; i++) {
		printf("\n%d", p[i]);
	}

	rewind(pf);
	fwrite(p, sizeof(int), 100, pf);
	fflush(pf);							//刷新 生效

	rewind(pf);
	fread(pread, sizeof(int), 100, pf);
	fflush(pf);							//刷新 生效

	for (int i = 0; i < 100; i++) {
		printf("\npread=%d", pread[i]);
	}

	fclose(pf);
}

void main() {

	memsort();
	system("pause");

}