#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<memory.h>
struct csdn{
	int id;
	int num;
};

void mainx() {
	int num;
	scanf("%d", &num);
	struct csdn*p1 = malloc(sizeof(struct csdn)*num);   //堆
	struct csdn*p2 = alloca(sizeof(struct csdn)*num);   //栈
	memset(p1, 0, sizeof(struct csdn)*num);
	memset(p2, 0, sizeof(struct csdn)*num);

	for (int i = 0; i < num; i++) {    //动态数组的引用方式
		printf("%d,%d   %d %d\n", p1[i].id = i, p1[i].num, p2[i].id = i, p2[i].num);
	}

	for (int i = 0; i < 10; i++) {     //动态数组的引用方式
		int id;
		scanf("%d", &id);
		for (int j = 0; j < num; j++) {
			if (id == p1[j].id) {
				p1[j].num++;
				p2[j].num++;
			}

		}
	}
	for (int i = 0; i < num; i++) {    //动态数组的引用方式
		printf("%d,%d   %d %d\n", p1[i].id, p1[i].num, p2[i].id, p2[i].num);
	}


	free(p1);

	system("pause");
}

struct MyStruct {
	int id;
	char str[10];
};

void mainy() {
	//int num;
	//scanf("%d", &num);
	//struct csdn*p1 = malloc(sizeof(struct csdn)*num);
	//struct MyStruct *p2 = (struct MyStruct[]) { {10,"20"},{20, "30"} };
	struct csdn*p2 = (struct csdn[]) { 1, 2, 3, 4 };
	printf("%d\n", p2[1].id);
	printf("%d\n", (&p2[1])->id);
	printf("%d\n", (p2+1)->id);		//p[i] 等于 *(p+i)   &p[i] = p+i;
	printf("%d\n", (*(p2 + 1)).id);

	struct csdn csdndata[100];      //int a[100]
	struct csdn *p3 = csdndata;	    //int *p

	struct csdn csdndataX[10][10];  //int a[10][10]
	struct csdn (*p4)[10] = csdndataX;	//int (*p)[10]

	//struct csdn csdnx = { 10,20 };
	//struct csdn *p = &csdnx;
	//printf("%d\n", p->id);
	//printf("%d\n", (*p).id);


	system("pause");
}

void main11() {

	struct csdn csdndata[100];      //int a[100]
	struct csdn *p3 = csdndata;	    //int *p

	struct csdn csdndataX[10][10];  //int a[10][10]
	struct csdn(*p4)[10] = csdndataX;	//int (*p)[10] = malloc(sizeof(int)*100)

	struct csdn(*p5)[10] = malloc(sizeof(struct csdn) * 50);
	p5[3][4];

}



