#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

char *path = "G:\\BigData.txt";				//·��

#define allN 15186998-1
#define Max 37

char **pp = NULL;

int getN() {
	int i = 0;
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
		}

		fclose(pf);
		return i;
	}
}

int GetMax() {
	int i = -1;
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 37, pf);
			int length = strlen(str);										//��ȡ�ַ�������
			if (length > i) {
				i = length;
			}
		}

		fclose(pf);
		return i;
	}
}




void init() {

	pp = (char **)malloc(sizeof(char*)*allN);								//����һ��ָ������

	memset(pp, 0, sizeof(char*)*allN);										//����ڴ�,��������ڴ�

	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < allN; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			pp[i] = calloc(strlen(str) + 1, sizeof(char));					//Ϊÿһ��ָ������ڴ�
			if (pp[i] != NULL) {											//�����ڴ����ʧ��
				strcpy(pp[i], str);											//�����ڴ�
			}
			else {
				printf("�ڴ�ʧ��!");
			}
		}

		printf("�ڴ�������!\n");
		fclose(pf);															//�ر��ļ�ָ��
	}
}

void search(char *searchstr) {
	for (int i = 0; i < allN; i++) {
		if (pp[i] != NULL) {												//Ϊ�ղ��ز���

			char *p = strstr(pp[i], searchstr);								//����
			if (p != NULL) {
				printf("%s\n", pp[i]);										//��ӡ���
			}
		}
	}
}


void main() {
	//printf("%d", GetMax());

	init();
	int i = 0;
	while (1) {
		char searchstr[100] = { 0 };
		scanf("%s", searchstr);
		search(searchstr);
		i += 1;
		printf("��%d�μ������",i);
		getchar();

	}


	system("pause");

}