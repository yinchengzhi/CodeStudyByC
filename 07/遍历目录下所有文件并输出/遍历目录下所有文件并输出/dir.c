
//������ǰĿ¼�������ļ��Լ��ļ���, ���������ʱ��

//dir-----Windows
//����/b�Ժ�,�Ϳ��Խ�����ʾ�ļ��������ļ�����
// /a:-d�ų�Ŀ¼
// >C:\\list.txt ����·�������������ı�


//ls-Linux
// ls ������ǰĿ¼
// -l ÿ��ʾһ���ͻ���
// -F��ʾ�ļ���ϸ��Ϣ,	*�����ִ���ļ� /����Ŀ¼
// grep -v [*$,/$]	�ų���ִ���ļ�����Ŀ¼
//	> lastlist.txt		����ı�


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main() {

	char path[100] = "C:\\Users\\Ollydebug\\Pictures";
	char CMD[500];
	//sprintf(CMD, "dir /b /a:-d \"%s\" > F:\\list.txt",path);

	sprintf(CMD, "dir /b /a:-d \"%s\" ", path);

	system(CMD);							//ִ��ָ��

	system("pause");
}


/*
Linux������
*/

#include<stdio.h>
#include<stdlib.h>

void main() {
	char path[100] = "/home/yincheng/����";
	char cmd[200];

	sprintf(cmd, "ls -l -F \"%s\" |grep -v[*$,/$] > lastlist.txt", path);
	system(cmd);
	system("cat lastlist.txt");
}