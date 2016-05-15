
#include"linklist.h"


void init(node *phead) {				    
	phead->pNext = NULL;
	phead->data = 0;						
}

//β�壬�ı�һ��ָ�룬��Ҫָ��ĵ�ַ���÷���ֵ��ָ�븳ֵ
node *addback(node *phead, int data) {			
	node *pnew = malloc(sizeof(node));						//�µĽڵ�
	pnew->data = data;
	pnew->pNext = NULL;

	if (phead == NULL) {
		phead = pnew;										//ֱ������
	}
	else {
		node *ptemp = phead;								//����ͷ�ڵ�
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;							//ѭ��
		}
		ptemp->pNext = pnew;								//����
	}

	return phead;
}

void showall(node *phead) {					
	if (phead == NULL) {
		return;
	}
	else {
		printf("%d,%p,%p\n", phead->data, phead, phead->pNext);
		showall(phead->pNext);								//������һ���ڵ�
	}
}

void revshowall(node *phead) {
	if (phead == NULL) {
		return;
	}
	else {
		showall(phead->pNext);								//������һ���ڵ�
		printf("%d,%p,%p\n", phead->data, phead, phead->pNext);
	}
}

void *addhead(node **pphead, int data) {
	node *pnew = malloc(sizeof(node));						//�µĽڵ�
	pnew->data = data;
	pnew->pNext = NULL;										//��ֵ

	if (*pphead==NULL) {
		*pphead = pnew;										//ֱ������
	}
	else {
		pnew->pNext = *pphead;								//ͷ��
		*pphead = pnew;
	}

}


node *searchfirst(node *phead, int finddata) {
	for (node *p = phead; p != NULL; p = p->pNext) {
		if (p->data == finddata) {
			return p;										//�����ҵ��ĵ�ַ
		}
	}
	return NULL;
}


node *changefirst(node *phead, int finddata,int newdata) {
	for (node *p = phead; p != NULL; p = p->pNext) {
		if (p->data == finddata) {
			p->data = newdata;
			return p;										//�����ҵ��ĵ�ַ
		}
	}
	return NULL;
}

node *deletefirst(node *phead, int finddata) {
	node *p1 = NULL, *p2 = NULL;											//����ָ��
	p1 = phead;												//����ͷ�ڵ�
	while (p1 != NULL) {
		if (p1->data != finddata) {
			p2 = p1;										//p2�Ǳ���p1��һ��λ��
			p1 = p1->pNext;									//��ǰ�ƶ�
		}
		else {
			break;
		}
	}

	if (p1 != phead) {
		p2->pNext = p1->pNext;								//����p1
		free(p1);											//ɾ��p1
	}
	else {
		phead = phead->pNext;
		free(p1);											//ͷ��ɾ��
	}

	return phead;
}


node *insertfirst(node *phead, int finddata, int newdata) {
	node *p1 = NULL, *p2 = NULL;											//����ָ��
	p1 = phead;												//����ͷ�ڵ�
	while (p1 != NULL) {
		if (p1->data != finddata) {
			p2 = p1;										//p2�Ǳ���p1��һ��λ��
			p1 = p1->pNext;									//��ǰ�ƶ�
		}
		else {
			break;
		}
	}

	node *pnew = malloc(sizeof(node));						//�µĽڵ�
	pnew->data = newdata;
	pnew->pNext = NULL;										//��ֵ

	if (phead == p1) {
		pnew->pNext = phead;								//����ͷ�ڵ�
		phead = pnew;										//ͷ������
	}
	else {
		pnew->pNext = p1;
		p2->pNext = pnew;
	}
	return phead;
}


void bubblesort(node *phead) {

	//���������������κ�һ��Ԫ��
	//�����ҵ�N��Ԫ�أ��ȱ���N-1

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
		node *pfen = fen(pbegin, pback);							//ȡ�м��
		quicksort(pbegin,pfen);										//�ֶ�ǰ��
		quicksort(pfen->pNext, pback);								//�ֶκ���
	}
}


node *fen(node *pbegin, node *pback) {
	int key = pbegin->data;											//�Ե�һ������Ϊ�ֶ�
	node *p = pbegin;												//��һ���ڵ�
	node *q = pbegin->pNext;										//�ڶ����ڵ�
	
	while (q!=pback) {
		if (q->data < key) {
			p = p->pNext;											//ѭ����һ���ڵ�
			int temp = p->data;
			p->data = q->data;
			q->data = temp;											//����
		}
		q = q->pNext;												//ѭ���ڶ���ָ��

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
		int key = phead->data;										//��ȡ��һ��ֵ���ֽ���
		node *p1 = phead;
		for (node *p2 = phead->pNext; p2 != pback; p2 = p2->pNext) {
			if (p2->data < key) {
				p1 = p1->pNext;										//ѭ������һ��
				int temp = p1->data;								//����
				p1->data = p2->data;
				p2->data = temp;
			}
		}

		int temp = p1->data;										//����
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
		return 1 + getnum_recursion(phead->pNext);					//���ݲ���
	}
}


node *rev(node *phead) {								//����ķ�ת
	if (phead == NULL || phead->pNext == NULL) {
		return NULL;
	}
	else {
		node*pre, *pcur, *pnext;						//�����ڵ�
		pre = pcur = pnext = NULL;						//��ֵ���ʽ

		pre = phead;
		pcur = phead->pNext;
		while (pcur) {									//pcur!=NULL
			pnext = pcur->pNext;						//������һ���ڵ�
			pcur->pNext = pre;							//ǰһ���ڵ�
			pre = pcur;
			pcur = pnext;								//����
		}
		phead->pNext = NULL;
		phead = pre;									//����ڵ�
	}
	return phead;
}

node *rev_recursion(node*phead) {
	if (phead == NULL || phead->pNext == NULL) {
		return phead;
	}
	else {
		node* pnext = phead->pNext;						//˳��
		node* head = rev_recursion(pnext);				//�ݹ���ã�������һ���ڵ㣬��Ѱ���еĽڵ�
		pnext->pNext = phead;							//����
		phead->pNext = NULL;							//����
		return head;
	}
}