#include"stack.h"

PNODE init(PNODE phead) {							
	phead = NULL;									//��ʼ��ͷָ��
	return phead;
	//��ʼ��һ���ڵ�
	//phead->id = 0;
	//phead->data = 0;
	//phead->pNext = NULL;
}

PNODE push(PNODE phead, int id, datatype data) {	//�Զ���
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
			ptemp = ptemp->pNext;							//ѭ����β��
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

PNODE pop(PNODE phead, PNODE pdata) {						//�³�
	if (phead == NULL) {
		return NULL;
	}
	else if (phead->pNext == NULL) {						//1���ڵ�
		pdata->id = phead->id;
		pdata->data = phead->data;							//��ֵ
		free(phead);
		phead = NULL;
		return phead;										//ɾ��һ���ڵ�
	}
	else {
		PNODE ptemp = phead;
		while (ptemp->pNext->pNext != NULL) {
			ptemp = ptemp->pNext;							//ѭ���������ڶ����ڵ�
		}
		pdata->id = ptemp->pNext->id;
		pdata->data = ptemp->pNext->data;					//��ֵ
		free(ptemp->pNext);
		ptemp->pNext = NULL;
		return phead;
	}
}

PNODE clear(PNODE phead) {									//���
	if (phead == NULL) {
		return NULL;
	}
	else {
		PNODE p1 = phead, p2 = NULL;
		while (p1->pNext != NULL) {
			p2 = p1->pNext;									//����ڶ����ڵ��λ��
			p1->pNext = p2->pNext;							//����p2;
			free(p2);
		}
		free(phead);										//ɾ����һ���ڵ�
		phead = NULL;
		return NULL;
	}
}
void showall(PNODE phead) {									//��ʾȫ������
	if (phead == NULL) {
		return;
	}
	else {
		printf("\n%d,%d,%p,%p",phead->id,phead->data, phead, phead->pNext);
		showall(phead);
	}
}