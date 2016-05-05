#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct MyStruct
{
	int data;
	int length;
}csdndata1[3] = {
	{1,2},
	{3,4},
	{5,6}
};
void main() {
	struct MyStruct *p1 = malloc(sizeof(struct MyStruct)*3);
	memset(p1, 0, sizeof(struct MyStruct) * 3);
	for (int i = 0; i < sizeof(csdndata1) / sizeof(csdndata1[0]); i++) {
		printf("%d %d\n", p1[i].data, p1[i].length);
	}

	struct MyStruct *p2 = malloc(sizeof(struct MyStruct)*3);
	p2 = csdndata1;
	for (int i = 0; i < sizeof(csdndata1) / sizeof(csdndata1[0]); i++) {
		printf("%d %d\n", p2[i].data, p2[i].length);
	}

	system("pause");
}