#define  _CRT_SECURE_NO_WARNINGS

struct MyStructX{
	double db;
};

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
union pc{
	struct MyStructX my;
	int num;				//3000
	char price[10];			//����,����
	char *p;				//�����ڴ�,malloc
}pc2 = {.num=1000};

struct MyStruct{
	union pc pc1;
};


void main() {
	union pc pc1;
	pc1.p = malloc(100);
	strcpy(pc1.p, "����װ�ĵ��ԣ��۸�δ֪");
	union pc pc2 = pc1;				//ǳ����
	pc2.p = malloc(100);			//���
	strcpy(pc2.p, pc1.p);
	printf("%s\n%s\n", pc1.p, pc2.p);
	free(pc1.p);
	printf("%s\n%s\n", pc1.p, pc2.p);

	system("pause");
}


void main1() {
	union pc pc1;
	pc1.p = malloc(100);
	strcpy(pc1.p,"����װ�ĵ��ԣ��۸�δ֪");
	pc1.num = 4000;			//�ı�һ������,Ӱ������������	

	printf("%s", pc1.p);
	free(pc1.p);			//���صĴ���
	system("pause");
}


void main2() {

	//�����ʼ����һ����ʽ������������������������
	union pc pc1 = { 1000 };
	union pc pc[3] = { { 1000 } ,{ 1000 } ,{ 1000 } };
	union pc *p =(union pc[]){ { 1000 } ,{ 1000 } ,{ 1000 } };

	//pc1++;
	//pc1==pc2;		//������������ó�Ա��������������
	//pc1.num++;
	pc1.p = NULL;
	printf("%d", pc1.num);


	system("pause");
}