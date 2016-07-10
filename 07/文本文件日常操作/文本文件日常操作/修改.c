
#define _CRT_SECURE_NO_WARNINGS					//关闭安全检查

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
   修改：
   建一个临时文件，挨个读取字符串，然后写入，遇到要修改的就替换
   删除原来的文件，将临时文件重命名，有一个特点，可以处理大文件
*/

void mainChange() {
	char path[200] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\文件的增删改查.txt";
	char temppath[200] = { 0 };							//临时文件的路径

	FILE *pf = fopen(path, "r");						//按照读的方式打开文件
	if (pf == NULL) {
		printf("文件打开失败");
	}
	tmpnam(temppath);									//创建一个临时文件
	FILE *ptemp = fopen(temppath, "w");					//写入的模式来打开

	if (ptemp == NULL) {
		printf("临时文件创建失败");
	}

	char str[120];
	char findstr[30] = "一群妓女";

	while (fgets(str, 120, pf)) {				//从原来的文件读取字符串,按行读取，能读就一直读下去
		char *p = strstr(str, findstr);					//字符串查找

		if (p == NULL) {
			fputs(str, ptemp);

		}
		else {
			//找到我们要修改的字符串，
			//把修改好的字符串填充上去
			fputs("上联：二问中国男足有多愁. 下联：恰似失足妇女守青楼. 横联: 总是被射\n", ptemp);
		}
	}

	fclose(pf);
	fclose(ptemp);										//关闭文件
	remove(path);										//删除原来的文件
	rename(temppath, path);								//将临时文件命名为原来的文件

	system("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\文件的增删改查.txt");
	system("pause");
}






