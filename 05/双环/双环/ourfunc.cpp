#include<iostream>
#include<stdio.h>
void simon(int);						//function prototype for simon()
int main3x() {
	using namespace std;
	simon(3);							//call the simon() funcion
	cout << "Pick an integer:";
	int count;
	cin >> count;
	simon(count);						//call it again
	cout << "Done!" << endl;
	system("pause");
	return 0;
}

void simon(int n) {						//define the simon() funcion
	using namespace std;
	cout << "Simon says touch your toes " << n << " times. " << endl;
}