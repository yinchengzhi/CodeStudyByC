#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void main1() {

	for (volatile int i = 0; i < INT_MAX; i++) {			//�Ż�,ǿ�ƶ��ڴ�

	}
}


void main() {

	volatile int i = 10;								  //���ݱ�����ı��ʱ��,ǿ�ƶ��ڴ�
	int a = i;
	printf("\ni = %d", a);

	//͵͵�ı�i��ֵ
	_asm {
		mov dword ptr[ebp - 4],20h						   //16����20h����32
	}
	int b = i;
	printf("\ni = %d", b);

	getchar();
}