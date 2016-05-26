//limits.cpp -- some integer limits
#include<iostream>
#include<climits>
int main2x() {
	using namespace std;
	int n_int = INT_MAX;					//initialize n_int to max int value
	short n_short = SHRT_MAX;				//symbols defined in limits.h file
	long n_long = LONG_MAX;					

	//sizeof operator yields size of type or of varible
	cout << "int is " << sizeof(int) << " bytes. " << endl;
	cout << "short is " << sizeof n_short << " bytes. " << endl;
	cout << "long is " << sizeof n_long << " bytes. " << endl;

	cout << "Maxinum values: " << endl;
	cout << "int : " << n_int << endl;
	cout << "short : " << n_short << endl;
	cout << "long : " << n_long << endl;

	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	system("pause");
	return 0;
}