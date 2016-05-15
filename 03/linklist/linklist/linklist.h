#include<stdio.h>
#include<stdlib.h>

struct LinkNode{
	int data;
	struct LinkNode*pNext;
};

typedef struct LinkNode node;									//简化类型

void init(node *phead);											//初始化
node *addback(node *phead, int data);							//尾部添加节点
void *addhead(node **pphead, int data);							//头插法

void showall(node *phead);										//显示
void revshowall(node *phead);									//反转显示

node *searchfirst(node *phead,int finddata);					//查找
node *changefirst(node *phead, int finddata, int newdata);		//修改查找


node *deletefirst(node *phead, int finddata);					//删除
node *insertfirst(node *phead, int finddata, int newdata);		//插入

void bubblesort(node *phead);

void quicksort(node *pbegin, node *pback);
node *fen(node *pbegin, node *pback);

int getnum(node* phead);
int getnum_recursion(node* phead);

void myquicksort(node *phead, node*pback);

node *rev(node *phead);
node *rev_recursion(node*phead);