#include<stdio.h>
#include<stdlib.h>

struct LinkNode{
	int data;
	struct LinkNode*pNext;
};

typedef struct LinkNode node;									//������

void init(node *phead);											//��ʼ��
node *addback(node *phead, int data);							//β����ӽڵ�
void *addhead(node **pphead, int data);							//ͷ�巨

void showall(node *phead);										//��ʾ
void revshowall(node *phead);									//��ת��ʾ

node *searchfirst(node *phead,int finddata);					//����
node *changefirst(node *phead, int finddata, int newdata);		//�޸Ĳ���


node *deletefirst(node *phead, int finddata);					//ɾ��
node *insertfirst(node *phead, int finddata, int newdata);		//����

void bubblesort(node *phead);

void quicksort(node *pbegin, node *pback);
node *fen(node *pbegin, node *pback);

int getnum(node* phead);
int getnum_recursion(node* phead);

void myquicksort(node *phead, node*pback);

node *rev(node *phead);
node *rev_recursion(node*phead);