#include"stack.h"


void toBinary(int num) {
	if (num == 0) {
		return;
	}
	else {
		toBinary(num / 2);
		printf("%d", num % 2);
	}
}

void main() {
	toBinary(10);
	struct LinkNode *phead = NULL;
	phead = init(phead);
	for (int i = 0; i < 10; i++) {
		phead = push(phead, i, i + 100);
	}

	while (phead != NULL) {
		node nd;
		phead = pop(phead, &nd);
		printf("\nµ¯³ö%d,%d", nd.id, nd.data);
	}

	system("pause");
}


void main2x() {
	struct LinkNode *phead = NULL;
	phead = init(phead);
	int num = 10;
	while (num) {									//num!=0
		phead = push(phead, num % 2, 0);
		num /= 2;
	}
	while (phead != NULL) {
		node nd;
		phead = pop(phead, &nd);
		printf("\nµ¯³ö%d,%d", nd.id, nd.data);
	}

	phead = clear(phead);

	printf("\n\n\n");
	num = 10;
	while (num) {									//num!=0
		phead = push(phead, num % 2, 0);
		node nd;
		phead = pop(phead, &nd);
		printf("\nµ¯³ö%d,%d", nd.id, nd.data);
		num /= 2;
	}

	system("pause");
}