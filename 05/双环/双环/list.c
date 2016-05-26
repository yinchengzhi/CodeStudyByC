
#include"list.h"


void init(Dlist *p) {
	p->head = p->tail = NULL;						//初始化作用
}

void adddataback(Dlist *p, int data) {
	PNODE pnew = malloc(sizeof(NODE));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;

	if (p->head == NULL&&p->tail == NULL) {
		p->tail = p->head = pnew;
		pnew->pPre = pnew->pNext = pnew;			//插入一个节点
	}
	else if (p->head == p->tail) {					//仅有一个节点
		p->head->pPre = pnew;
		p->head->pNext = pnew;

		pnew->pPre = p->head;
		pnew->pNext = p->head;
		p->tail = pnew;								//保存尾部
	}
	else {
		pnew->pPre = p->tail;
		pnew->pNext = p->head;
		p->tail->pNext = pnew;
		p->head->pPre = pnew;
		p->tail = pnew;								//保存尾部
	}
}

void showall(Dlist *p) {
	if (p->head == NULL&&p->tail == NULL) {
		return;
	}
	else if (p->head == p->tail) {					
		PNODE pl = p->head;
		printf("\n%d,%p,%p,%p",pl->data, pl, pl->pPre, pl->pNext);
	}
	else {
		PNODE pl = p->head;
		for (; pl->pNext != p->head; pl = pl->pNext) {
			printf("\n%d,%p,%p,%p", pl->data, pl, pl->pPre, pl->pNext);
		}
		printf("\n%d,%p,%p,%p", pl->data, pl, pl->pPre, pl->pNext);
	}
}


void adddatahead(Dlist *p, int data) {
	PNODE pnew = malloc(sizeof(NODE));
	pnew->data = data;
	pnew->pNext = NULL;
	pnew->pPre = NULL;

	if (p->head == NULL&&p->tail == NULL) {
		p->tail = p->head = pnew;
		pnew->pPre = pnew->pNext = pnew;			//插入一个节点
	}
	else if (p->head == p->tail) {					//仅有一个节点
		p->head->pNext = p->head->pPre = pnew;
		pnew->pPre = pnew->pNext = p->head;
		p->head = pnew;
	}
	else {
		pnew->pPre = p->tail;
		pnew->pNext = p->head;

		p->head->pPre = pnew;
		p->tail->pNext = pnew;
		p->head = pnew;
	}
}

PNODE find(Dlist *p, int data) {
	if (p->head == NULL&&p->tail == NULL) {
		return;
	}
	else if (p->head == p->tail) {
		PNODE pl = p->head;
		if (pl->data == data) {
			return pl;
		}
		else {
			return NULL;
		}
	}
	else {
		PNODE pl = p->head;
		for (; pl->pNext != p->head; pl = pl->pNext) {
			if (pl->data == data) {
				return pl;
			}
		}
		if (pl->data == data) {
			return pl;
		}
		else {
			return NULL;
		}
	}
}

void change(Dlist *p, int data, int newdata) {
	if (p->head == NULL&&p->tail == NULL) {
		return;
	}
	else if (p->head == p->tail) {
		PNODE pl = p->head;
		if (pl->data == data) {
			pl->data = newdata;
		}
	}
	else {
		PNODE pl = p->head;
		for (; pl->pNext != p->head; pl = pl->pNext) {
			if (pl->data == data) {
				pl->data = newdata;
			}
		}
		if (pl->data == data) {
			pl->data = newdata;
		}
	}
}

void insert(Dlist *p, int data, int newdata) {
	PNODE pnew = malloc(sizeof(NODE));			//开辟一个节点
	pnew->data = newdata;
	pnew->pNext = NULL;
	pnew->pPre = NULL;

	PNODE pl = NULL;
	pl = p->head;								//第一个节点
	while (pl->pNext != p->head) {
		if (pl->data == data) {
			break;
		}
		else {
			pl = pl->pNext;
		}
	}
	//前面插入
	if (p->head == pl&&p->tail == pl) {				
		p->head->pNext = p->head->pPre = pnew;
		pnew->pPre = pnew->pNext = p->head;
		p->head = pnew;
	}
	else if (p->head == pl&&p->tail != pl) {
		pnew->pPre = p->tail;
		pnew->pNext = pl;
		p->tail->pNext = pnew;
		p->head->pPre = pnew;
		p->head = pnew;
	}
	else {
		pnew->pPre = pl->pPre;
		pnew->pNext = pl;
		pl->pPre->pNext = pnew;
		pl->pPre = pnew;
	}
}

void deletedata(Dlist *p, int data) {
	PNODE pl = NULL;
	pl = p->head;								//第一个节点
	while (pl->pNext != p->head) {
		if (pl->data == data) {
			break;
		}
		else {
			pl = pl->pNext;
		}
	}
	//n-1
	printf("\n%d",pl->data);
	if (p->head == pl&&p->tail == pl) {
		free(pl);
		p->head = NULL;
		p->tail = NULL;
	}
	else if (p->head == pl&&p->tail != pl) {
		pl->pNext->pPre = p->tail;
		pl->pPre->pNext = pl->pNext;
		p->head = pl->pNext;
		free(pl);
	}
	else if (p->tail == pl &&p->head != pl) {
		pl->pNext->pPre = pl->pPre;
		pl->pPre->pNext = p->head;
		p->tail = pl->pPre;
		free(pl);
	}
	else{
		pl->pPre->pNext = pl->pNext;
		pl->pNext->pPre = pl->pPre;
		free(pl);
	}
}