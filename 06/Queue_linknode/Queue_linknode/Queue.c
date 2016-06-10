
#include"Queue.h"

Queue *init(Queue *queueA) {							//初始化
	return NULL;
}

Queue *EnQueue(Queue *queueA, int num, int high) {		//入队
	Queue *pnewnode = (Queue*)malloc(sizeof(Queue));	//分配内存
	pnewnode->num = num;
	pnewnode->high = high;
	pnewnode->pNext = NULL;


	if (queueA == NULL) {								//链表为空
		queueA = pnewnode;
		//sort(queueA);
		return queueA;									//返回值
	}
	else {
		Queue *p = queueA;								//头节点
		while (p->pNext != NULL) {
			p = p->pNext;
		}
		//确定要插入的位置
		p->pNext = pnewnode;							//插入
		//sort(queueA);
		return queueA;									//返回
	}
}

Queue *DeQueue(Queue *queueA, Queue *pout) {			//出队
	if (queueA == NULL) {
		return NULL;
	}
	else {
		pout->num = queueA->num;
		pout->high = queueA->high;						//赋值
		Queue *ptemp = queueA;							//记录要删除的地址
		queueA = queueA->pNext;							//跳过queueA指向的
		free(ptemp);									//释放节点

		return queueA;
	}
}

Queue *freeall(Queue *queueA) {							//清空

}

Queue *insertEnQueue(Queue *queueA, int num, int high) {//队列插入
	Queue *pnewnode = (Queue *)malloc(sizeof(Queue));
	pnewnode->high = high;
	pnewnode->num = num;
	if (queueA == NULL) {								//节点为空
		pnewnode->pNext = NULL;
		queueA = pnewnode;
		return queueA;
	}
	else {
		if (pnewnode->high > queueA->high) {
			pnewnode->pNext = queueA;					//头部插入
			queueA = pnewnode;							//指向这个节点
			return queueA;
		}
		else {
			Queue *p = queueA;							//头节点
			while (p->pNext != NULL) {
				p = p->pNext;
			}

			//p循环到尾部							    //尾部插入
			if (pnewnode->high <= p->high) {
				p->pNext = pnewnode;
				pnewnode->pNext = NULL;
				return queueA;
			}
			else {										//中间插入
				Queue *p1, *p2;
				p1 = p2 = NULL;							//避免野指针
				p1 = queueA;							//头节点
				while (p1->pNext != NULL) {
					p2 = p1->pNext;
					if (p1->high >= pnewnode->high&&p2->high < pnewnode->high) {
						pnewnode->pNext = p2;
						p1->pNext = pnewnode;			//插入
						break;
					}
					p1 = p1->pNext;
				}
				return queueA;
			}

		}
	}

}

void insertDeque(Queue *queueA) {						//插入排序

}


void sort(Queue *queueA) {								//优先级排队

	if (queueA == NULL || queueA->pNext == NULL) {
		return;
	}


	//冒泡排序
	//for (Queue *p1 = queueA; p1 != NULL; p1 = p1->pNext) {
	//	for (Queue *p2 = queueA; p2 != NULL; p2 = p2->pNext) {
	//		if (p1->high > p2->high) {
	//			Queue temp;
	//			temp.num = p1->num;
	//			p1->num = p2->num;
	//			p2->num = temp.num;

	//			temp.high = p1->high;
	//			p1->high = p2->high;
	//			p2->high = temp.high;					//交换节点数据
	//		}
	//	}
	//}


}

void printall(Queue *queueA) {							//递归
	if (queueA == NULL) {
		return;
	}
	else {
		printf("%d,%d,%p,%p\n", queueA->num, queueA->high, queueA, queueA->pNext);
		printall(queueA->pNext);							//进入下一个节点
	}
}