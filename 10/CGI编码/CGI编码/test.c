#include<stdio.h>

// %D6 %D0 %B9 %FA	4���ֽ�	8 32
// %D6		//1101  13  0110  6    13*16+6 = 214
// %D0		//1101	13  0000  0    13*16 = 208

// -55
// 10	   11    12      13
// 'A' 65  B 66	 C 67    D 68

void main() {

	char strx[7] = "%D6%D0";
	char str[3] = { 0 };
	str[0] = 214;									// 'D' '6'   13*15+6
	str[1] = 208;									// 'D' '0'   13*16+0

	printf("%s", str);


	getchar();
}