#include<stdio.h>
#include<stdlib.h>

//ֱ���滻������37��ʮһ
//һ���д
//�����ı�ĳ�����define

#define N 2+8
//define N (2+8)
#define �Ĵ�Կ� void
#define _______ main
#define PI 3.1415
#define A 10;									//�����滻

�Ĵ�Կ� _______() {

	int aA = 10;								//defineֻ�������滻����ʶ���ľֲ��������滻

	printf("A=%d\n", 10000);					//�������滻�ַ����ڲ��Ķ���

	//printf("%d\n", A);
	printf("%d\n", N*N);						//2+8*2+8
	printf("%f,%f,%f\n", PI, PI, PI);

	const int num = 10;
	*(int*)&num = 3;							//α����
	printf("%d", num);

	system("pause");

}