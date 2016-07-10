
#define _CRT_SECURE_NO_WARNINGS					//关闭安全检查

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
   1.读取到内存，然后按照字符串修改，大文件就挂了
   2.新建一个临时文件，挨个读取字符串，然后写入。遇到要删除的，就不写入，
     删除原来的文件，将临时文件重命名，有一个特点，可以处理大文件
*/

void maindel() {

	char path[200] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\文件的增删改查.txt";
	char temppath[200] = { 0 };							//临时文件的路径

	FILE *pf = fopen(path, "rb");						//按照读的方式打开文件
	if (pf == NULL) {
		printf("文件打开失败");
	}
	tmpnam(temppath);									//创建一个临时文件
	FILE *ptemp = fopen(temppath, "wb");					//写入的模式来打开

	if (ptemp == NULL) {
		printf("临时文件创建失败");
	}

	char str[120];
	char findstr[30] = "阳痿患者";

	while (fgets(str, 120, pf)) {						//从原来的文件读取字符串,按行读取，能读就一直读下去
		char *p = strstr(str, findstr);					//字符串查找

		if (p == NULL) {								//没有找到
			fputs(str, ptemp);

		}
		else {
			//找到我们要删除的字符串，不需要写入
		}
	}

	fclose(pf);
	fclose(ptemp);										//关闭文件
	remove(path);										//删除原来的文件
	rename(temppath, path);								//将临时文件命名为原来的文件



	system("pause");
}