#include"list.h"


void init(List *p) {
	p->head = p->tail = NULL;
}


void adddatahead(List *p, int data) {
	node *pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;									//����һ���ڵ�
	if (p->head == NULL || p->tail == NULL) {
		p->head = pnew;
		p->tail = pnew;									//����һ���ڵ㣬û�нڵ�
	}
	else {
		p->head->pPre = pnew;							//ǰ��
		pnew->pNext = p->head;							//���
		p->head = pnew;									//���룬ͷ��
	}
}

void adddataback(List *p, int data) {
	node *pnew = malloc(sizeof(node));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;									//����һ���ڵ�
	if (p->head == NULL || p->tail == NULL) {
		p->head = pnew;
		p->tail = pnew;									//����һ���ڵ㣬û�нڵ�
	}
	else {
		p->tail->pNext = pnew;							//���
		pnew->pPre = p->tail;							//����ڵ��ǰ��
		p->tail = pnew;									//β���ڵ㱣�棬���
	}
}

void show(List *p) {
	node *pshow = p->head;
	while (pshow!=NULL) {
		printf("%4d", pshow->data);
		pshow = pshow->pNext;
	}
	printf("\n");
}

void revshow(List *p) {
	node *pshow = p->tail;
	while (pshow != NULL) {
		printf("%4d", pshow->data);
		pshow = pshow->pPre;
	}
	printf("\n");
}


node* find(List *p,int data) {
	node *pfind = p->head;
	while (pfind != NULL) {
		if (pfind->data == data) {
			return pfind;
		}
		pfind = pfind->pNext;
	}
	return NULL;
}

node* revfind(List *p,int data) {
	node *pfind = p->tail;
	while (pfind != NULL) {
		if (pfind->data == data) {
			return pfind;
		}
		pfind = pfind->pPre;
	}
	return NULL;
}

void insertdata(List *p, int data, int newdata) {
	node *pnew = malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;
	pnew->pPre = NULL;										//����һ���ڵ�

	node *p1 = NULL;
	p1 = p->head;
	while (p != NULL) {
		if (p1->data != data) {
			p1 = p1->pNext;
		}
		else {
			break;
		}
	}

	if (p1 != p->head && p1 != p->tail) {
		pnew->pNext = p1;
		pnew->pPre = p1->pPre;

		p1->pPre->pNext = pnew;
		p1->pPre = pnew;
	}
	else if (p1 == p->head) {
		p1->pPre = pnew;
		pnew->pNext = p1;
		p->head = pnew;
	}
	else if (p1 == p->tail) {
		pnew->pNext = p1;
		pnew->pPre = p1->pPre;
		p1->pPre->pNext = pnew;
		p1->pPre = pnew;
	}
}

void deletedata(List *p, int data) {
	node *p1 = NULL;
	p1 = p->head;
	while (p!= NULL) {
		if (p1->data != data) {
			p1 = p1->pNext;
		}
		else {
			break;
		}
	}
	//p1��¼���ҵ���λ��
	if (p1 != p->head && p1 != p->tail) {
		p1->pPre->pNext = p1->pNext;
		p1->pNext->pPre = p1->pPre;
		free(p1);
	}
	else if (p1 == p->head) {
		p->head = p1->pNext;
		p1->pNext->pPre = NULL;								//p->head->Ppre = NULL; ?
		free(p1);
	}
	else if (p1 == p->tail) {
		p->tail = p1->pPre;
		p1->pPre->pNext = NULL;								//p->tail->Ppre = NULL; ?
		free(p1);
	}
}