#include"mem.h"

void *mymalloc(size_t size) {
	void *p = malloc(size);
	//printf("\n�����ڴ��ַ%p,��С%d", p, size);
	struct MEM*pmem = malloc(sizeof(struct MEM));
	pmem->p = p;
	pmem->size = size;													//����һ���ڵ�
	phead = addback(phead, pmem);
	return p;
}

void myfree(void *p) {
	//printf("\n�ڴ��ַ%p�ͷ�", p);
	PNODE *px = findit(phead, p);
	if (px == NULL) {
		return;
	}
	else {
		deletenode(phead, p);											//ɾ���ڵ�
		free(p);
	}
}

void *myrealloc(void*p, size_t size) {
	void *pt = realloc(p, size);
	struct MEM mymem;
	mymem.p = pt;
	mymem.size = size;													//�µ��ڴ��ַ��С
	phead = change(phead, p, &mymem);
	//printf("\n�ڴ��ַ%p���·��䵽%p����С%d", p, pt, size);
	return pt;
}


PNODE addback(PNODE phead, struct MEM*pmem) {						   	//����һ������
	//struct MEM*
	PNODE pnew = malloc(sizeof(node));
	pnew->pmem = pmem;
	pnew->pNext = NULL;													//����һ���ڵ�

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

PNODE change(PNODE phead, void*pfind, struct MEM*pnewmem) {				//�޸�
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

PNODE deletenode(PNODE phead, void *paddr) {							//ɾ��
	PNODE p1, p2;
	p1 = p2 = NULL;
	p1 = phead;
	while (p1 != NULL) {
		if (p1->pmem->p == paddr) {
			break;
		}
		else {
			p2 = p1;
			p1 = p1->pNext;											    //������һ����ַ
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
	int i = 0;															//���ٸ���ַ
	int j = 0;															//������ٸ��ֽ��ڴ�
	for (PNODE p = phead; p != NULL; p = p->pNext) {
		i++;
		j += p->pmem->size;
		printf("\nmemaddr=%p,size=%d", p->pmem->p, p->pmem->size);
	}
	printf("\nĿǰһ��%d����ַ��ʹ�ã�һ������%d�ڴ�", i, j);
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
			p1->pNext = p2->pNext;										//�Ȱ��м���Щ�ڵ��ͷ�
			free(p2->pmem->p);											//�ͷ��ڴ�
			free(p2);
			//p1 = p1->pNext;
		}
		free(phead->pmem->p);												//�ͷ��ڴ�
		free(phead);													//����ͷ�ͷ�ڵ�
	}
}