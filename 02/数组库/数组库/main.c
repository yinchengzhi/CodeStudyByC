
#include"myarray.h"

void main() {
	struct array mydata;
	int a[10] = { 1,2,6,4,5,6,7,8,6,6 };
	int b[5] = { 11,12,13,14,15};
	int c[4] = { 21,22,23,24 };
	initwitharray(&mydata, a, 10);
	show(&mydata);

	addobjects(&mydata, b, 5);
	addobjects(&mydata, c, 4);
	insertobject(&mydata, 1, 999);
	show(&mydata);

	//changefirstobject(&mydata, 5, 955);
	//changeallobject(&mydata, 6, 66);
	//show(&mydata);

	//insertobjects(&mydata, 8, c, 4);
	//show(&mydata);

	//deletefirstobject(&mydata, 7);
	//show(&mydata);

	//deleteallobject(&mydata, 6);
	//show(&mydata);

	struct Res res = findall(&mydata, 6);
	for (int i = 0; i < res.n; i++) {
		printf("\n%p,%d", res.ppstart[i],*res.ppstart[i]);
	}

	system("pause");
}