#include"mem.h"

struct LinkNode *phead = NULL;

#define malloc mymalloc
#define free myfree
#define realloc myrealloc

void main() {

	int a;
	int *p;

	void *p1 = malloc(1024 * 1024 * 100);
	void *p2 = malloc(1024 * 1024 * 100);
	void *p3 = malloc(1024 * 1024 * 100);
	void *p4 = malloc(1024 * 1024 * 100);
	getinfo(phead);

	realloc(p1, 1024 * 1024 * 200);

	getinfo(phead);
	free(p2);
	free(p2);
	free(1003);

	getinfo(phead);
																			//可设置断点
	deleteall(phead);
																			//可设置断点
	system("pause");
}