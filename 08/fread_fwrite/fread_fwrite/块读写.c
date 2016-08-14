#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void write() {
	int a[100];

	printf("%p", a);
	for (int i = 0; i < 100; i++) {
		printf("\n%d", a[i] = i);
	}

	FILE *pf = fopen("F:\\1.bin", "wb");
	int num = fwrite(a, sizeof(int), 100, pf);						//第一个内存首地址，第二个元素大小，第三个个数大小
	printf("fwrite return = %d", num);								//返回写入成功的个数,失败返回0
	fclose(pf);
	system("pause");
}

void read() {

	void *p = malloc(400);
	printf("%p\n", p);
	FILE *pf = fopen("F:\\1.bin", "rb");
	int num = fread(p, 4, 100, pf);									//第一个内存首地址，第二个元素大小，第三个个数大小
	printf("fread return = %d", num);								//返回写入成功的个数,失败返回0
	fclose(pf);
}

void main() {
	

	read();


	system("pause");
}