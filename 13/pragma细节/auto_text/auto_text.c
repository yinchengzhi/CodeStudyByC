#include<stdio.h>
#include<stdlib.h>
void run();
void run1() {

}

//常量字符串分配到run函数所在的代码区,声明一个字符串分配到函数所在，函数无法定义
#pragma alloc_text("yinchengsection",run)

void main() {

	char *p = "yinchengsection";
	printf("%s", p);

	run1();

	getchar();
}