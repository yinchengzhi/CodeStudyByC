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
	int num = fwrite(a, sizeof(int), 100, pf);						//��һ���ڴ��׵�ַ���ڶ���Ԫ�ش�С��������������С
	printf("fwrite return = %d", num);								//����д��ɹ��ĸ���,ʧ�ܷ���0
	fclose(pf);
	system("pause");
}

void read() {

	void *p = malloc(400);
	printf("%p\n", p);
	FILE *pf = fopen("F:\\1.bin", "rb");
	int num = fread(p, 4, 100, pf);									//��һ���ڴ��׵�ַ���ڶ���Ԫ�ش�С��������������С
	printf("fread return = %d", num);								//����д��ɹ��ĸ���,ʧ�ܷ���0
	fclose(pf);
}

void main() {
	

	read();


	system("pause");
}