#include"stack.h"

PNODE init(PNODE phead) {							
	phead = NULL;									//初始化头指针
	return phead;
	//初始化一个节点
	//phead->id = 0;
	//phead->data = 0;
	//phead->pNext = NULL;
}

PNODE push(PNODE phead, int id, datatype data) {	//吃东西
	PNODE pnew = malloc(sizeof(node));
	pnew->id = id;
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		PNODE ptemp = phead;
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;							//循环到尾部
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

PNODE pop(PNODE phead, PNODE pdata) {						//吐出
	if (phead == NULL) {
		return NULL;
	}
	else if (phead->pNext == NULL) {						//1个节点
		pdata->id = phead->id;
		pdata->data = phead->data;							//赋值
		free(phead);
		phead = NULL;
		return phead;										//删除一个节点
	}
	else {
		PNODE ptemp = phead;
		while (ptemp->pNext->pNext != NULL) {
			ptemp = ptemp->pNext;							//循环到倒数第二个节点
		}
		pdata->id = ptemp->pNext->id;
		pdata->data = ptemp->pNext->data;					//赋值
		free(ptemp->pNext);
		ptemp->pNext = NULL;
		return phead;
	}
}

PNODE clear(PNODE phead) {									//清空
	if (phead == NULL) {
		return NULL;
	}
	else {
		PNODE p1 = phead, p2 = NULL;
		while (p1->pNext != NULL) {
			p2 = p1->pNext;									//保存第二个节点的位置
			p1->pNext = p2->pNext;							//跳过p2;
			free(p2);
		}
		free(phead);										//删除第一个节点
		phead = NULL;
		return NULL;
	}
}
void showall(PNODE phead) {									//显示全部数据
	if (phead == NULL) {
		return;
	}
	else {
		printf("\n%d,%d,%p,%p",phead->id,phead->data, phead, phead->pNext);
		showall(phead);
	}
}