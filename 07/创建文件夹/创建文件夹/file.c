#define _CRT_SECURE_NO_WARNINGS							//ǿ��ȥ����ȫ���

#include<stdio.h>
#include<stdlib.h>

void main() {
	char path[200] = "F:\\yinchengzhi2212\\run";
	char CMD[120];
	sprintf(CMD, "md  \"%s\"",path);

	//md	"·��"

	system(CMD);										//ִ��ָ����ļ���
	system("pause");
}


//Linux �µ�ʵ��


#include<stdio.h>
#include<stdlib.h>

void main() {

	char path[100] = "/home/HP8570P/Desktop/yinchengzhi2212";
	char cmd[120];

	sprintf(cmd, "mkdir \"%s\"", path);
	system(cmd);

}