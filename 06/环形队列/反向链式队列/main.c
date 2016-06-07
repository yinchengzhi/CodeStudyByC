#include"linknode.h"

void main() {
	
	struct node *phead;
	init(&phead);

	for (int i = 0; i < 10; i++) {
		phead = enq(phead, i);
		show(phead);
		fputc('\n', stderr);
	}

	while (phead != NULL) {
		int num;
		phead = deq(phead,&num);
		printf("out is %4d\n", num);
		show(phead);
		fputc('\n', stderr);
	}

	system("pause");
}