#include"环形链表.h"

void main1() {

	//printf("%d %d\n", sizeof(node), sizeof(PNODE));
	PNODE phead = NULL;										//头节点
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
	PNODE phead = NULL;										//头节点
	for (int i = 0; i < 10; i++) {
		phead = addback(phead, i);							//插入数据
	}

	PNODE p = phead;
	while (getnum(phead)!=1) {
		for (int i = 0; i < 4; i++) {
			p = p->pNext;									//循环
		}
		phead = deletefirstp(phead, p->data,&p);				//根据数据删除
		printf("\n\n");
		showall(phead);										//初始化
	}


	system("pause");

}

