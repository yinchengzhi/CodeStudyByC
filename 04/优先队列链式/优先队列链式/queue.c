#include"queue.h"


void init(PQueue *pphead) {							//��ʼ��
	*pphead = NULL;
}

PQueue enq(PQueue phead, datatype data,int high) {	//���
	PQueue pnew = malloc(sizeof(Queue));
	pnew->high = high;
	pnew->data = data;
	pnew->pNext = NULL;								//�����½ڵ�
	if (phead == NULL) {
		phead = pnew;
		return phead;
	}
	else {
		if (pnew->high > phead->high) {
			pnew->pNext = phead;
			phead = pnew;
			return phead;							//ͷ������
		}
		else {
			PQueue ptemp = phead;
			while (ptemp->pNext != NULL) {
				ptemp = ptemp->pNext;				//ѭ����β��
			}
			if (pnew->high<ptemp->high) {
				ptemp->pNext = pnew;
				return phead;						//β������
			}
			else {
				PQueue p1, p2;						
				p1 = p2 = NULL;
				p1 = phead;
				while (p1->pNext!=NULL) {
					p2 = p1->pNext;					
					if ((pnew->high <= p1->high) && (pnew->high>p2->high)) {
						pnew->pNext = p1->pNext;
						p1->pNext = pnew;			//����
						break;
					}
					p1 = p1->pNext;
				}
				return phead;
			}
		}
	}
}

PQueue deq(PQueue phead, PQueue pdata) {			//����
	if (phead == NULL) {
		return NULL;
	}
	else {
		pdata->high = phead->high;
		pdata->data = phead->data;					//������ӵ�ֵ

		PQueue ptemp = phead;
		phead = phead->pNext;						//������һ���ڵ�

		free(ptemp);
		return phead;
	}
}

void show(PQueue phead) {							//��ʾ����
	if (phead == NULL) {
		return;
	}
	else {
		printf("\n%d,%d,%p,%p", phead->data, phead->high, phead, phead->pNext);
		show(phead->pNext);
	}
}