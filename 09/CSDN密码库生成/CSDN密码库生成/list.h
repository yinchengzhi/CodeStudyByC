#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct passinfo{
	char password[20];
	int ci;
	struct passinfo *pNext;
}INFO, *PINFO;


PINFO addback(PINFO phead, char password[20]);						//β������
PINFO sortByci(PINFO phead);										//����
PINFO sortBypass(PINFO phead);										//����
PINFO show(PINFO phead);											//��ʾ
int isin(PINFO phead, char password[20]);							//�жϴ������
void writetofile(PINFO phead,char path[100]);						//д�뵽�ļ�