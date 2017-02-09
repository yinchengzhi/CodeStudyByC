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
#pragma deprecated(run1,run2,run3)		//限定函数的作用域,上面一段允许使用run1,run2,run3，下面一段不允许使用
	run1();
	run2();
	run3();
}