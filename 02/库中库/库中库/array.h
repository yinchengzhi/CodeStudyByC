#include"string.h"

struct dataarray{
	void *p;
	int length;
	char datatape[10];			//	"int"	"double"
	int elemsize;				//  4
};


void initwithnull(struct dataarray *pdataarray,char datatape[10],int elemsize);

void initwitharray(struct dataarray *pdataarray, char datatape[10], int elemsize,void *parray,int n);

void backaddone(struct dataarray *pdataarray,void *parray);			//传递一个元素的地址

void showarray(struct dataarray *pdataarray, char datatape[10]);
