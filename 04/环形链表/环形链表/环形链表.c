#include"��������.h"

PNODE addback(PNODE phead, int data) {				//β������
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;								//����ռ�
	if (phead == NULL) {
		phead = pnew;
		pnew->pNext = phead;
	}
	else {
		//ѭ����β��
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;													//ͷβ����
	}
	return phead;
}

PNODE addfront(PNODE phead, int data) {											//ͷ������
	PNODE pnew = malloc(sizeof(node));
	pnew->data = data;															//����ռ�
	if (phead == NULL) {
		phead = pnew;
		pnew->pNext = phead;
	}
	else {
		//ѭ����β��
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;															//��β�巨����������ڴ�
	}
	return phead;
}

void showall(PNODE phead) {														//����Ի��������ӡ
	if (phead == NULL) {
		return;
	}
	else if (phead->pNext==phead) {
		printf("ĸ����%d��,%p,%p\n", phead->data, phead, phead->pNext);					//��ӡһ���ڵ�
	}
	else {
		PNODE p = phead;
		while (p->pNext != phead) {
			printf("ĸ����%d��,%p,%p\n", p->data, p, p->pNext);							//��ӡһ���ڵ�
			p = p->pNext;														//ѭ��
		}
		printf("ĸ����%d��,%p,%p\n", p->data, p, p->pNext);								//������ȵ����
	}
}


PNODE findfirst(PNODE phead, int data) {										//��ǰԤ����
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
			p = p->pNext;														//ѭ��
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
			p1 = p1->pNext;													  //ѭ��������
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

		phead = phead->pNext;												  //�ı�ͷ�ڵ�
		free(p1);															  //�ͷ�p1
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
			p = p->pNext;														//ѭ��
		}
		return i;																//ͳ�Ƽ���
	}
}



PNODE insertfirst(PNODE phead, int finddata, int data) {						//��������
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
		//pnew->pNext = p1->pNext;									�����
		//p1->pNext = pnew;
		//ǰ����Ҫp2
		pnew->pNext = p2->pNext;
		p2->pNext = pnew;
	}
	else{
		//ǰ�����
		/*
		node*p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;
		phead = pnew;

		*/

		//ѭ����β��
		PNODE p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}
		p->pNext = pnew;
		pnew->pNext = phead;													//ͷβ����

	}
	return phead;
}

PNODE deletefirstp(PNODE phead, int data, PNODE *ppnext) {			//ɾ�����ݣ�����ָ��
	PNODE p1 = NULL;
	PNODE p2 = NULL;
	p1 = phead;
	while (p1->pNext != phead) {
		if (p1->data == data) {
			break;
		}
		else {
			p2 = p1;
			p1 = p1->pNext;													  //ѭ��������
		}
	}

	if (p1 != phead) {
		p2->pNext = p1->pNext;
		*ppnext = p1->pNext;												  //����һ���ڵ�
		free(p1);
	}
	else {
		node *p = phead;
		while (p->pNext != phead) {
			p = p->pNext;
		}

		phead = phead->pNext;												  //�ı�ͷ�ڵ�
		*ppnext = p1->pNext;
		free(p1);															  //�ͷ�p1
		p->pNext = phead;
	}
	return phead;
}