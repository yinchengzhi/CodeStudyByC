#include"mem.h"

void *mymalloc(size_t size) {
	void *p = malloc(size);
	//printf("\n分配内存地址%p,大小%d", p, size);
	struct MEM*pmem = malloc(sizeof(struct MEM));
	pmem->p = p;
	pmem->size = size;													//开辟一个节点
	phead = addback(phead, pmem);
	return p;
}

void myfree(void *p) {
	//printf("\n内存地址%p释放", p);
	PNODE *px = findit(phead, p);
	if (px == NULL) {
		return;
	}
	else {
		deletenode(phead, p);											//删除节点
		free(p);
	}
}

void *myrealloc(void*p, size_t size) {
	void *pt = realloc(p, size);
	struct MEM mymem;
	mymem.p = pt;
	mymem.size = size;													//新的内存地址大小
	phead = change(phead, p, &mymem);
	//printf("\n内存地址%p重新分配到%p，大小%d", p, pt, size);
	return pt;
}


PNODE addback(PNODE phead, struct MEM*pmem) {						   	//插入一个数据
	//struct MEM*
	PNODE pnew = malloc(sizeof(node));
	pnew->pmem = pmem;
	pnew->pNext = NULL;													//开辟一个节点

	if (phead == NULL) {
		phead = pnew;
	}
	else {
		PNODE ptemp = phead;
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

PNODE change(PNODE phead, void*pfind, struct MEM*pnewmem) {				//修改
	for (PNODE p = phead; p != NULL; p = p->pNext) {
		if (p->pmem->p == pfind) {
			p->pmem->p = pnewmem->p;
			p->pmem->size = pnewmem->size;
			return phead;
		}
	}
}

PNODE findit(PNODE phead, void*pfind) {
	for (PNODE p = phead; p != NULL; p = p->pNext) {
		if (p->pmem->p == pfind) {
			return p;
		}
	}
	return NULL;
}

PNODE deletenode(PNODE phead, void *paddr) {							//删除
	PNODE p1, p2;
	p1 = p2 = NULL;
	p1 = phead;
	while (p1 != NULL) {
		if (p1->pmem->p == paddr) {
			break;
		}
		else {
			p2 = p1;
			p1 = p1->pNext;											    //备份上一个地址
		}
	}
	if (p1 != phead) {
		p2->pNext = p1->pNext;
		free(p1);
	}
	else {
		phead = phead->pNext;
		free(p1);
	}
	return phead;
}

void showall(PNODE phead) {
	if (phead == NULL) {
		return;
	}
	else {
		printf("\nmemaddr=%p,size=%d", phead->pmem->p, phead->pmem->size);
		showall(phead->pNext);
	}
}


void getinfo(PNODE phead) {
	printf("\n\n\n");
	int i = 0;															//多少个地址
	int j = 0;															//代表多少个字节内存
	for (PNODE p = phead; p != NULL; p = p->pNext) {
		i++;
		j += p->pmem->size;
		printf("\nmemaddr=%p,size=%d", p->pmem->p, p->pmem->size);
	}
	printf("\n目前一共%d个地址在使用，一共消耗%d内存", i, j);
}

PNODE deleteall(PNODE phead) {
	if (phead == NULL) {
		return;
	}
	else {
		PNODE p1 = NULL;
		PNODE p2 = NULL;
		p1 = phead;
		while (p1->pNext != NULL) {
			p2 = p1->pNext;
			p1->pNext = p2->pNext;										//先把中间这些节点释放
			free(p2->pmem->p);											//释放内存
			free(p2);
			//p1 = p1->pNext;
		}
		free(phead->pmem->p);												//释放内存
		free(phead);													//最后释放头节点
	}
}