#include<stdio.h>
#include<stdlib.h>

typedef struct Linknode {
	int data;
	struct Linknode*pNext;
}node,*PNODE;													//node结构体变量，PNODE代表一个结构体指针

PNODE addback(PNODE phead, int data);							//尾部插入
PNODE addfront(PNODE phead, int data);							//头部插入

PNODE findfirst(PNODE phead, int data);							//查找数据
PNODE deletefirst(PNODE phead, int data);						//删除数据
PNODE deletefirstp(PNODE phead, int data,PNODE *ppnext);	    //删除数据,二级指针

PNODE insertfirst(PNODE phead, int finddata,int data);			//插入数据

int getnum(PNODE phead);

void showall(PNODE phead);

