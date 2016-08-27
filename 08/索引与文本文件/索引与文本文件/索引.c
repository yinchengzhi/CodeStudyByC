#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//获取多少行 ,创建数组a[N]
//获取每一行的宽度 a[N] = Width
//读取的每一个字符串都有\r\n

struct index {
	int *pindex;
	int lenght;
}allindex;


int getN() {
	int i = -1;
	FILE *pf = fopen("test.txt", "rb");					// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {
		int alllength = 0;
		i = 0;
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			alllength += strlen(str);
			printf("%d %d %s", strlen(str), i, str);
			i++;
		}
		printf("\nalll = %d\n", alllength);
		fclose(pf);
		return i;
	}
}

void initindex() {
	int i = -1;
	FILE *pf = fopen("test.txt", "rb");					// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {
		int alllength = 0;
		i = 0;
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			allindex.pindex[i] = alllength;
			alllength += strlen(str);
			printf("\ni=%d index[%d] = %d,with = %d", i, i, allindex.pindex[i], strlen(str));
			i++;
		}

		fclose(pf);
		return i;
	}
}

void main() {

	allindex.lenght = getN();
	printf("\n行 = %d", allindex.lenght);
	allindex.pindex = calloc(allindex.lenght, sizeof(int));
	initindex();

	FILE *pf = fopen("test.txt", "rb");
	while (1) {
		int num = 0;
		scanf("%d", &num);
		fseek(pf, allindex.pindex[num], SEEK_SET);
		char str[128] = { 0 };
		fgets(str, 128, pf);								//读取
		printf("%s", str);
	}

	fclose(pf);

	system("pause");
}