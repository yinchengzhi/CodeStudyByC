#include<stdio.h>
#include<stdlib.h>
void run();
void run1() {

}

//�����ַ������䵽run�������ڵĴ�����,����һ���ַ������䵽�������ڣ������޷�����
#pragma alloc_text("yinchengsection",run)

void main() {

	char *p = "yinchengsection";
	printf("%s", p);

	run1();

	getchar();
}