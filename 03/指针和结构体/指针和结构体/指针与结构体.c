#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ģ�黯��ÿ��ģ����Կɿ���
//ÿһ���������һ������

struct data {
	long long QQ;
	char *pstr;
	int strlength;
};

struct Array{
	struct data *parr;
	int length;
};

void main() {

	struct Array *p = malloc(sizeof(struct Array));
	p->length = 10;
	(*p).length = 10;										//ָ��->�ṹ�������.
	//p->parr = malloc(sizeof(struct data)*p->length);
	(*p).parr[0].QQ = malloc(sizeof(struct data)*p->length);

	p->parr[0].QQ = 77025077;
	(p->parr+0)->QQ = 88025088;								//p->parr

	p->parr[0].pstr = malloc(10);
	strcpy(p->parr[0].pstr, "yincheng");
	p->parr[0].strlength = 10;
	system("pause");
}