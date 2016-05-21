
#include<stdio.h>
#include<stdlib.h>

#define datatype int 

typedef struct LinkNode {
	int id;										//节点的编号
	datatype data;								//存储数据
	struct LinkNode *pNext;						//指针
}node, *PNODE;

PNODE init(PNODE phead);						//初始化
PNODE push(PNODE phead, int id, datatype data);	//吃东西
PNODE pop(PNODE phead, PNODE pdata);				//吐出
PNODE clear(PNODE phead);						//清空
void showall(PNODE phead);