#define _CRT_SECURE_NO_WARNINGS							//关闭安全

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\文件批量修改并显示-test";
	char outputpath[100] = "F:\\list.txt";

	remove(outputpath);									//每次新执行 需要删除旧文件

	char CMD[100];

														//格式化字符串指令，查看所有的txt文件
	sprintf(CMD, "dir /b %s\\*.txt > %s",path,outputpath);
	system(CMD);

														//执行指令遍历文件夹，将文件列表输出到一个文件
	char show[50];
	sprintf(show, "type %s", outputpath);				//格式化字符串指令显示文件
	system(show);										//显示文件

	FILE *pf = fopen(outputpath, "r");					//按照读的方式打开list列表文件

	if (pf == NULL) {
		printf("文件打开失败");
		return;
	}

	char filename[128];									//字符串用于保存文件名
	while (fgets(filename, 128, pf)) {					//只要能读取，就一直读取下去，读取失败返回0就终止循环
		char temppath[100];								//保存读取出来文件名的路径
		int length = strlen(filename);					//获取字符串的长度
		filename[length - 1] = '\0';					//最后一个回车符替换为'\0'
		sprintf(temppath, "%s\\%s",path,filename);		//格式化字符串的作用
		printf("\n%s\n", temppath);						//输出路径

		//实现尾部增加	中国男足加油
		{
			FILE *fp = fopen(temppath, "a+");			//追加写入的模式打开
			fputs("\n中国男足加油", fp);					//写入字符串（会在尾部写入）
			fclose(fp);									//关闭文件
		}

		char cmdShow[100];								//显示文件指令的字符串
		sprintf(cmdShow, "type %s", temppath);			//字符串打印
		system(cmdShow);
	}

	fclose(pf);											//关闭文件

	system("pause");
}