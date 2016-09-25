#include"list.h"


//尾部插入
PINFO addback(PINFO phead, char password[20]) {
	PINFO pnew = calloc(1, sizeof(INFO));							//开辟内存
	strcpy(pnew->password, password);								//拷贝密码
	pnew->ci = 1;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;												//直接插入
	}
	else {
		pnew->pNext = phead;
		phead = pnew;												//头插
	}
	return phead;
}

//排序
PINFO sortByci(PINFO phead) {
	for (PINFO p1 = phead; p1 != NULL; p1 = p1->pNext) {
		for (PINFO p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p2->pNext != NULL) {
				if (p2->ci < p2->pNext->ci) {
					int citemp = p2->ci;									//交换数据
					p2->ci = p2->pNext->ci;
					p2->pNext->ci = citemp;

					char passtemp[100];
					strcpy(passtemp, p2->password);
					strcpy(p2->password, p2->pNext->password);
					strcpy(p2->pNext->password, passtemp);
				}
			}
		}
	}
}

//排序
PINFO sortBypass(PINFO phead) {
	for (PINFO p1 = phead; p1 != NULL; p1 = p1->pNext) {
		for (PINFO p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p2->pNext != NULL) {
				if (strcmp(p2->password, p2->pNext->password) < 0) {
					int citemp = p2->ci;									//交换数据
					p2->ci = p2->pNext->ci;
					p2->pNext->ci = citemp;

					char passtemp[100];
					strcpy(passtemp, p2->password);
					strcpy(p2->password, p2->pNext->password);
					strcpy(p2->pNext->password, passtemp);
				}
			}
		}
	}
}

//显示
PINFO show(PINFO phead) {
	if (phead == NULL) {
		return;
	}
	else {
		printf("%s,%d\n", phead->password, phead->ci);
		show(phead->pNext);
	}

	return phead;
}

//判断存在与否
int isin(PINFO phead, char password[20]) {
	PINFO p = phead;
	while (p != NULL) {
		if (strcmp(p->password, password) == 0) {
			p->ci += 1;
			return 1;							//存在
		}
		p = p->pNext;
	}
	return 0;									//不在链表内部
}

//写入到文件
void writetofile(PINFO phead) {

}