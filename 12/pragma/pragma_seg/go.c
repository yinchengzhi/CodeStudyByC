#include<stdio.h>
#include<stdlib.h>

//�Զ������Σ����Ա�������Ż�
//pop�����뺯��ѹ�����Σ�push���ڹ�����

//����Ķ�����
int data;
void go1() {
	puts("go1");
}

#pragma code_seg(".yincheng")				//����һ��

//#pragma code_seg("my_data1")
void go2() {
	puts("go2");
}

#pragma code_seg(pop,"RX","yincheng")		//����
#pragma code_seg(push,"RX","yincheng")		//ѹ��

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