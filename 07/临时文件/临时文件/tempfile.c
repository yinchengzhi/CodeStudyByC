
/*
  ��ʱ�ļ�
  �������أ���װ��ʱ��
  �����˾��Զ�ɾ�����ļ�
  
  tmpfile������ʱ�ļ������ر��ļ����߳���رգ��ͻ��Զ�ɾ�������߱������ƶ�дȨ�ޣ�
  һ���ڳ������ڵĴ��̣�ϵͳ�Զ���������һ�㿴����
  ��������ʱ�ļ���-tmpnam
  ��������ʱ�ļ�������Ӻ��
*/


#define _CRT_SECURE_NO_WARNINGS												//ȥ����ȫ���

#include<stdio.h>
#include<stdlib.h>

void main1() {

	FILE *ptemp;
	ptemp = tmpfile();														//������ʱ�ļ��������ļ�ָ��
	if (ptemp == NULL) {													//�ļ�ָ��Ϊ�գ���ζ�Ŵ���ʧ��
		printf("��ʱ�ļ�����ʧ��!");
		return;
	}

	fputs("�����յ���,ѧC����棬һ��С���飬һ��һ����",ptemp);				//����ı�
	rewind(ptemp);															//�ص��ļ���ͷ�����Խ��ж�ȡ
	char str[512];
	fgets(str, 512, ptemp);													//��ȡ�ַ���
	puts(str);
	fclose(ptemp);
	system("pause");
}