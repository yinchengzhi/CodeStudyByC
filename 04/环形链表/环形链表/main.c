#include"��������.h"

void main1() {

	//printf("%d %d\n", sizeof(node), sizeof(PNODE));
	PNODE phead = NULL;										//ͷ�ڵ�
	for (int i = 0; i < 10; i++) {
		phead = addback(phead,i);
		//phead = addfront(phead, i);
	}

	//PNODE pfind = findfirst(phead, 6);
	//pfind->data = 30;

	showall(phead);
	printf("\n\n\n");
	phead = insertfirst(phead, 4, 999);
	//phead = deletefirst(phead, 10);

	showall(phead);
	system("pause");
}



void main() {
	PNODE phead = NULL;										//ͷ�ڵ�
	for (int i = 0; i < 10; i++) {
		phead = addback(phead, i);							//��������
	}

	PNODE p = phead;
	while (getnum(phead)!=1) {
		for (int i = 0; i < 4; i++) {
			p = p->pNext;									//ѭ��
		}
		phead = deletefirstp(phead, p->data,&p);				//��������ɾ��
		printf("\n\n");
		showall(phead);										//��ʼ��
	}


	system("pause");

}

