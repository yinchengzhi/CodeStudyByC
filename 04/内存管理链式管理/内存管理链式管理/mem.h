#include<stdio.h>
#include<stdlib.h>

void *mymalloc(size_t size);
void myfree(void *p);
void *myrealloc(void*p, size_t size);

//��¼������ڴ��ַ��С,��ַ
struct MEM{
	void *p;
	int size;
};

typedef struct LinkNode{
	struct MEM *pmem;										//����ָ��
	struct LinkNode *pNext;									//ָ����һ���ڵ�
}node,*PNODE;


struct LinkNode *phead;

PNODE addback(PNODE phead, struct MEM*pmem);						//����һ������
PNODE change(PNODE phead,void*pfind, struct MEM*pnewmem);			//�޸�
PNODE findit(PNODE phead, void*pfind);
PNODE deletenode(PNODE phead,void *paddr);							//ɾ��
void showall(PNODE phead);

void getinfo(PNODE phead);

PNODE deleteall(PNODE phead);