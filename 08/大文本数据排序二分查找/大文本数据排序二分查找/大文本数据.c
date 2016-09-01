#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **g_pp;																				//����ָ������

#define N 33

struct index {
	int *pindex;
	int length;
}allindex;																					//����


int getN() {
	FILE *pf = fopen("file.txt", "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		int i = 0;
		while (!feof(pf)) {
			char str[50];	
			fgets(str, 50, pf);																 //��ȡ
			i++;
		}
		fclose(pf);
		return i;
	}
}

void eatN(char *str) {
	while (*str != '\0') {
		if (*str == '\r' || *str == '\n') {
			*str = '\0';
		}
		str++;
	}
}

void initmem() {
	g_pp = calloc(N, sizeof(char *));						    							//����ָ������
	FILE *pf = fopen("file.txt", "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);							    	   						  //��ȡ
			g_pp[i] = calloc(strlen(str) + 1, sizeof(char));
			eatN(g_pp[i]);

			sprintf(g_pp[i], str);					     							  	 //��ӡ��ȥ
			eatN(g_pp[i]);
			printf("%s", g_pp[i]);														//��ʾ����
		}
	}
}

int com(void *p1, void *p2) {
	char **pp1 = p1;
	char **pp2 = p2;

	return strcmp(*pp1, *pp2);
}

void sort() {
	qsort(g_pp, N, sizeof(char *), com);
}

void show() {
	printf("\n��ʱ״̬:\n");
	for (int i = 0; i < N; i++) {
		printf("\n%s", g_pp[i]);
	}
}

void writetofile() {
	FILE *pf = fopen("filesort.txt", "w");
	
	for (int i = 0; i < N; i++) {
		char temp[100] = { 0 };
		sprintf(temp, "%s\n", g_pp[i]);
		fputs(temp, pf);
	}

	fclose(pf);
}


void init(char *path) {

	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));											//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");

	FILE *pf = fopen("filesort.txt", "rb");												// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {

		int alllength = 0;

		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);

			allindex.pindex[i] = alllength;											//��λ , ��0��ʼ
			int length = strlen(str);
			alllength += length;
			allindex.pindex[i] = alllength;
		}
		fclose(pf);
	}

	printf("������ȡ\n");

	printf("��ʼд��\n");
	FILE *pfw = fopen("index.txt", "wb");											//д������
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("����д��\n");

	free(allindex.pindex);

	printf("��ʼ��ȡ\n");
	FILE *pfr1 = fopen("index.txt", "rb");											//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr1);
	fclose(pfr1);
	printf("������ȡ\n");

}


void quick() {
	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));										//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");
	FILE *pfr = fopen("index.txt", "rb");											//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr);
	fclose(pfr);
	printf("������ȡ\n");

}


void main�ڴ�����() {
	int num = 0;
	//scanf("%d", &num);
	//printf("%d", getN());
	//initmem();
	//sort();
	//show();
	//writetofile();

	//init("filesort.txt");

	quick();
	FILE *pf = fopen("filesort.txt", "rb");
	while (1) {
		printf("\n������Ҫ��ȡ������:");
		int num = 0;
		scanf("%d", &num);
		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf);										//��ȡ
		printf("%s", str);
	}

	fclose(pf);

	system("pause");
}



void main�����ļ�() {

	FILE *pf1 = fopen("index.txt", "rb");
	FILE *pf2 = fopen("filesort.txt", "rb");

	while (1) {
		printf("\n������Ҫ��ȡ������:");
		int num = 0;
		scanf("%d", &num);

		int indexnum = 0;
		fseek(pf1, num * sizeof(int), SEEK_SET);
		fread(&indexnum, sizeof(int), 1, pf1);						//��������indexnum

		fseek(pf2, indexnum, SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf2);										//��ȡ
		printf("\n%s", str);
	}

	fclose(pf1);
	fclose(pf2);

	system("pause");
}

void binsearch() {
	int tou = 0;
	int wei = N - 1;
	while (tou <= wei) {
		int zhong = (tou + wei) / 2;
		FILE *pf1 = fopen("index.txt", "rb");
		FILE *pf2 = fopen("filesort.txt", "rb");

		int indexnum = 0;
		fseek(pf1, num * sizeof(int), SEEK_SET);
		fread(&indexnum, sizeof(int), 1, pf1);						//��������indexnum

		fseek(pf2, indexnum, SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf2);										//��ȡ
		printf("\n%s", str);

		fclose(pf1);
		fclose(pf2);
	}
}

void main() {
	char str[256] = { 0 };
	scanf("%s", str);
	binsearch(str);

	system("pause");
}