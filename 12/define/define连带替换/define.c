#include<stdio.h>
#define M 10
#define N 2+8
#define X M/N
#define MN M/N+M/X

void main1() {
	printf("%d", MN);
	getchar();
}

#undef MN

void main2() {

	//printf("%d", MN);

	getchar();
}