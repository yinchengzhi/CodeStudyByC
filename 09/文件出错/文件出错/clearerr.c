#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//perror ��ʾ�ļ�������Ϣ
//ferror ����ļ��쳣������
//clearerr ����쳣

void main() {

	FILE *pf = fopen("G:\\51.txt", "w");
	if (pf == NULL) {
		perror("\n�����ǣ�");									//��ʾ�ļ�������Ϣ
	}

	fputs("hello china", pf);
	rewind(pf);													//�ƶ����ļ���ͷ

	if (fgetc(pf) == EOF) {										//EOF�����ֿ��ܣ�EOF�������ڶ��ֳ���
		if (feof(pf)) {
			printf("�����ļ�ĩβ\n");
			clearerr(pf);
		}
		if (ferror(pf)) {
			printf("�쳣\n");
			clearerr(pf);										//���ļ�ָ��ص���ͷ
		}
	}
	
	//int ch = fgetc(pf);
	//if (ch == EOF) {
	//	printf("error");
	//}

	fclose(pf);

	//if (ferror(pf) == 0) {									//�ļ���ʧ�ܵ�����£��������������ʾ�쳣
	//	printf("����\n");
	//}
	//else {
	//	printf("�쳣\n");
	//}

	//fclose(pf);

	system("pause");
}