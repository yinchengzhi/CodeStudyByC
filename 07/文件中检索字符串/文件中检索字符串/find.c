#define  _CRT_SECURE_NO_WARNINGS		//�رհ�ȫ���

/*
���ļ��������ַ���

FIND[/V] [/V] [/N] [/I] ["string" [[drive:][path]filename[...]]

  /V	��ʾ����δ����ָ���ַ�������
  /C	����ʾ�����ַ���������
  /N	��ʾ�к�
  /I	�����ַ���ʱ���Դ�Сд

  "string" ָ��Ҫ���������ִ�
  [drive:][path] filename	ָ��Ҫ�������ļ�

*/

#include<stdio.h>
#include<stdlib.h>

void main() {
	char str[30] = "text";				//Ҫ���ҵ��ַ���
	char path[60] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\FindCMD.html";

	char CMD[150];
	sprintf(CMD, "find /c /n /i \"%s\" \"%s\" ", str, path);

	//��ʽ������ָ��
	system(CMD);			//ִ��ָ��
	system("pause");
}

/*

*/

/*
	grep	-n	"��Ҫ�������ַ���"	"�ļ�·��"
*/

/*  
Linuxд��

#include<stdio.h>
#include<stdlib.h>

void main() {

	char str[50] = "sprintf";
	char path[100] = "/homme/yinchengzhi/����/rm.c";
	char cmd[150];
	sprintf(cmd, "grep -n %s %s", str, path);
	system(cmd);
}

*/