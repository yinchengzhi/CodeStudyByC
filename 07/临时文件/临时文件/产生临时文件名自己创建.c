
#define _CRT_SECURE_NO_WARNINGS												//去掉安全检查

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	FILE *ptemp;						//创建一个文件指针
	char path[100];						//路径保存临时文件名
	tmpnam(path);						//生成一个临时文件名，保存到path

	//一般在程序所在磁盘的根目录

	char *p = path;
	while (*p != '\0') {				//如果没有结束就继续
		if (*p == '.') {				//替换字符的作用
			*p = 'x';
		}
		p++;							//指针向前移动
	}

	strcat(path, ".txt");				//加上后戳，字符串链接的作用


	ptemp = fopen(path, "w+");			//按照可读可写打开路径
	printf("路径是%s\n", path);

	if (ptemp == NULL) {
		printf("文件打开失败!");
	}

	//写入文本

	fputs("上联：三问中国男足有多愁. 下联：恰似阳痿患者逛青楼. 横联: 欲射不能", ptemp);
	fputs("上联：三问中国男足有多愁. 下联：恰似阳痿患者逛青楼. 横联: 欲射不能", ptemp);

	rewind(ptemp);						//文件指针移动到开头
	char str[512];
	fgets(str, 512, ptemp);				//从文件读取内容
	printf("%s", str);					//输出字符串

	fclose(ptemp);
										//可能还需要用到的临时文件，用这种方式读写
	system("pause");
}