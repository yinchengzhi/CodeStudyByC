#include<list>
#include<stdio.h>
#include<stdlib.h>
using namespace std;					//ʹ�������ռ�
void main1() {
	
	list<int> mylist;					//�趨Ԫ��Ϊint����
	list<list<list<int>>> mylist1;
	for (int i = 0; i < 10; i++) {
		mylist.push_back(i);
	}
	for (auto i : mylist) {				//����һ��STL
		printf("%d", i);
	}

	system("pause");
}