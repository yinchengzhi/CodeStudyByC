
#include<stdio.h>
#include<stdlib.h>

#define datatype int 

typedef struct LinkNode {
	int id;										//�ڵ�ı��
	datatype data;								//�洢����
	struct LinkNode *pNext;						//ָ��
}node, *PNODE;

PNODE init(PNODE phead);						//��ʼ��
PNODE push(PNODE phead, int id, datatype data);	//�Զ���
PNODE pop(PNODE phead, PNODE pdata);				//�³�
PNODE clear(PNODE phead);						//���
void showall(PNODE phead);