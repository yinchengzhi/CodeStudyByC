#include"queue.h"

void main() {
	myQ my1;									//创建结构体
	init(&my1);

	enQ(&my1, 1);
	print(&my1);

	enQ(&my1, 2);
	print(&my1);

	enQ(&my1, 3);
	print(&my1);

	enQ(&my1, 4);
	print(&my1);

	enQ(&my1, 5);
	print(&my1);

	printf("\n弹出的屎=%d", getlast(&my1));
	deQ(&my1);
	print(&my1);

	printf("\n弹出的屎=%d", getlast(&my1));
	deQ(&my1);
	print(&my1);

	printf("\n弹出的屎=%d", getlast(&my1));
	deQ(&my1);
	print(&my1);

	printf("\n弹出的屎=%d", getlast(&my1));
	deQ(&my1);
	print(&my1);

	printf("\n弹出的屎=%d", getlast(&my1));
	deQ(&my1);
	print(&my1);

	system("pause");
}