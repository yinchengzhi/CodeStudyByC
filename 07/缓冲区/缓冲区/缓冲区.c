#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>



void main1() {

	FILE *pf = fopen("D:\\11.txt", "w");
	fputs("��ã�����", pf);							//������

	fclose(pf);										//�ر��ļ���ʱ�򣬽�����������д�뵽�ı�

	system("pause");
}