#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
�ı��ļ���������ļ����������ڣ�Windows��
д���ʱ���ı��Ὣ���з�10\n,ASII�����Ϊ�س��� 13\r�����з�10\n
��ȡ��ʱ�򣬻Ὣ����һ��Ļس���13\r�����з�10\n����Ϊ���з�10

�ı��ļ���������ļ���д�޲��(Linux)
*/


void readfile(char *path) {
	FILE *pf = fopen(path, "rb");					//�����ƶ�ȡ��ʽ��ȡ��ԭ�ⲻ��
	char ch;
	fread(&ch, 1, 1, pf);							//��ȡһ��Ԫ��
	while (!feof(pf)) {
		printf("%d ", ch);							//��ӡASCII��
		fread(&ch, 1, 1, pf);						//��ȡһ��Ԫ��
	}

	fclose(pf);										//�ر��ļ�ָ��
}


void main() {
	char buf[5] = { 10,10,10,10,10 };				//��ʼ���ַ�����,ÿ��Ԫ�ض��ǻ��з�10
	FILE *pfa;										//�����ı���ASCII���ı�
	FILE *pfb;										//����bin�������Ƶ��ļ�
	char patha[40] = "F:\\a.c";						//�ı���·��
	char pathb[40] = "F:\\b.c";						//�����Ƶ�·��

	pfa = fopen(patha, "w");						//���ն������ı�д��ķ�ʽ���ļ�
	if (pfa == NULL) {
		printf("�������ļ���ʧ��");
	}
	else {
		fwrite(buf, 1, 5, pfa);
		//д�����飬���������׵�ַ,Ԫ�ش�СΪ1��5��Ԫ���Լ��ļ�ָ��
		fclose(pfa);								//�ر��ļ�ָ��
	}
	pfb = fopen(pathb, "wb");						//���ն������ı�д��ķ�ʽ���ļ�
	if (pfb == NULL) {
		printf("�������ļ���ʧ��");
	}
	else {
		fwrite(buf, 1, 5, pfa);
		//д�����飬���������׵�ַ,Ԫ�ش�СΪ1��5��Ԫ���Լ��ļ�ָ��
		fclose(pfb);								//�ر��ļ�ָ��
	}

	printf("\n");
	printf("�ı�д���ȡ������!");
	printf("\n");
	readfile(patha);

	printf("\n");
	printf("������д���ȡ������!");
	printf("\n");
	readfile(pathb);

	system("pause");
}