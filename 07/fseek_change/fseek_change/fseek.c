#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
void showp(FILE *p) {
	printf("\n\n");
	printf("\n��������Ч����%d", p->_cnt);
	printf("\n������ָ��%p,%c", p->_ptr, *(p->_ptr));
	printf("\n��������ʼ��ַ%p", p->_base);
	printf("\n�������Ĵ�С%d", p->_bufsiz);
	printf("\n���������ļ�����%d", p->_file);
}

int main() {

	char x;
	showp(stdin);
	x = getchar();
	putchar(x);
	showp(stdin);
	x = getchar();
	showp(stdin);
	x = getchar();
	showp(stdin);
	fflush(stdin);
	showp(stdin);


	char path[150] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt";
	FILE *pf = fopen(path, "r");
	while (!feof(pf)) {
		char ch = fgetc(pf);
		showp(pf);
	}

	fclose(pf);


	system("pause");
	return 0;
}

*/

void main2() {

	char path[150] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt";
	//FILE *pf = fopen(path, "a+");					//β�����,�ļ�ָ����β��
	//FILE *pf = fopen(path, "w+");					//�ļ�ָ����ͷ��,�������
	FILE *pf = fopen(path, "r+");					//�ļ�ָ����ͷ��,���������
	
	fseek(pf, 0, SEEK_END);
	fputs("0000000", pf);

	fflush(pf);										//ˢ���ļ�

	//����
	int length = 10;
	for (int i = 0; i < 10; i++) {

		fseek(pf, -7 - i - 1, SEEK_END);
		int ch = fgetc(pf);
		//#define SEEK_CUR	1	��ǰ
		//#define SEEK_END	2	����
		//#define SEEK_SET	0	��ͷ

		fseek(pf, -i - 1, SEEK_END);
		fputc(ch,pf);

		fflush(pf);										//ˢ���ļ�

	}

	fseek(pf, -17, SEEK_END);						//a+ �ļ�ָ���ƶ���Ч
													//r+ �ļ�����
	fputs("abcdefg",pf);

	fclose(pf);

	system("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt");
	system("pause");
}