#include<stdio.h>
#include<stdlib.h>
#include<string.h>

													//�������������ã��˷ѵȴ�����ʱ�䣬�������С
void run1() {
	puts("123");
}

void run2() {
	puts("123456");
}


#pragma intrinsic(run1,run2)						//����Ϊ��������
#pragma intrinsic(memset,strlen)					//�����Զ��庯����ϵͳ����Ϊ��������

void main() {

	run1();
	run2();

#pragma function(run1)								//ȡ����������

	getchar();
}