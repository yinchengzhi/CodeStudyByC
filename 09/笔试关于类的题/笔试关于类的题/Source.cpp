#include<iostream>

#define MAX_NAME_LEN 20
struct USERINFO
{
	int nAge;
	char szName[MAX_NAME_LEN];
};

void FillUserInfo(USERINFO *parUserInfo)
{
	std::cout << "�������û��ĸ�����";
	int nCount = 0;
	std::cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		std::cout << "����������:";
		std::cin >> parUserInfo[i]->nAge;
		std::string strName;
		std::cout << "����������:";
		std::cin >> strName;
		strcpy(parUserInfo[i].szName, strName.c_str());
	}
}


void main2() {

	USERINFO arUserInfos[100] = { 0 };
	FillUserInfo(arUserInfos);
	printf("The first name is:");
	printf(arUserInfos[0].szName);
	printf("\n");


	system("pause");
}