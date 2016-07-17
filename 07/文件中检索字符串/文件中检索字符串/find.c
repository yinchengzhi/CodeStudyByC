#define  _CRT_SECURE_NO_WARNINGS		//关闭安全检查

/*
在文件中搜索字符串

FIND[/V] [/V] [/N] [/I] ["string" [[drive:][path]filename[...]]

  /V	显示所有未包含指定字符串的行
  /C	仅显示包含字符串的行数
  /N	显示行号
  /I	搜索字符串时忽略大小写

  "string" 指定要搜索的文字串
  [drive:][path] filename	指定要搜索的文件

*/

#include<stdio.h>
#include<stdlib.h>

void main() {
	char str[30] = "text";				//要查找的字符串
	char path[60] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\FindCMD.html";

	char CMD[150];
	sprintf(CMD, "find /c /n /i \"%s\" \"%s\" ", str, path);

	//格式化搜索指令
	system(CMD);			//执行指令
	system("pause");
}

/*

*/

/*
	grep	-n	"需要检索的字符串"	"文件路径"
*/

/*  
Linux写法

#include<stdio.h>
#include<stdlib.h>

void main() {

	char str[50] = "sprintf";
	char path[100] = "/homme/yinchengzhi/桌面/rm.c";
	char cmd[150];
	sprintf(cmd, "grep -n %s %s", str, path);
	system(cmd);
}

*/