#include<stdio.h>
#include<stdlib.h>
//#line 1

void main() {							//计数，从这一行开始
	
	printf("%d",__LINE__);				//改变行数，某一段到某一段，一共多少行
	printf("\n%s", __FILE__);

	getchar();
}