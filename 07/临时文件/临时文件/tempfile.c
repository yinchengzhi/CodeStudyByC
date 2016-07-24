
/*
  临时文件
  例如下载，安装的时候
  用完了就自动删除的文件
  
  tmpfile产生临时文件，（关闭文件或者程序关闭，就会自动删除），具备二进制读写权限，
  一般在程序所在的磁盘，系统自动管理，所以一般看不到
  产生的临时文件名-tmpnam
  产生的临时文件名并添加后戳
*/


#define _CRT_SECURE_NO_WARNINGS												//去掉安全检查

#include<stdio.h>
#include<stdlib.h>

void main1() {

	FILE *ptemp;
	ptemp = tmpfile();														//创建临时文件，返回文件指针
	if (ptemp == NULL) {													//文件指针为空，意味着创建失败
		printf("临时文件创建失败!");
		return;
	}

	fputs("锄禾日当午,学C真好玩，一本小破书，一看一下午",ptemp);				//输出文本
	rewind(ptemp);															//回到文件开头，可以进行读取
	char str[512];
	fgets(str, 512, ptemp);													//获取字符串
	puts(str);
	fclose(ptemp);
	system("pause");
}