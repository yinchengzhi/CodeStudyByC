#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void main1x() {

	node *phead = NULL;			//ͷ�ڵ㲻�����ڴ�
	//init(phead);				//��ʼ��һ���ڵ㣬�����Գ�ʼ��ͷ�ڵ�
	phead = addback(phead, 14);
	phead = addback(phead, 3);
	phead = addback(phead, 15);
	phead = addback(phead, 16);
	phead = addback(phead, 8);
	phead = addback(phead, 12);
	phead = addback(phead, 13);
	phead = addback(phead, 30);

	showall(phead);
	//printf("%d",getnum_recursion(phead));



	//myquicksort(phead, NULL);
	printf("\n\n\n");
	//bubblesort(phead);

	phead = rev_recursion(phead);

	//printf("\n\n\n");
	//phead = insertfirst(phead, 14, 99);
	//phead = insertfirst(phead, 16, 199);
	//phead = insertfirst(phead, 11, 899);
	//printf("\n\n\n");
	//phead = deletefirst(phead, 11);
	//phead = deletefirst(phead, 14);
	//phead = deletefirst(phead, 16);

	//addhead(&phead,20);
	//addhead(&phead, 21);
	//addhead(&phead, 22);

	//node *pfind = searchfirst(phead, 13);
	//pfind->data = 99;


	showall(phead);
	system("pause");
}


void main2x() {
	node *phead1 = NULL;								//ͷ�ڵ㲻�����ڴ�
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 10);
	phead1 = addback(phead1, 12);
	phead1 = addback(phead1, 14);

	node *phead2 = NULL;								//ͷ�ڵ㲻�����ڴ�
	phead2 = addback(phead2, 1);
	phead2 = addback(phead2, 3);
	phead2 = addback(phead2, 5);
	phead2 = addback(phead2, 7);
	phead2 = addback(phead2, 9);

	node *phead = NULL;									//123456
	node *p1 = phead1;
	node *p2 = phead2;
	// 1 2 3 5 7
	// 4
	while (p2 != NULL || p1 != NULL) {
		if (p1!=NULL && p2!=NULL) {						//��������
			if (p1->data < p2->data) {
				phead = addback(phead, p1->data);
				p1 = p1->pNext;
			}
			else {
				phead = addback(phead, p2->data);
				p2 = p2->pNext;
			}
		}
		else {
			while (p1 != NULL) {						//β�����
				phead = addback(phead, p1->data);
				p1 = p1->pNext;
			}

			while (p2 != NULL) {						//β�����
				phead = addback(phead, p2->data);
				p2 = p2->pNext;
			}
			break;
		}
	}
	showall(phead);

	system("pause");
}


node*getmid(node *phead) {
	if (phead == NULL || phead->pNext == NULL) {
		return phead;
	}
	else {
		node *p1 = phead;
		node *p2 = phead;
		while (p2->pNext!= NULL) {
			p1 = p1->pNext;								//ǰ��һ��
			p2 = p2->pNext;								//ǰ��2��
			if (p2->pNext != NULL) {					//��ǰ����
				p2 = p2->pNext;
			}
		}

		return p1;
	}
}

void main3x() {
	node *phead1 = NULL;								//ͷ�ڵ㲻�����ڴ�
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 10);
	phead1 = addback(phead1, 12);
	phead1 = addback(phead1, 14);

	node *pmid = getmid(phead1);
	printf("%d\n", pmid->data);

	system("pause");
}

void showall_bycircle(node *phead) {					//��������
	node*p = phead;
	for (; p->pNext != phead; p = p->pNext) {
		printf("%d\n", p->data);
	}
	printf("%d\n", p->data);
}

int is_circle(node *phead) {
	int flag = 0;
	for (node*p1 = phead, *p2 = phead; p1 != NULL && p2!=NULL; p1 = p1->pNext,p2 = p2->pNext) {			//��ѭ��
		if (p2->pNext != NULL) {
			p2 = p2->pNext;
		}
		if (p1 == p2) {
			flag = 1;
			break;
		}
	}
	return flag;
}

void main() {
	node *phead1 = NULL;								//ͷ�ڵ㲻�����ڴ�
	phead1 = addback(phead1, 1);
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 3);
	phead1 = addback(phead1, 4);						//�м�
	phead1 = addback(phead1, 5);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 7);
	phead1 = addback(phead1, 8);
	phead1 = addback(phead1, 9);
	node *p = phead1;

	for (; p->pNext != NULL; p = p->pNext) {

	}
	p->pNext = phead1;									//β������ͷ

	showall_bycircle(phead1);

	printf("%d\n", is_circle(phead1));

	system("pause");
}