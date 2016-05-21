#include"环形链表.h"

PNODE addback(PNODE phead, int data) {				//尾部插入
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;								//分配空间
	if (phead == NULL) {
		phead = pnew;
		pnew->pNext = phead;
	}
	else {
		//循环到尾部
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;													//头尾相连
	}
	return phead;
}

PNODE addfront(PNODE phead, int data) {											//头部插入
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;															//分配空间
	if (phead == NULL) {
		phead = pnew;
		pnew->pNext = phead;
	}
	else {
		//循环到尾部
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;															//与尾插法的区别就在于此
	}
	return phead;
}

void showall(PNODE phead) {														//仅针对环形链表打印
	if (phead == NULL) {
		return;
	}
	else if (phead->pNext==phead) {
		printf("母猴子%d号,%p,%p\n", phead->data, phead, phead->pNext);					//打印一个节点
	}
	else {
		PNODE p = phead;
		while (p->pNext != phead) {
			printf("母猴子%d号,%p,%p\n", p->data, p, p->pNext);							//打印一个节点
			p = p->pNext;														//循环
		}
		printf("母猴子%d号,%p,%p\n", p->data, p, p->pNext);								//补充相等的情况
	}
}


PNODE findfirst(PNODE phead, int data) {										//提前预处理
	if (phead == NULL) {
		return NULL;
	}
	else if (phead->pNext == phead) {
		if (phead->data == data)
			return phead;
	}
	else {
		PNODE p = phead;
		while (p->pNext != phead) {
			if (p->data == data) {
				return p;
			}
			p = p->pNext;														//循环
		}
		if (p->data == data) {
			return p;
		}
	}
}

PNODE deletefirst(PNODE phead, int data) {
	PNODE p1 = NULL;
	PNODE p2 = NULL;
	p1 = phead;
	while (p1->pNext != phead) {
		if (p1->data==data) {
			break;
		}
		else {
			p2 = p1;
			p1 = p1->pNext;													  //循环的作用
		}
	}

	if (p1!=phead) {
		p2->pNext = p1->pNext;
		free(p1);
	}
	else {
		node *p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}

		phead = phead->pNext;												  //改变头节点
		free(p1);															  //释放p1
		p->pNext = phead;
	}
	return phead;
}


int getnum(PNODE phead) {
	if (phead == NULL) {
		return 0;
	}
	else if (phead->pNext == phead) {
		return 1;
	}
	else {
		int i = 1;
		PNODE p = phead;
		while (p->pNext != phead) {
			i++;
			p = p->pNext;														//循环
		}
		return i;																//统计计数
	}
}



PNODE insertfirst(PNODE phead, int finddata, int data) {						//插入数据
	PNODE p1 = NULL;
	PNODE p2 = NULL;
	p1 = phead;
	while (p1->pNext != phead) {
		if (p1->data != finddata) {
			p2 = p1;
			p1 = p1->pNext;
		}
		else{
			break;
		}
	}
	printf("p1 = %d\n", p1->data);

	node *pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;
	if (p1 != phead) {
		//pnew->pNext = p1->pNext;									后插入
		//p1->pNext = pnew;
		//前插需要p2
		pnew->pNext = p2->pNext;
		p2->pNext = pnew;
	}
	else{
		//前面插入
		/*
		node*p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;

		*/

		//循环到尾部
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;													//头尾相连

	}
	return phead;
}

PNODE deletefirstp(PNODE phead, int data, PNODE *ppnext) {			//删除数据，二级指针
	PNODE p1 = NULL;
	PNODE p2 = NULL;
	p1 = phead;
	while (p1->pNext != phead) {
		if (p1->data == data) {
			break;
		}
		else {
			p2 = p1;
			p1 = p1->pNext;													  //循环的作用
		}
	}

	if (p1 != phead) {
		p2->pNext = p1->pNext;
		*ppnext = p1->pNext;												  //跳下一个节点
		free(p1);
	}
	else {
		node *p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}

		phead = phead->pNext;												  //改变头节点
		*ppnext = p1->pNext;
		free(p1);															  //释放p1
		p->pNext = phead;
	}
	return phead;
}