#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//��һ�ְ취���滻Ϊ�ո�
//�ڶ��ְ취�����ü��ϵ��ַ�
//scanf		//__________
//sscanf
//fscanf


void main() {

	char strall[300] = "123adfdsadfads#45342dfadd6#yinchengzhi01@163.com\n";
	char name[100] = { 0 };
	char pass[100] = { 0 };
	char mail[100] = { 0 };

	//%[0-9A-Za-z]%*[^0-9A-Za-z]	��ȡһ�����ϣ������������ֻ��ߴ�Сд��ĸ����	%*[^0-9A-Za-z]��ȡ���з����ֻ��߷Ǵ�Сд��ĸ����

	//scanf("%s#%s#%s", name, pass, mail);
	sscanf(strall,"%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z]%*[^0-9A-Za-z]%[0-9A-Za-z@.]%*[^0-9A-Za-z]", name, pass, mail);

	printf("name=%s--pass=%s--mail=%s", name, pass, mail);

	system("pause");
}


