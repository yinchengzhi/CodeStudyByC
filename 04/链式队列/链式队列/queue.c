#include"queue.h"

void init(PQueue *pphead) {								//初始化					
	*pphead = NULL;

}

PQueue enq(PQueue phead, datatype data) {				//入队
	PQueue pnew = malloc(sizeof(Queue));				//开辟数据
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;									//直接插入
	}
	else {
		PQueue ptemp = phead;
		while (ptemp->pNext!=NULL){
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

PQueue deq(PQueue phead, datatype *pdata) {				//出队
	if (phead == NULL) {

	}
	else{
		*pdata = phead->data;							//获取弹出的数据
		PQueue ptemp = phead;
		phead = phead->pNext;							//存储下一个节点
	}
	return phead;
}

void show(PQueue phead) {								//显示队列
	if (phead == NULL) {
		return;
	}
	else {
		printf("%5d", phead->data);
		show(phead->pNext);								//递归调用
	}
}