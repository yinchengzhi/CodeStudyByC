#include<stdio.h>
#include<stdlib.h>

typedef struct MyStruct{
	int num;
	double db;
}myx,mys;

typedef union MyUnion {
	int num;
	double db;
}myy;


typedef struct MyStruct my;			//�������͵ı���
typedef union MyUnion myu;

typedef unsigned long int num1, num2, num3;			//��������



void main1() {
	my my1 = { .num = 10,10.9 };
	myx my2 = { 11,11.99 };				//ͬʱ��ʼ��
	myu myu1 = { 10 };					//������ֻ�ܶ�һ��������ʼ��
	myy myu2 = { .db = 11.9 };			//ָ����Ա��ֵ
	mys my3 = { 12,12.9 };

	system("pause");
}