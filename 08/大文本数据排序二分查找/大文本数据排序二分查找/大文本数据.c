#define  _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **g_pp;														//����ָ������

#define N 33

struct index {
	int *pindex;
	int lenght;
}allindex;															//����


int getN() {
	FILE *pf = fopen("file.txt", "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		int i = 0;
		while (!feof(pf)) {
			char str[50];
			fgets(str, 50, pf);										 //��ȡ
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
	g_pp = calloc(N, sizeof(char *));						    	//����ָ������
	FILE *pf = fopen("file.txt", "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);								   	    //��ȡ
			g_pp[i] = calloc(strlen(str) + 1, sizeof(char));
			eatN(g_pp[i]);

			sprintf(g_pp[i], str);									//��ӡ��ȥ
			eatN(g_pp[i]);
			printf("%s", g_pp[i]);									//��ʾ����
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




void main() {
	int num = 0;
	//scanf("%d", &num);
	//printf("%d", getN());
	initmem();
	sort();
	show();

	writetofile();

	system("pause");
}