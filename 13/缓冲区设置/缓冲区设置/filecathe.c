#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����壬������д
//�л��壬һ�о�д
//�޻���

//Ĭ�ϵ����������ϵͳ�����������
//�Լ���


//#define _IOFBF 0x0000				full	�����������ٸɻ�
//#define _IOLBF 0x0040				line	�л���
//#define _IONBF 0x0004				No		�޻���


void main() {

	char str[4096] = { 0 };
	setvbuf(stdout, str, _IOLBF, 4096);
	fprintf(stdout, "hello fang\n");
	char *p = strstr(str, "\n");
	if (p != NULL) {
		fflush(stdout);
	}

	//printf("Hello World");

	//fflush(stdout);
	
	system("pause");
}

void main2() {
	FILE *pf = fopen("G:\\����������2.txt", "w");
	setvbuf(pf, NULL, _IONBF, 0);

	fputs("1234567890", pf);


	system("pause");
}
