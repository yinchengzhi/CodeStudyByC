#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ȡ������ ,��������a[N]
//��ȡÿһ�еĿ�� a[N] = Width
//��ȡ��ÿһ���ַ�������\r\n

int getN() {
	int i = -1;
	FILE *pf = fopen("test.txt", "rb");
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
			printf("%d %s", strlen(str), str);
			i++;
		}
		printf("\nalll = %d\n", alllength);
		fclose(pf);
		return i;
	}
}

void main() {

	printf("\n�� = %d", getN());

	system("pause");
}