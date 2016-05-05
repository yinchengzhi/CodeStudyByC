#include"array.h"


void initwithnull(struct dataarray *pdataarray, char datatape[10], int elemsize) {

	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;				//大小
	strcpy(pdataarray->datatape, datatape);			//确定类型
}

//"char"  char

void initwitharray(struct dataarray *pdataarray, char datatape[10], int elemsize, void *parray, int n) {
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;				//大小
	strcpy(pdataarray->datatape, datatape);			//确定类型

	if (strcmp(pdataarray->datatape, "stringa")==0) {

		stringa *pa = parray;						//指针类型转换
		pdataarray->elemsize = sizeof(stringa);		//元素大小

		pdataarray->p = malloc(sizeof(stringa)*n);	//分配内存
		memcpy(pdataarray->p, parray, sizeof(stringa)*n);
		pdataarray->length = n;						//记录长度


	}

}

void showarray(struct dataarray *pdataarray, char datatape[10]) {
	
	stringa* pa = pdataarray->p;
	if(strcmp(pdataarray->datatape,"stringa") == 0){
		for (int i = 0; i < pdataarray->length; i++) {

			printf("%s ", pa[i].p);					//打印字符串
		}

		printf("\n");

	}
}


void backaddone(struct dataarray *pdataarray,void *parray) {		//传递一个元素的地址

	if (strcmp(pdataarray->datatape, "stringa") == 0) {

		pdataarray->p = realloc(pdataarray->p, sizeof(stringa)*(pdataarray->length + 1));		//拓展数组的长度
		stringa *pa = pdataarray->p;								//接受首地址
		stringa *palast = parray;									//转换类型

		pa[pdataarray->length].p = palast->p;
		pa[pdataarray->length].memlength = palast->memlength;
		pdataarray->length += 1;
	}

}