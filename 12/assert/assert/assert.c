#include<stdio.h>
#include<stdlib.h>
#include<assert.h>									//��������


void main2() {

	int a = 1;
	assert(a == 0);									//������ԣ������ˣ�������
	system("pause");
}

//�꣬�Զ���ʵ��assert
#define ASSERT(x)	\
if((x))				\
{					\
	printf("ASSERT %s������� \n",#x);				\
	printf("�ļ� %s %d�� \n",__FILE__,__LINE__);		\
	printf("���� %s \n",__FUNCTION__);				\
	abort();										\
    getchar();										\
	return;											\
}

void main() {
	int b = 10;
	int a = 0;
	ASSERT(a == 0);									//���������������
	
	//ASSERT(a != 0);
	
	printf("%d", b / a);
	
	//if (a == 0) {
	//	abort();
	//}

	system("pause");
}