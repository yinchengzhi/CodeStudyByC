#include<stdio.h>
#include<stdlib.h>

//自定义程序段，可以避免代码优化
//pop数据与函数压入程序段，push放在公共端

//编译的独立性
int data;
void go1() {
	puts("go1");
}

#pragma code_seg(".yincheng")				//创建一段

//#pragma code_seg("my_data1")
void go2() {
	puts("go2");
}

#pragma code_seg(pop,"RX","yincheng")		//弹出
#pragma code_seg(push,"RX","yincheng")		//压入

//#pragma code_seg("my_data2")
void go3() {
	puts("go3");
}
//#pragma code_seg("my_data3")
void go4() {
	puts("go4");
}

void main() {
	go1();
	go2();
	go3();

	system("pause");
}