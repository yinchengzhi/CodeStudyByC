#include<stdio.h>
#include<stdlib.h>

struct MyStruct{
	int data;	//数据域
	struct MyStruct *pNext;			//指针域
};

void show(struct MyStruct *p) {
	if (p == NULL) {
		return;
	}
	else {
		show(p->pNext);									//跳到下一个节点
		printf("%d	%p	%p\n", p->data, p, p->pNext);
	}
}

void main() {
	struct MyStruct *p;
	struct MyStruct s1;
	struct MyStruct s2;
	struct MyStruct s3;
	struct MyStruct s4;
	struct MyStruct s5;

	p = &s1;

	s1.data = 1;
	s2.data = 2;
	s3.data = 3;
	s4.data = 4;
	s5.data = 5;

	s1.pNext = &s2;
	s2.pNext = &s3;
	s3.pNext = &s4;
	s4.pNext = &s5;
	s5.pNext = NULL;

	//printf("%d\n", p->data);
	//printf("%d\n", p->pNext->data);
	//printf("%d\n", p->pNext->pNext->data);
	//printf("%d\n", p->pNext->pNext->pNext->data);

	//for (struct MyStruct *px = p; px != NULL; px = px->pNext) {
	//	printf("%d	%p	%p\n", px->data,px,px->pNext);
	//}

	show(p);

	system("pause");
}