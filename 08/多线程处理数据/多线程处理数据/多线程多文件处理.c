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
}myinfo[22];														//22���ṹ�屣����22���ļ�����Ϣ


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
	else {

	}
	fclose(pf);
}

void runthreadsearch(void *p) {

}

void main() {

}