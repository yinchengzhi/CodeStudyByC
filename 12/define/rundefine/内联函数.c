#include<stdio.h>

#define N 2+8
#define f(x) x*x
#define go(y) printf("%d",y);
#define run() {puts("�����յ���1");\
			   puts("�����յ���2");\
			   puts("�����յ���3");}

#define getmax(x,y) x>y?x:y

//����������#define���������������ٶȣ���Լ�����ĵȴ����ص�ִ��ʱ��
//���Զ��������һ��д���£�����\����,û�п����

void main() {

	printf("%d", getmax(10, 20));
	printf("\n%f", getmax(10.1, 20.2));
	//go(1000);
	run();
	//printf("%d", f(N));

	system("pause");
}