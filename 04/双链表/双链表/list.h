#include<stdio.h>
#include<stdlib.h>

//˫����Ľڵ�
typedef struct LinkNode{
	int data;
	struct LinkNode *pPre;
	struct LinkNode *pNext;
}node;

typedef struct head {
	node *head;					//ָ��ͷ��
	node *tail;					//ָ��β��
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