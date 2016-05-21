#include"queue.h"

void main() {

	PQueue phead;
	init(&phead);
	phead = enq(phead, 100, 4);
	phead = enq(phead, 100, 2);
	phead = enq(phead, 100, 1);
	phead = enq(phead, 100, 3);
	phead = enq(phead, 100, 5);
	phead = enq(phead, 101, 5);
	phead = enq(phead, 102, 5);
	printf("\n此时状态");
	show(phead);

	while (phead!=NULL) {
		Queue qu;
		phead = deq(phead,&qu);
		printf("\n free %d %d",qu.high,qu.data);
		printf("\n此时状态");
		show(phead);
	}

	system("pause");
}