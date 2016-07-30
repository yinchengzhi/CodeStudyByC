/*
   This program's purpose is generate the random and fake QQ Number 
   and QQ Password and write all of it to one txt file.Make it become
   the big data txt file.But,this program need to update,It's have a bug
   when the txt file's size become approximately 427 MB,My program have 
   broken down by immediately.
*/


//Code By yinchengzhi 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>


//QQ账号密码格式如下：
//1319148052----YNU1500621032

//rand()%m  生成一个 0 到 m-1 的随机数


//生成9到12位随机QQ号


char *getRandomQQNumber() {									

	char *QQNumber = (char*)malloc(sizeof(char) * 13);		//动态分配内存——设定13位
	int i, Number;
	int RandomQQLength = rand() % 4 + 9;					//生成随机数9到11，rand()%4生成0-3，两边加上9，生成9到12

	for (i = 0; i < RandomQQLength; i++) {					
		Number = rand() % 10;
		if (i == 0 && Number == 0) {
			continue;
		}
		QQNumber[i] = Number + '0';							//整型的数字转换为字符
	}

	QQNumber[RandomQQLength] = '\0';
	return QQNumber;
}

//生成6到20位随机的QQ密码

char *getRandomQQPass() {						

	char *QQPassWord = (char*)malloc(sizeof(char) * 21);	//动态分配内存——设定20位
	int RandomQQLength = rand() % 15 + 6;					//生成6到19,rand()%15生成0-14，两边加上6，生成6到20
	int i, flag;

	for (i = 0; i < RandomQQLength; i++) {
		flag = rand() % 3;

		switch (flag)
		{
		case 0:
			QQPassWord[i] = 'A' + rand() % 26;
			break;
		case 1:
			QQPassWord[i] = 'a' + rand() % 26;
			break;
		case 2:
			QQPassWord[i] = '0' + rand() % 10;
			
		default:
			QQPassWord[i] = 'x';
			break;
		}
	}

	QQPassWord[RandomQQLength] = '\0';

	return QQPassWord;
}



void main() {

	srand((unsigned)time(NULL));									//随机数种子设置,srand需要放在循环之外。

	char *QQNumber = getRandomQQNumber();							//获得生成的随机QQ号码
	char *QQPassWord = getRandomQQPass();							//获得生成的随机QQ密码

	//for (int i = 0; i < 50; i++) {
	//	QQNumber = getRandomQQNumber();							
	//	QQPassWord = getRandomQQPass();
	//	printf("%s----%s\n", QQNumber, QQPassWord);
	//}


	char path[100] = "G:\\BigData.txt";
	FILE *pf = fopen(path, "rb+");
	if (pf == NULL) {
		printf("文件打开失败!");
		printf("error");
	}
	else {
		//定位文件指针到尾部
		fseek(pf, 0, SEEK_END);						//定位到文件的末尾，偏移量为0
		long long length = ftell(pf);
		if (length == -1) {
			printf("计算文件长度失败!");
		}
		else {
			while (length < 536870912) {			//536870912字节(b)=512兆字节(mb)
				length = ftell(pf);
				QQNumber = getRandomQQNumber();
				QQPassWord = getRandomQQPass();
				fprintf(pf, "%s----%s\r\n", QQNumber, QQPassWord);
			}

			printf("写入完毕!文件长度为%lld",length);
		}
		fclose(pf);
	}
	system("pause");
}