#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void main1() {

	FILE *pf = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpass.txt", "r");
	while (!feof(pf)) {
		char str[256] = { 0 };
		fgets(str, 255, pf);							//��ȡ����ȡ�ַ������׵�ַ,255��󳤶ȣ�pf�ļ�ָ��
		printf("%s", str);
	}

	fclose(pf);

	system("pause");
}

void main2() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QQpass\\QQpass.txt", "r");
	FILE *pfw = fopen("f:\\QQpassA.txt", "w");

	//while (!feof(pfr)) {
	//	char str[256] = { 0 };
	//	fgets(str, 255, pfr);							//��ȡ����ȡ�ַ������׵�ַ,255��󳤶ȣ�pf�ļ�ָ��
	//	fputs(str, pfw);
	//	printf("%s", str);
	//}

	char str[256] = { 0 };
	while (fgets(str, 255, pfr) != NULL) {				//��ȡ�ɹ�. str,��ȡʧ��NULL
		//fputs(str, pfw);
		int length = fputs(str, pfw);					//����ֵ�����һ���ַ���������EOF
		printf("\n%d", length);
	}

	fclose(pfr);
	fclose(pfw);

	system("f:\\QQpassA.txt");
	system("pause");
}