#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ȡ������ ,��������a[N]
//��ȡÿһ�еĿ�� a[N] = Width
//��ȡ��ÿһ���ַ�������\r\n

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

			allindex.pindex[i] = alllength;
			alllength += strlen(str);
			printf("%d %s", strlen(str), str);
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
			printf("i=%d index[%d] = %d,with = %d", i, i, allindex.pindex[i], strlen(str));
			i++;
		}

		fclose(pf);
		return i;
	}
}

void main() {

	allindex.lenght = getN();
	printf("\n�� = %d", allindex.lenght);
	allindex.pindex = calloc(allindex.lenght, sizeof(int));


	system("pause");
}