#include<stdio.h>
#include<stdlib.h>

typedef struct Linknode {
	int data;
	struct Linknode*pNext;
}node,*PNODE;													//node�ṹ�������PNODE����һ���ṹ��ָ��

PNODE addback(PNODE phead, int data);							//β������
PNODE addfront(PNODE phead, int data);							//ͷ������

PNODE findfirst(PNODE phead, int data);							//��������
PNODE deletefirst(PNODE phead, int data);						//ɾ������
PNODE deletefirstp(PNODE phead, int data,PNODE *ppnext);	    //ɾ������,����ָ��

PNODE insertfirst(PNODE phead, int finddata,int data);			//��������

int getnum(PNODE phead);

void showall(PNODE phead);

