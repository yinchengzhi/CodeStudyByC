#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct data{
	int num;
};
void main() {

	//int a[3][4];
	//int (*a)[4]; int *a[4];
	//printf("%p,%p", a, a + 1);
	struct data(*p)[10] = malloc(sizeof(struct data) * 90);		//动态分配二维数组
	int k = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%4d", p[i][j].num = k++);
		}
		printf("\n");
	}

	system("pause");
}


void main1z() {
	//struct data *p = malloc(sizeof(struct data) * 10);
	struct data *p = alloca(sizeof(struct data) * 10);
	int i = 0;
	for (struct data*newp = p; newp < p + 10; newp++) {
		//printf("\n%p,%d", newp, ((*newp).num = i++));
		printf("\n%p,%d", newp, newp->num = i++);
	}
	system("pause");
}

void main2z() {

	struct data**pp;		//分块数组
	int j = 0;
	pp = malloc(sizeof(struct data*)*10);		//先分配指针数组
	for (int i = 0; i < 10; i++) {
		pp[i] = malloc(sizeof(struct data) * 10);				//每一个指针分配内存
		for (struct data*newp = pp[i]; newp < pp[i] + 10; newp++) {			//遍历
			//printf("%p,%d	", newp, newp->num = j++);
			printf("%d	",newp->num = j++);
		}
		printf("\n");
	}

	system("pause");
}