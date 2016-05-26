#include"list.h"

void main() {

	Dlist dlist;
	init(&dlist);
	for (int i = 0; i < 5; i++) {
		//adddataback(&dlist, i);
		adddatahead(&dlist, i);
		printf("\n\n\n");
		showall(&dlist);
	}

	for (int i = 0; i < 5; i++) {
		//deletedata(&dlist, i);
		insert(&dlist, i, 998 + i);
		printf("\n\n\n");
		showall(&dlist);
	}

	//PNODE px = find(&dlist, 3);
	//px->data = 19;

	//change(&dlist, 3, 999);
	printf("\n\n\n");

	//showall(&dlist);

	system("pause");
}