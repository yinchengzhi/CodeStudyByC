#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *pNext;
};


void init(struct node **pNext);
struct node *enq(struct node *p, int newdata);
struct node *deq(struct node *p, int *pout);
void show(struct node *p);


void init(struct node **pNext) {
	*pNext = NULL;
}

struct node* enq(struct node *p, int newdata) {

	struct node* pnew = malloc(sizeof(struct node));
	pnew->data = newdata;
	pnew->pNext = NULL;

	if (p == NULL) {
		p = pnew;
		return p;
	}
	else {
		pnew->pNext = p;
		p = pnew;
		return p;
	}
}

struct node* deq(struct node *p, int *pout) {
	if (p == NULL) {
		abort();
		return NULL;
	}
	else if (p->pNext == NULL) {
		*pout = p->data;
		free(p);
		p = NULL;
		return p;
	}
	else {
		struct node*ptemp = p;
		while (ptemp->pNext->pNext!=NULL) {
			ptemp = ptemp->pNext;
		}
		*pout = ptemp->pNext->data;
		ptemp->pNext = NULL;

		free(ptemp->pNext);
		return p;
	}

}


void show(struct node *p) {
	if (p == NULL) {
		return;
	}
	else {
		printf("%4d", p->data);
		show(p->pNext);
	}
}