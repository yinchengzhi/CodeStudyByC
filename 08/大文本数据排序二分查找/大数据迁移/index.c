#include"index.h"


char **g_pp = NULL;													//����ָ������
char filepath[256] = { 0 };
char sortpath[256] = { 0 };
char indexpath[256] = { 0 };
struct index allindex = { 0 };										//����


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

void eatg(char *str) {
	while (*str != '\0') {
		if (*str == '-') {
			*str = '\0';
		}
		str++;
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