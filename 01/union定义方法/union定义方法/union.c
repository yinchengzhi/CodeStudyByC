#include<stdio.h>
#include<stdlib.h>
union MyUnion {
	int num;
	float f1;
}my2,myX[4],*p1;	//�ڶ���

union{
	int num;
	float f1;
}my3, myX3[5], *px;			//������

union {
	int num;
	float f1;
};

void main() {

	printf("%d\n", sizeof(my3));

	union MyUnion my1, my[3], *p2;			//��һ��
	//�������ʺϣ����ڱ���ʱʱ�̿�ֻ��һ������

	my1.num = 100;
	printf("%d,%f\n", my1.num, my1.f1);
	my1.f1 = 34.897;
	printf("%d,%f", my1.num, my1.f1);

	system("pause");
}