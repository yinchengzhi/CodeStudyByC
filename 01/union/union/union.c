#include<stdio.h>
#include<stdlib.h>

//Ҫ��һ���ṹ������������һ����Ա
union MyUnion{
	int num;
	double db;
};

void main() {

	//printf("%d", sizeof(union MyUnion));	  //����ȡ���
	union MyUnion my1;

	my1.db = 1111111111123.988776;		//��һ������

	printf("%8d %f\n", my1.num, my1.db);	//һ�������ı仯��Ӱ������һ������
	
	my1.num = -10;
	
	printf("%8d %f\n", my1.num,my1.db);
	system("pause");
}