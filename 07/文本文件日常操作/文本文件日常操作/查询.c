
#define _CRT_SECURE_NO_WARNINGS					//关闭安全检查

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maincha() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\文件的增删改查.txt";
	FILE *pf = fopen(path, "r");				//按照读的方式打开文件
	if (pf == NULL) {
		printf("文件打开失败");
	}
	else {

		//fgets的返回值为0，就到了文件末位，能读就一直读下去
		char str[100];
		char findstr[50] = "傻比";

		while (fgets(str,100,pf)) {				//从文件流读取字符串，最大长度为100

			char *p = strstr(str, findstr);
			if (p != NULL) {
				printf("找到              %s", str);			//屏幕输出字符串
			}

			printf("%s", str);					//屏幕输出字符串
		}

		fclose(pf);

	}


	system("pause");
}