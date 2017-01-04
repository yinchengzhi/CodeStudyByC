#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char path[256] = "G:\\BigData.txt";
char index_path[256] = "G:\\QQindex8848.txt";
char sort_index_path[256] = "G:\\QQsort_index8848.txt";

//#define ALLN 84331072				//�ҵ����ݸ���û��8000����
#define ALLN 18175317				//��������,ÿ��12�ֽ�,208M * 1024 * 1024 / 12 �Ľ��

struct INDEX{
	long long QQ;
	int index;

};

typedef struct INDEX Index;

void getQQ(char *str, char *tmp) {
	int length = strlen(str);
	strcpy(tmp, str);
	char *p = tmp;
	while (*p) {
		if (*p == '-') {
			*p = '\0';
			break;
		}
		p++;
	}
}

void main1() {

	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(index_path, "wb");

	while (!feof(pfr)) {
		int index = ftell(pfr);								//��ȡ��ǰ�ļ�ָ����뿪ͷ��λ��
		char str[50] = { 0 };
		fgets(str, 50, pfr);								//��ȡ
		char tmp[50] = { 0 };
		getQQ(str, tmp);									//��ȡ
		long long lltmp = atoll(tmp);						//����QQ
		
		if (lltmp == 0) {
			continue;
		}
		Index in1 = { 0 };
		in1.QQ = lltmp;
		in1.index = index;
		fwrite(&in1, sizeof(in1), 1, pfw);

	}


	fclose(pfr);
	fclose(pfw);

	printf("����OK");

	system("pause");
}

int com(void *p1, void *p2) {
	Index *pl1 = p1;
	Index *pl2 = p2;
	if (pl1->QQ > pl2->QQ) {
		return 1;
	}
	else if (pl1->QQ < pl2->QQ) {
		return -1;
	}
	else {
		return 0;
	}
}

void main() {

	FILE *pfr = fopen(index_path, "rb");
	FILE *pfw = fopen(sort_index_path, "wb");
	Index *p = malloc(ALLN * sizeof(Index));
	fread(p, sizeof(Index), ALLN, pfr);

	qsort(p, sizeof(Index), ALLN, com);

	fwrite(p, sizeof(Index), ALLN, pfw);


	fclose(pfr);
	fclose(pfw);

	system("pause");
}