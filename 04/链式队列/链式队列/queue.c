#include"queue.h"

void init(PQueue *pphead) {								//��ʼ��					
	*pphead = NULL;

}

PQueue enq(PQueue phead, datatype data) {				//���
	PQueue pnew = malloc(sizeof(Queue));				//��������
	pnew->data = data;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;									//ֱ�Ӳ���
	}
	else {
		PQueue ptemp = phead;
		while (ptemp->pNext!=NULL){
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

PQueue deq(PQueue phead, datatype *pdata) {				//����
	if (phead == NULL) {

	}
	else{
		*pdata = phead->data;							//��ȡ����������
		PQueue ptemp = phead;
		phead = phead->pNext;							//�洢��һ���ڵ�
	}
	return phead;
}

void show(PQueue phead) {								//��ʾ����
	if (phead == NULL) {
		return;
	}
	else {
		printf("%5d", phead->data);
		show(phead->pNext);								//�ݹ����
	}
}