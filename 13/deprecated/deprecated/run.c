#include<stdio.h>
#include<stdlib.h>

void run1() {

}

void run2() {

}

void run3() {

}

void main() {
	run1();
	run2();
	run3();
#pragma deprecated(run1,run2,run3)		//�޶�������������,����һ������ʹ��run1,run2,run3������һ�β�����ʹ��
	run1();
	run2();
	run3();
}