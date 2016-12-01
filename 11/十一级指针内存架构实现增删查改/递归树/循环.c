#include<stdio.h>
#include<stdlib.h>

int num = 0;

void test1() {		//11
	num++;
	for (int i = 0; i < 10; i++) {
		num++;
	}
}

void test2() {		//111
	num++;
	for (int i = 0; i < 10; i++) {
		num++;
		for (int j = 0; j < 10; j++) {
			num++;
		}
	}
}

void test4() {		//1111
	num++;
	for (int i = 0; i < 10; i++) {
		num++;
		for (int j = 0; j < 10; j++) {
			num++;
			for (int k = 0; k < 10; k++) {
				num++;
			}
		}
	}
}

//1					10	go(0) 10 11
//go(0)				1
//1 10go(0) 10		11	go(1)
//1+10*11			111	go(n)=1+10*g(n-1)

void go(int data) {

	num++;
	if (data == 0) {
		return;
	}

	for (int i = 0; i < 10; i++) {
		go(data - 1);
	}
}

void main() {

	go(5);
	printf("%d", num);

	system("pause");
}