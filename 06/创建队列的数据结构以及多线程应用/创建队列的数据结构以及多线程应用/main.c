#include"queue.h"

myQ my1;										//队列保存多线程的结果

struct threadinfo {
	int *pstart;
	int length;
	int key;
	int id;
};

void find(void *p) {
	struct threadinfo *pinfo = p;				//接收参数
	printf("\n线程%d开始", pinfo->id);
	for (int *px = pinfo->pstart; px < pinfo->pstart + pinfo->length; px++) {
		if (*px == pinfo->key) {
			printf("\n线程%d找到%p,%p", pinfo->id, px, *px);
			enQ(&my1, px);						//地址入队
		}
	}

	printf("\n线程%d结束", pinfo->id);
}


void main() {
	init(&my1);									//初始化队列
	int a[100];
	time_t ts;
	srand((unsigned int)time(&ts));
	for (int i = 0; i < 100; i++) {
		a[i] = rand() % 10;
	}

	struct threadinfo info[10];
	for (int i = 0; i < 10; i++) {
		info[i].pstart = a + i * 10;
		info[i].length = 10;
		info[i].key = 5;
		info[i].id = i;
		_beginthread(find, 0, &info[i]);
	}

	Sleep(5000);

	//弹出队列所有数据
	while (!isEmpty(&my1)) {
		printf("\n弹出的屎=%p", getlast(&my1));
		deQ(&my1);
		print(&my1);
	}


	system("pause");
}



void mainABC() {
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