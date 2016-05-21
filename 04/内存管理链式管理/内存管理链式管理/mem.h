#include<stdio.h>
#include<stdlib.h>

void *mymalloc(size_t size);
void myfree(void *p);
void *myrealloc(void*p, size_t size);

//记录分配的内存地址大小,地址
struct MEM{
	void *p;
	int size;
};

typedef struct LinkNode{
	struct MEM *pmem;										//保存指针
	struct LinkNode *pNext;									//指向下一个节点
}node,*PNODE;


struct LinkNode *phead;

PNODE addback(PNODE phead, struct MEM*pmem);						//插入一个数据
PNODE change(PNODE phead,void*pfind, struct MEM*pnewmem);			//修改
PNODE findit(PNODE phead, void*pfind);
PNODE deletenode(PNODE phead,void *paddr);							//删除
void showall(PNODE phead);

void getinfo(PNODE phead);

PNODE deleteall(PNODE phead);