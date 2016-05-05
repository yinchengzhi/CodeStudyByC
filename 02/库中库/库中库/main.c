//#include"string.h"


//void main() {
//	//setlocale(LC_ALL, "zh-CN");
//	setbackground("zh-CN");
//	struct StringA stringa1;
//	struct StringW stringw1;
//	//init(&stringa1,'a');
//	//init(&stringw1,'a');
//	initwithstring(&stringa1, 'a', "calc");
//	initwithstring(&stringw1, 'w', L"notepad海华");
//	show(&stringa1, 'a');
//	show(&stringw1, 'w');
//
//	system("pause");
//}

#include"array.h"
//	C语言分层设计，结构体实现

void main() {

	//初始化了一个结构体数组,每一个元素表示了字符串,p代表了首地址,memlength的长度
	struct StringA stringa[6];
	char *str[6] = { "calc","notepad","pause","12345","pak","haihua"};
	for (int i = 0; i < 6; i++) {
		initwithstring(&stringa[i], 'a', str[i]);
	}

	{
		struct dataarray data;
		initwitharray(&data, "stringa", sizeof(stringa),stringa,4);
		showarray(&data, "stringa");

		//尾部插入
		backaddone(&data, &stringa[5]);
		backaddone(&data, &stringa[4]);
		showarray(&data, "stringa");

	}

	system("pause");
}