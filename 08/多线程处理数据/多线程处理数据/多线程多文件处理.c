#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include<process.h>
#include<Windows.h>

struct infos{
	char path[256];													//ԭʼ
	int id;

	char **g_pp;													//���ļ������ݣ����������ַ
	int length;

	char findstr[100];												//��ѯ
}myinfo[22] = { 0 };												//22���ṹ�屣����22���ļ�����Ϣ

HANDLE inithd[22] = { 0 };											//22����ʼ���̵߳�ַ
HANDLE findhd[22] = { 0 };											//22�������̵߳�ַ
void runthreadinit(void *p) {
	struct infos *pinfo = p;
	FILE *pf = fopen(pinfo->path, "r");
	if (pf != NULL) {
		int i = 0;													//���Զ�����
		while (!feof(pf)) {
			char str[256] = { 0 };
			fgets(str, 256, pf);									//��ȡ
			i++;
		}
		//i ��¼����
		rewind(pf);													//�ص�����		fseek(pf,0,SEEK_SET);
		pinfo->g_pp = calloc(i, sizeof(char*));						//�����ڴ��ʼ��
		pinfo->length = i;											//��¼����

		for (int j = 0; j < i; j++) {
			char str[256] = { 0 };
			fgets(str, 256, pf);									//��ȡ

			int length = strlen(str);
			pinfo->g_pp[j] = calloc(length + 1, sizeof(char));		//�����ڴ沢�ҳ�ʼ��

			if (pinfo->g_pp[j] != NULL) {
				strcpy(pinfo->g_pp[j], str);						//�����ڴ�
			}
		}

	}
	fclose(pf);

	printf("�߳�%d init over\n", pinfo->id);
}

void runthreadsearch(void *p) {
	struct infos *pinfo = p;
	for (int i = 0; i < pinfo->length; i++) {
		if (pinfo->g_pp[i] != NULL) {
			char *px = strstr(pinfo->g_pp[i], pinfo->findstr);
			if (px != NULL) {
				printf("\n%s", pinfo->g_pp[i]);
			}
		}
	}

	printf("�߳�%d find over\n", pinfo->id);
}

void main1x() {

	myinfo[0].id = 1;
	strcpy(myinfo[0].path, "G:\\BigData.txt");
	HANDLE pd1 = _beginthread(runthreadinit, 0, &myinfo[0]);
	WaitForSingleObject(pd1, INFINITE);												//�ȴ�
	strcpy(myinfo[0].findstr, "34243524");											//������һ������

	HANDLE pd2 = _beginthread(runthreadsearch, 0, &myinfo[0]);
	WaitForSingleObject(pd2, INFINITE);

	system("pause");
}

void main() {
	for (int i = 0; i < 22; i++) {
		myinfo[i].id = i + 1;
		sprintf(myinfo[i].path, "G:\\BigData.txt", i + 1);
		strcpy(myinfo[i].findstr, "34243524");
	}

	for (int i = 0; i < 15; i++) {
		inithd[i] = _beginthread(runthreadinit, 0, &myinfo[i]);
	}

	WaitForMultipleObjects(15, inithd, TRUE, INFINITE);					//�ȴ�
	system("pause");
	
	for (int i = 0; i < 15; i++) {
		findhd[i] = _beginthread(runthreadsearch, 0, &myinfo[i]);
	}


	system("pause");
}