#include<stdio.h>
#include<stdlib.h>
struct MyStruct
{
	int a[10];
	int length;
};
void change(struct MyStruct s1) {	//�������ƣ����ڽṹ����Ч(�ṹ���ڲ������飬������Ч)
	printf("\nchange %p",s1.a);
	for (int i = 0; i < s1.length; i++) {
		s1.a[i] = i * 3;
		printf("%d ", s1.a[i]);
	}
}

void main1() {
	struct MyStruct s1 = { {1,2,3,4,5,6,7,8,9,10},10 };
	change(s1);
	printf("\nmain %p",s1.a);
	for (int i = 0; i < s1.length; i++) {
		printf("%d ", s1.a[i]);
	}
	system("pause");
}

struct MyStruct testReturn(){				//�ṹ��ķ���ֵҲ�и�������
	struct MyStruct s1 = { { 1,2,3,4,5,6,7,8,9,10 },10 };
	printf("%p,%p\n", s1.a,s1.a+1);		    //int *
	printf("%p,%p\n", &s1.a,&s1.a+1);		//int (*) 10

	return s1;
};

typedef int *P;
typedef int A[10];      //�ȶ���������ټ�typedef,������������������

//A returnint() {		//error ������������
//
//}

void main2X() {
	struct MyStruct s1 = testReturn();
	for (int i = 0; i < s1.length; i++) {
		printf("%d ", s1.a[i]);
	}
	printf("\n\n\n");

	system("pause");
}

struct info{
	char name[10];
	int age;
};


//struct info infos[3]
//struct info infos[]
//struct info *infos

void changeinfo(struct info *infos) {		//��������Ϊ�����˻�Ϊָ������޸�
	//infos = infos + 3;
	infos[1].age = 88;			//�޸ĵ���ԭ��
}

//��������Ļ�

struct data{
	struct info*p;
	int length;
};

void main3x() {
	struct info infos[3] = { {"fang",18},{"hua",19},{"lin",19} };
	changeinfo(infos);
	for (int i = 0; i < 3; i++) {
		printf("%s,%d\n", infos[i].name, infos[i].age);
	}

	system("pause");
}