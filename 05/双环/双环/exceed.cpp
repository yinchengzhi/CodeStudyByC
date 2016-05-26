//exceed.cpp -- exceeding some integer limits

#include<iostream>
#define ZERO 0								//makes ZERO symbol for 0 value
#include<climits>							//defines INT_MAX as largest int value
int main1x() {
	using namespace std;
	short sam = SHRT_MAX;					//initialize a varible to max value
	unsigned short sue = sam;				//okay if varible sam already defined

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited. " << endl << "Add $1 to each account." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars desposited.\nPoor Sam!" << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars desposited." << endl;
	cout << "Take $1 from each account." << endl << "Now";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars and sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
	system("pause");
	return 0;
}
