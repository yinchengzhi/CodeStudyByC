#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//ferror�������쳣��������
//ÿ��дһ��,�Ͳ���һ��ferror
//0 ����������1�����쳣

void main2() {
	FILE *pf = fopen("G:\\SmallData.txt", "r");
	if (pf == NULL) {
		printf("open fail!\n");
	}
	else {
		printf("open success!\n");
	}


	if (ferror(pf) == 0) {									//�ļ���ʧ�ܵ�����£��������������ʾ�쳣
		printf("����\n");
	}
	else {
		printf("�쳣\n");
	}

	fputs("1234", pf);

	if (ferror(pf)==0) {									//�ļ���ʧ�ܵ�����£��������������ʾ�쳣
		printf("����\n");
	}
	else {
		printf("�쳣\n");
	}


	system("pause");
}