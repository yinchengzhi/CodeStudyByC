#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//第一种办法，替换为空格
//第二种办法，采用集合的手法
//scanf		//__________
//sscanf
//fscanf


void main() {

	char strall[300] = "123adfdsadfads#45342dfadd6#yinchengzhi01@163.com\n";
	char name[100] = { 0 };
	char pass[100] = { 0 };
	char mail[100] = { 0 };

	//%[0-9A-Za-z]%*[^0-9A-Za-z]	读取一个集合，遇到不是数字或者大小写字母跳出	%*[^0-9A-Za-z]读取所有非数字或者非大小写字母忽略

	//scanf("%s#%s#%s", name, pass, mail);
	sscanf(strall,"%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z@.]%*[^0-9A-Za-z]", name, pass, mail);

	printf("name=%s--pass=%s--mail=%s", name, pass, mail);

	system("pause");
}


