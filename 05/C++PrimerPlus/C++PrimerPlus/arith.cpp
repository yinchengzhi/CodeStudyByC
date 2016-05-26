//arith.cpp	-- some C++ arithmetic

#include<iostream>
int main2() {
	using namespace std;
	float hats, heads;

	cout.setf(ios_base::fixed, ios_base::floatfield);				//fixed-point
	cout << "Enter a numer ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;

	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;
	system("pause");
	return 0;
}