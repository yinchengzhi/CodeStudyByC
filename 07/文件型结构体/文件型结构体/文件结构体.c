
#include<stdio.h>
#include<stdlib.h>

int main() {
	char ch;
	printf("����������Ч������%d\n", stdin->_cnt);
	printf("ָ�򻺳�����ָ��%p\n", stdin->_ptr);
	printf("����������ʼ��ַ%p\n", stdin->_base);
	printf("�������Ĵ�С%d\n", stdin->_bufsiz);
	printf("�ļ���ʶ��%d\n", stdin->_file);

	ch = getchar();
	printf("��ǰ��ȡ���ַ���%c\n", ch);
	printf("����������Ч������%d\n", stdin->_cnt);
	printf("ָ�򻺳�����ָ��%p\n", stdin->_ptr);
	printf("����������ʼ��ַ%p\n", stdin->_base);
	printf("�������Ĵ�С%d\n", stdin->_bufsiz);
	printf("�ļ���ʶ��%d\n", stdin->_file);

	ch = getchar();
	printf("��ǰ��ȡ���ַ���%c\n", ch);
	printf("����������Ч������%d\n", stdin->_cnt);
	printf("ָ�򻺳�����ָ��%p\n", stdin->_ptr);
	printf("����������ʼ��ַ%p\n", stdin->_base);
	printf("�������Ĵ�С%d\n", stdin->_bufsiz);
	printf("�ļ���ʶ��%d\n", stdin->_file);

	ch = getchar();
	printf("��ǰ��ȡ���ַ���%c\n", ch);
	printf("����������Ч������%d\n", stdin->_cnt);
	printf("ָ�򻺳�����ָ��%p\n", stdin->_ptr);
	printf("����������ʼ��ַ%p\n", stdin->_base);
	printf("�������Ĵ�С%d\n", stdin->_bufsiz);
	printf("�ļ���ʶ��%d\n", stdin->_file);

	//fflush(stdin);                                     //��Ч����  ���㣬ָ��ص���ʼ��ַ
	//rewind(stdin);                                     //�ļ��ص���ͷ����Ч�������㣬ָ��ص���ʼ��ַ


	/*
	stdin->_cnt = 0;                                     //��Ч�������㣬������û����Ч���ַ�
	stdin->_ptr = stdin->_base;                          //���ļ���ǰָ��ص��ļ��Ļ���ַ
	*/

	printf("��ǰ��ȡ���ַ���%c\n", ch);
	printf("����������Ч������%d\n", stdin->_cnt);
	printf("ָ�򻺳�����ָ��%p\n", stdin->_ptr);
	printf("����������ʼ��ַ%p\n", stdin->_base);
	printf("�������Ĵ�С%d\n", stdin->_bufsiz);
	printf("�ļ���ʶ��%d\n", stdin->_file);

	system("pause");

}