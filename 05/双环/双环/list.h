#include<stdio.h>
#include<stdlib.h>

//ÿһ���ڵ�
typedef struct node {
	int data;
	struct node *pPre;
	struct node *pNext;
}NODE,*PNODE;

//˫�����ͷβ
typedef struct List {
	struct node *head;
	struct node *tail;
}Dlist;

void init(Dlist *p);

void adddataback(Dlist *p, int data);

void showall(Dlist *p);

void adddatahead(Dlist *p, int data);

PNODE find(Dlist *p, int data);

void change(Dlist *p, int data,int newdata);

void insert(Dlist *p, int data, int newdata);

void deletedata(Dlist *p, int data);
