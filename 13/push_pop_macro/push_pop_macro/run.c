#include<stdio.h>
#include<stdlib.h>

#define X 10
#define Y 20

#define Y 80								//������������

void main() {

	printf("%d", Y);
	getchar();
}

#pragma push_macro("Y")						//Y�ĺ��ջ,����ԭ���ĺ꣬��Ȼ��Ч

#define Y 80								//Y=80��Ч

#pragma pop_macro("Y")						//Y�ĺ��ջ,ȡ��Y����Ч����ԭ����Y��Ч

void main21() {

	printf("\nX=%d", X);					//10
	printf("\nY=%d", Y);					//20

#pragma push_macro("Y")

#define Y 40								//�ڲ������ⲿ,һֱ����
	printf("\nY=%d", Y);

#pragma push_macro("X")						//��ջ
	printf("\nX=%d", X);
#define X 80
	printf("\nX=%d", X);
#pragma pop_macro("X");						//��ջ
	printf("\nX=%d", X);

#pragma pop_macro("Y");
	printf("\nY=%d", Y);

	system("pause");
}