#include<stdio.h>
#include<stdlib.h>

void show() {
	printf("������%d��\n", __LINE__);
	printf("�������ʱ��%s %s\n", __DATE__, __TIME__);
	printf("�ļ���%s\n", __FILE__);
	printf("������%s\n", __FUNCTION__);
}


void main() {

	//C���Ա��������ã��������

	printf("������%d��\n", __LINE__);
	printf("�������ʱ��%s %s\n", __DATE__, __TIME__);
	printf("�ļ���%s\n", __FILE__);
	printf("������%s\n", __FUNCTION__);

	show();
	showit();

	getchar();
}