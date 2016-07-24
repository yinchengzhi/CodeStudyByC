#define _CRT_SECURE_NO_WARNINGS							//强制去掉安全检查

#include<stdio.h>
#include<stdlib.h>

void main() {
	char path[200] = "F:\\yinchengzhi2212\\run";
	char CMD[120];
	sprintf(CMD, "md  \"%s\"",path);

	//md	"路径"

	system(CMD);										//执行指令创建文件夹
	system("pause");
}


//Linux 下的实现


#include<stdio.h>
#include<stdlib.h>

void main() {

	char path[100] = "/home/HP8570P/Desktop/yinchengzhi2212";
	char cmd[120];

	sprintf(cmd, "mkdir \"%s\"", path);
	system(cmd);

}