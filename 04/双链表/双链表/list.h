#include<stdio.h>
#include<stdlib.h>

//双链表的节点
typedef struct LinkNode{
	int data;
	struct LinkNode *pPre;
	struct LinkNode *pNext;
}node;

typedef struct head {
	node *head;					//指向头部
	node *tail;					//指向尾部
}List;


void init(List *p);

void adddatahead(List *p, int data);
void adddataback(List *p, int data);
void show(List *p);
void revshow(List *p);
node* find(List *p,int data);
node* revfind(List *p,int data);

void insertdata(List *p, int data,int newdata);
void deletedata(List *p, int data);