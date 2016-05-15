
#include"linklist.h"


void init(node *phead) {				    
	phead->pNext = NULL;
	phead->data = 0;						
}

//尾插，改变一个指针，需要指针的地址，用返回值给指针赋值
node *addback(node *phead, int data) {			
	node *pnew = malloc(sizeof(node));						//新的节点
	pnew->data = data;
	pnew->pNext = NULL;

	if (phead == NULL) {
		phead = pnew;										//直接连接
	}
	else {
		node *ptemp = phead;								//备份头节点
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;							//循环
		}
		ptemp->pNext = pnew;								//连接
	}

	return phead;
}

void showall(node *phead) {					
	if (phead == NULL) {
		return;
	}
	else {
		printf("%d,%p,%p\n", phead->data, phead, phead->pNext);
		showall(phead->pNext);								//跳到下一个节点
	}
}

void revshowall(node *phead) {
	if (phead == NULL) {
		return;
	}
	else {
		showall(phead->pNext);								//跳到下一个节点
		printf("%d,%p,%p\n", phead->data, phead, phead->pNext);
	}
}

void *addhead(node **pphead, int data) {
	node *pnew = malloc(sizeof(node));						//新的节点
	pnew->data = data;
	pnew->pNext = NULL;										//赋值

	if (*pphead==NULL) {
		*pphead = pnew;										//直接连接
	}
	else {
		pnew->pNext = *pphead;								//头插
		*pphead = pnew;
	}

}


node *searchfirst(node *phead, int finddata) {
	for (node *p = phead; p != NULL; p = p->pNext) {
		if (p->data == finddata) {
			return p;										//返回找到的地址
		}
	}
	return NULL;
}


node *changefirst(node *phead, int finddata,int newdata) {
	for (node *p = phead; p != NULL; p = p->pNext) {
		if (p->data == finddata) {
			p->data = newdata;
			return p;										//返回找到的地址
		}
	}
	return NULL;
}

node *deletefirst(node *phead, int finddata) {
	node *p1 = NULL, *p2 = NULL;											//两个指针
	p1 = phead;												//保存头节点
	while (p1 != NULL) {
		if (p1->data != finddata) {
			p2 = p1;										//p2是保存p1上一个位置
			p1 = p1->pNext;									//向前移动
		}
		else {
			break;
		}
	}

	if (p1 != phead) {
		p2->pNext = p1->pNext;								//跳过p1
		free(p1);											//删除p1
	}
	else {
		phead = phead->pNext;
		free(p1);											//头部删除
	}

	return phead;
}


node *insertfirst(node *phead, int finddata, int newdata) {
	node *p1 = NULL, *p2 = NULL;											//两个指针
	p1 = phead;												//保存头节点
	while (p1 != NULL) {
		if (p1->data != finddata) {
			p2 = p1;										//p2是保存p1上一个位置
			p1 = p1->pNext;									//向前移动
		}
		else {
			break;
		}
	}

	node *pnew = malloc(sizeof(node));						//新的节点
	pnew->data = newdata;
	pnew->pNext = NULL;										//赋值

	if (phead == p1) {
		pnew->pNext = phead;								//保存头节点
		phead = pnew;										//头部插入
	}
	else {
		pnew->pNext = p1;
		p2->pNext = pnew;
	}
	return phead;
}


void bubblesort(node *phead) {

	//数组可以随机访问任何一个元素
	//链表找到N个元素，先遍历N-1

	for (node *p1 = phead; p1 != NULL; p1 = p1->pNext) {

		for (node*p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p1->data < p2->data) {
				int temp;
				temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
			else {

			}
		}
	}
}


void quicksort(node *pbegin, node *pback) {
	if (pbegin != pback) {
		node *pfen = fen(pbegin, pback);							//取中间点
		quicksort(pbegin,pfen);										//分段前面
		quicksort(pfen->pNext, pback);								//分段后面
	}
}


node *fen(node *pbegin, node *pback) {
	int key = pbegin->data;											//以第一个数据为分段
	node *p = pbegin;												//第一个节点
	node *q = pbegin->pNext;										//第二个节点
	
	while (q!=pback) {
		if (q->data < key) {
			p = p->pNext;											//循环下一个节点
			int temp = p->data;
			p->data = q->data;
			q->data = temp;											//交换
		}
		q = q->pNext;												//循环第二个指针

		printf("\n\n");
		showall(pbegin);
	}

	int temp = p->data;
	p->data = pbegin->data;
	pbegin->data = temp;											

	showall(pbegin);

	return p;
}


void myquicksort(node *phead, node*pback) {
	if (phead == pback) {
		return;
	}
	else {
		int key = phead->data;										//获取第一个值，分界线
		node *p1 = phead;
		for (node *p2 = phead->pNext; p2 != pback; p2 = p2->pNext) {
			if (p2->data < key) {
				p1 = p1->pNext;										//循环到下一个
				int temp = p1->data;								//交换
				p1->data = p2->data;
				p2->data = temp;
			}
		}

		int temp = p1->data;										//交换
		p1->data = phead->data;
		phead->data = temp;

		myquicksort(phead, p1);
		myquicksort(p1->pNext, pback);
	}
	
}


int getnum(node* phead) {
	int i = 0;
	for (; phead != NULL;phead = phead->pNext) {
		i++;
	}
	return i;
}


int getnum_recursion(node* phead) {
	if (phead == NULL) {
		return 0;
	}
	else {
		return 1 + getnum_recursion(phead->pNext);					//传递参数
	}
}


node *rev(node *phead) {								//链表的反转
	if (phead == NULL || phead->pNext == NULL) {
		return NULL;
	}
	else {
		node*pre, *pcur, *pnext;						//三个节点
		pre = pcur = pnext = NULL;						//赋值表达式

		pre = phead;
		pcur = phead->pNext;
		while (pcur) {									//pcur!=NULL
			pnext = pcur->pNext;						//保存下一个节点
			pcur->pNext = pre;							//前一个节点
			pre = pcur;
			pcur = pnext;								//轮替
		}
		phead->pNext = NULL;
		phead = pre;									//保存节点
	}
	return phead;
}

node *rev_recursion(node*phead) {
	if (phead == NULL || phead->pNext == NULL) {
		return phead;
	}
	else {
		node* pnext = phead->pNext;						//顺序
		node* head = rev_recursion(pnext);				//递归调用，跳到下一个节点，轮寻所有的节点
		pnext->pNext = phead;							//保存
		phead->pNext = NULL;							//逆序
		return head;
	}
}