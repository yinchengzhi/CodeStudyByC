//#include<stdio.h>
//
//#pragma warning(disable:4996)
//#pragma warning(once:4700)							//同类错误提示一个
//
////#pragma warning(disable:4700)						//禁用警告当中的错误
//
//void main() {
//
//	int num = 10;
//	int data;
//	int numnew;
//
//	//scanf("%d", &num);
//	printf("%d%d%d", num, data, numnew);
//
//}

//#pragma warning(disable:4507 34;once:4385;error:164)
//等价于:
//#pragma warning(disable:4507 34)					//不显示4507和34号警告信息
//#pragma warning(once:4385)						//4385号警告信息仅报告一次
//#pragma warning(error:164)						//把164号警告信息作为一个错误

//#include<stdio.h>
////#pragma warning(error:4047)						//警告当作错误
//#pragma warning(default:4047)						//警告恢复默认状态
//
//void main() {
//	int *p = 5;
//
//	getchar();
//}



#include<stdio.h>

//#pragma warning(push)						//让一个多个warning生效进栈
//#pragma warning(disable:4996)
//#pragma warning(error:4047)
//#pragma warning(pop)						//一个多个	无效出栈pop


void main() {

	int num;
	int *p = 5;
	scanf("%d", &num);

}