#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct info7k7k{
	char user[50];
	char password[50];
}INFO,*PINFO;																//INFO �ṹ�壬PINFOָ��

void main2x() {
	FILE *pfr = fopen("G:\fakeData.txt","r");
	FILE *pfw = fopen("G:\fakeDataWithId.txt", "w");
	int i = 0;

	while (!feof(pfr)) {
		i++;
		INFO info1;
		fscanf(pfr, "%s%s", info1.user, info1.password);					//��ȡ
		fprintf(pfw, "%d %s %s\n", i, info1.user, info1.password);			//���

	}


	fclose(pfr);
	fclose(pfw);
	system("pause");
}


void main3x() {

	//int num = fprintf(stdout, "HelloWorld%s", "1234");
	//printf("\n%d", num);													//fprintf����ֵ����д��ɹ��ַ��ĸ���

	FILE *pf = fopen("C:\\x.txt", "r");
	int num = fprintf(pf, "HelloWorld%s", "1234");							//д��ʧ�ܷ���-1
	printf("\n%d", num);

	system("pause");
}


void main() {

	//char str[128] = { 0 };
	//int numa;
	//int numb;
	//int num = fscanf(stdin, "%s%d%d", str, &numa, &numb);
	////����ֵ��ɨ�赽��������,ʧ�ܷ���-1
	//printf("\n%d", num);

	FILE *pf = fopen("C:\\x.txt", "w");
	char str[128] = { 0 };
	int numa;
	int numb;
	int num = fscanf(pf, "%s%d%d", str, &numa, &numb);
	printf("\n%d", num);

	system("pause");
}