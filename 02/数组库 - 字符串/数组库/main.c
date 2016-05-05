
#include"myarray.h"

void main() {
	struct array mydata;
	char *str[5] = {"calc","notepad","tasklist","pause","123"};
	char *str1[3] = { "calc","call","myphone" };
	initwitharray(&mydata, str, 5);
	show(&mydata, showdata);
	//addobjects(&mydata, str1, 3);
	//show(&mydata, showdata);
	insertobjects(&mydata, "123", str1, 3);
	show(&mydata, showdata);

	deleteallobject(&mydata, "calc");
	show(&mydata, showdata);
	system("pause");
}