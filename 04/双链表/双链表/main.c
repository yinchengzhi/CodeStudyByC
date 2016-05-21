#include"list.h"

void main() {

	List dlist;
	init(&dlist);
	//adddatahead(&dlist, 1);
	//adddatahead(&dlist, 2);
	//adddatahead(&dlist, 3);
	//adddatahead(&dlist, 4);
	//adddatahead(&dlist, 5);
	adddataback(&dlist, 1);
	adddataback(&dlist, 2);
	adddataback(&dlist, 3);
	adddataback(&dlist, 4);
	adddataback(&dlist, 5);

	show(&dlist);

	insertdata(&dlist, 2, 99);
	//deletedata(&dlist, 5);

	//node *pfind = find(&dlist, 3);
	//pfind->data = 999;
	printf("\n\n\n");
	revshow(&dlist);

	system("pause");
}