#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//���������							txt
//�����������						bin

void jia(char *path,char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	char ch = 0;

	while ((ch = fgetc(pfr))!=EOF) {								//�����ַ�EOF������
		ch += 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

}

void jie(char *path, char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	char ch = 0;

	while ((ch = fgetc(pfr))!=EOF) {								//�����ַ�EOF������
		ch -= 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

}

void main() {

	char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt";
	char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjia.txt";
	char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\Qjie.txt";
	jia(path, pathjia);
	jie(pathjia, pathjie);

	system("pause");
}



void main4() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\Q.txt", "r");
	FILE *pfw = fopen("C:\\Users\\Ollydebug\\Desktop\\test1\\QTX.txt", "w");

	//���һ���ַ�EOF
	//while (!feof(pfr)) {
	//	char ch = fgetc(pfr);										//��ȡ��
	//	fputc(ch, pfw);
	//}

	char ch = 0;
	while (ch != EOF) {												//EOF�ļ�����
		ch = fgetc(pfr);											//��ȡ
		if (ch != EOF) {
			fputc(ch, pfw);
		}
	}

	//while ((ch = fgetc(pfr))!=EOF) {								//�����ַ�EOF������
	//	fputc(ch, pfw);
	//}

	fclose(pfr);
	fclose(pfw);

	system("C:\\Users\\Ollydebug\\Desktop\\test1\\QTX.txt");

	system("pause");
}