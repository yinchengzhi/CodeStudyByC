
#include"Queue.h"

Queue *init(Queue *queueA) {							//��ʼ��
	return NULL;
}

Queue *EnQueue(Queue *queueA, int num, int high) {		//���
	Queue *pnewnode = (Queue*)malloc(sizeof(Queue));	//�����ڴ�
	pnewnode->num = num;
	pnewnode->high = high;
	pnewnode->pNext = NULL;


	if (queueA == NULL) {								//����Ϊ��
		queueA = pnewnode;
		//sort(queueA);
		return queueA;									//����ֵ
	}
	else {
		Queue *p = queueA;								//ͷ�ڵ�
		while (p->pNext != NULL) {
			p = p->pNext;
		}
		//ȷ��Ҫ�����λ��
		p->pNext = pnewnode;							//����
		//sort(queueA);
		return queueA;									//����
	}
}

Queue *DeQueue(Queue *queueA, Queue *pout) {			//����
	if (queueA == NULL) {
		return NULL;
	}
	else {
		pout->num = queueA->num;
		pout->high = queueA->high;						//��ֵ
		Queue *ptemp = queueA;							//��¼Ҫɾ���ĵ�ַ
		queueA = queueA->pNext;							//����queueAָ���
		free(ptemp);									//�ͷŽڵ�

		return queueA;
	}
}

Queue *freeall(Queue *queueA) {							//���

}

Queue *insertEnQueue(Queue *queueA, int num, int high) {//���в���
	Queue *pnewnode = (Queue *)malloc(sizeof(Queue));
	pnewnode->high = high;
	pnewnode->num = num;
	if (queueA == NULL) {								//�ڵ�Ϊ��
		pnewnode->pNext = NULL;
		queueA = pnewnode;
		return queueA;
	}
	else {
		if (pnewnode->high > queueA->high) {
			pnewnode->pNext = queueA;					//ͷ������
			queueA = pnewnode;							//ָ������ڵ�
			return queueA;
		}
		else {
			Queue *p = queueA;							//ͷ�ڵ�
			while (p->pNext != NULL) {
				p = p->pNext;
			}

			//pѭ����β��							    //β������
			if (pnewnode->high <= p->high) {
				p->pNext = pnewnode;
				pnewnode->pNext = NULL;
				return queueA;
			}
			else {										//�м����
				Queue *p1, *p2;
				p1 = p2 = NULL;							//����Ұָ��
				p1 = queueA;							//ͷ�ڵ�
				while (p1->pNext != NULL) {
					p2 = p1->pNext;
					if (p1->high >= pnewnode->high&&p2->high < pnewnode->high) {
						pnewnode->pNext = p2;
						p1->pNext = pnewnode;			//����
						break;
					}
					p1 = p1->pNext;
				}
				return queueA;
			}

		}
	}

}

void insertDeque(Queue *queueA) {						//��������

}


void sort(Queue *queueA) {								//���ȼ��Ŷ�

	if (queueA == NULL || queueA->pNext == NULL) {
		return;
	}


	//ð������
	//for (Queue *p1 = queueA; p1 != NULL; p1 = p1->pNext) {
	//	for (Queue *p2 = queueA; p2 != NULL; p2 = p2->pNext) {
	//		if (p1->high > p2->high) {
	//			Queue temp;
	//			temp.num = p1->num;
	//			p1->num = p2->num;
	//			p2->num = temp.num;

	//			temp.high = p1->high;
	//			p1->high = p2->high;
	//			p2->high = temp.high;					//�����ڵ�����
	//		}
	//	}
	//}


}

void printall(Queue *queueA) {							//�ݹ�
	if (queueA == NULL) {
		return;
	}
	else {
		printf("%d,%d,%p,%p\n", queueA->num, queueA->high, queueA, queueA->pNext);
		printall(queueA->pNext);							//������һ���ڵ�
	}
}