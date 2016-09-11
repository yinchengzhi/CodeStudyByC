#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//第一种办法，替换为空格
//第二种办法，采用集合的手法
//scanf		//__________
//sscanf
//fscanf


void main1() {

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


void main2() {
	//int *p1[4];
	//int a = 1, b = 2, c = 3, d = 4;
	//p1[0] = &a;
	//p1[1] = &b;
	//p1[2] = &c;
	//p1[3] = &d;

	//for (int i = 0; i < 4; i++) {
	//	printf("%d\n", *(p1[i]));
	//}

	int(*p2)[4];
	int a[4] = { 0,1,2,3 };
	p2 = &a;

	for (int i = 0; i < 4; i++) {
		printf("%d\n", *(*(p2)+i));
	}


	//int *func(void);
	//int(*func)(void);

	system("pause");
}

void main() {
	FILE *pf = fopen("G:\\test.txt", "r");
	
	for (int i = 0; i < 100; i++) {
		char name[100] = { 0 };
		char pass[100] = { 0 };
		char mail[100] = { 0 };
		//fscanf(pf, "%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z@.]%*[^0-9A-Za-z]", name, pass, mail);
		char allstr[500] = { 0 };
		fgets(allstr, 500, pf);
		sscanf(allstr, "%[0-9A-Za-z_]%*[# ]%[0-9A-Za-z_]%*[# ]%[0-9A-Za-z@._]%*[# ]", name, pass, mail);
		printf("%s %s %s\n", name, pass, mail);


		//zdg # 12344321 # adg@csdn.net
	}



	fclose(pf);
	system("pause");
}