#include<stdio.h>
#define huahuafindWC 10

//	if else,���˱��룬������
//	�������,��ѡ��ı��룬�ó��������С
void main1() {

#if huahuafindWC==1
	printf("��");
#else
	printf("��");

#endif
	getchar();
}

#define isdebug 0

void test() {

#if isdebug 1
	printf("test");							//����״̬,
#endif

}

void main2() {
	test();
	getchar();
}

//'b' ����	's'�Ĵ�,	   'h'����	'a'����
#define huahuaspeak	'b'

void main3() {

#if huahuaspeak=='b'
	puts("���� love you 1314");
#elif huahuaspeak=='h'
	puts("����ϡ����");
#elif huahuaspeak=='a'
	puts("i love you for ever");
#elif huahuaspeak=='s'
	puts("����ϲ���㣬��ϲ���ң������˰���");
#endif

}

//ifdef ���������ִ��ĳһ�Σ�
#define Debug
void main4x() {

#ifdef Debug
	printf("����love fangfang");
#endif 
	getchar();
}


#define fangfangisin

void main() {

#ifndef fangfangisin
	printf("��������˼����");
#endif // !fangfangisin


	getchar();
}