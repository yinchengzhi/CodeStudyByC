#include<stdio.h>
#include<stdlib.h>
#include<assert.h>									//触发错误


void main2() {

	int a = 1;
	assert(a == 0);									//程序调试，出错了，跳出来
	system("pause");
}

//宏，自定义实现assert
#define ASSERT(x)	\
if((x))				\
{					\
	printf("ASSERT %s代码出错 \n",#x);				\
	printf("文件 %s %d行 \n",__FILE__,__LINE__);		\
	printf("函数 %s \n",__FUNCTION__);				\
	abort();										\
    getchar();										\
	return;											\
}

void main() {
	int b = 10;
	int a = 0;
	ASSERT(a == 0);									//处理代码出错的问题
	
	//ASSERT(a != 0);
	
	printf("%d", b / a);
	
	//if (a == 0) {
	//	abort();
	//}

	system("pause");
}