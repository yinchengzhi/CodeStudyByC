#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main1() {

	FILE *pf = fopen("G:\\SmallData.txt", "w");
	if (pf == NULL) {
		perror("\n�����ǣ�");									//��ʾ�ļ�������Ϣ
	}

	fputs("haihua", pf);
	fclose(pf);
	system("pause");
}

