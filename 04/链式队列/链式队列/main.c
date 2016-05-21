#include"queue.h"

void main() {

	Queue *phead;
	init(&phead);
	for (int i = 0; i < 10; i++) {
		phead = enq(phead, i);
		printf("\nqueue");
		show(phead);
	}

	printf("\n\n\n");
	while (phead != NULL) {
		datatype data;
		phead = deq(phead, &data);
		printf("\nÀ­³öµÄÊº%d", data);
		printf("\nqueue");
		show(phead);
	}

	system("pause");
}