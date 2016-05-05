
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct A{
	long long QQ;
	char*pstr;
	int strlengh;
};

struct B{
	struct A *parr;
	int length;
};

int main() {
	struct B*p = (B*)malloc(sizeof(struct B));
	p->length = 10;
	p->parr = (A*)malloc(sizeof(struct A)*p->length);
	p->parr[0].QQ = 7702550;
	p->parr[0].pstr =(char*)malloc(sizeof(10));
	strcpy(p->parr[0].pstr, "yinchengzhi");
	p->parr[0].strlengh = 10;
}