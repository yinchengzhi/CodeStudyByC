#include<list>
#include<stdio.h>
#include<stdlib.h>
using namespace std;					//使用命名空间
void main1() {
	
	list<int> mylist;					//设定元素为int类型
	list<list<list<int>>> mylist1;
	for (int i = 0; i < 10; i++) {
		mylist.push_back(i);
	}
	for (auto i : mylist) {				//遍历一个STL
		printf("%d", i);
	}

	system("pause");
}