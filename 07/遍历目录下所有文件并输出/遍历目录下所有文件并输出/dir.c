
//遍历当前目录下所有文件以及文件夹, 输出日期与时间

//dir-----Windows
//附加/b以后,就可以仅仅显示文件名或者文件夹名
// /a:-d排除目录
// >C:\\list.txt 按照路径将结果输出到文本


//ls-Linux
// ls 遍历当前目录
// -l 每显示一个就换行
// -F显示文件详细信息,	*代表可执行文件 /代表目录
// grep -v [*$,/$]	排除可执行文件还有目录
//	> lastlist.txt		输出文本


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main() {

	char path[100] = "C:\\Users\\Ollydebug\\Pictures";
	char CMD[500];
	//sprintf(CMD, "dir /b /a:-d \"%s\" > F:\\list.txt",path);

	sprintf(CMD, "dir /b /a:-d \"%s\" ", path);

	system(CMD);							//执行指令

	system("pause");
}


/*
Linux环境下
*/

#include<stdio.h>
#include<stdlib.h>

void main() {
	char path[100] = "/home/yincheng/桌面";
	char cmd[200];

	sprintf(cmd, "ls -l -F \"%s\" |grep -v[*$,/$] > lastlist.txt", path);
	system(cmd);
	system("cat lastlist.txt");
}