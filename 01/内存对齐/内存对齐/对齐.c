#include<stdio.h>

//����������������Ա
//��Ա��ַ-�׵�ַ�������������ǰ��Ա��С,�ṹ�����
//��������

struct MyStruct{
	char str[23];	//24
	short db;		//4�ֽڣ�2short ����ȡ��̵�Ϊ���
};
struct MyStructX{
	struct MyStruct x;
	char y;					//�ṹ��Ƕ������£���������Ա�������ڵ�ǰ�ṹ�� 
};


void main() {
	printf("%d", sizeof(struct MyStruct));
	system("pause");
}


union MyUnion {
	char str[13];	//13 14
	char db;
};

//�������Ⱦ�������Ǹ������Ǳ������������Ǹ�

void main1() {
	printf("%d", sizeof(union MyUnion));
	system("pause");
}