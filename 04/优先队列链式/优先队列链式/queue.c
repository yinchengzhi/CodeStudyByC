#include"queue.h"


void init(PQueue *pphead) {							//初始化
	*pphead = NULL;
}

PQueue enq(PQueue phead, datatype data,int high) {	//入队
	PQueue pnew = malloc(sizeof(Queue));
	pnew->high = high;
	pnew->data = data;
	pnew->pNext = NULL;								//开辟新节点
	if (phead == NULL) {
		phead = pnew;
		return phead;
	}
	else {
		if (pnew->high > phead->high) {
			pnew->pNext = phead;
			phead = pnew;
			return phead;							//头部插入
		}
		else {
			PQueue ptemp = phead;
			while (ptemp->pNext != NULL) {
				ptemp = ptemp->pNext;				//循环到尾部
			}
			if (pnew->high<ptemp->high) {
				ptemp->pNext = pnew;
				return phead;						//尾部插入
			}
			else {
				PQueue p1, p2;						
				p1 = p2 = NULL;
				p1 = phead;
				while (p1->pNext!=NULL) {
					p2 = p1->pNext;					
					if ((pnew->high <= p1->high) && (pnew->high>p2->high)) {
						pnew->pNext = p1->pNext;
						p1->pNext = pnew;			//插入
						break;
					}
					p1 = p1->pNext;
				}
				return phead;
			}
		}
	}
}

PQueue deq(PQueue phead, PQueue pdata) {			//出队
	if (phead == NULL) {
		return NULL;
	}
	else {
		pdata->high = phead->high;
		pdata->data = phead->data;					//保存出队的值

		PQueue ptemp = phead;
		phead = phead->pNext;						//保存下一个节点

		free(ptemp);
		return phead;
	}
}

void show(PQueue phead) {							//显示队列
	if (phead == NULL) {
		return;
	}
	else {
		printf("\n%d,%d,%p,%p", phead->data, phead->high, phead, phead->pNext);
		show(phead->pNext);
	}
}