//#include"string.h"


//void main() {
//	//setlocale(LC_ALL, "zh-CN");
//	setbackground("zh-CN");
//	struct StringA stringa1;
//	struct StringW stringw1;
//	//init(&stringa1,'a');
//	//init(&stringw1,'a');
//	initwithstring(&stringa1, 'a', "calc");
//	initwithstring(&stringw1, 'w', L"notepad����");
//	show(&stringa1, 'a');
//	show(&stringw1, 'w');
//
//	system("pause");
//}

#include"array.h"
//	C���Էֲ���ƣ��ṹ��ʵ��

void main() {

	//��ʼ����һ���ṹ������,ÿһ��Ԫ�ر�ʾ���ַ���,p�������׵�ַ,memlength�ĳ���
	struct StringA stringa[6];
	char *str[6] = { "calc","notepad","pause","12345","pak","haihua"};
	for (int i = 0; i < 6; i++) {
		initwithstring(&stringa[i], 'a', str[i]);
	}

	{
		struct dataarray data;
		initwitharray(&data, "stringa", sizeof(stringa),stringa,4);
		showarray(&data, "stringa");

		//β������
		backaddone(&data, &stringa[5]);
		backaddone(&data, &stringa[4]);
		showarray(&data, "stringa");

	}

	system("pause");
}