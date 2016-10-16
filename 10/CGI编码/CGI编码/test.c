#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// %D6 %D0 %B9 %FA	4¸ö×Ö½Ú	8 32
// %D6		//1101  13  0110  6    13*16+6 = 214
// %D0		//1101	13  0000  0    13*16 = 208

// -55
// 10	   11    12      13
// 'A' 65  B 66	 C 67    D 68

void main1() {

	char strx[7] = "%D6%D0";
	char str[3] = { 0 };
	str[0] = 214;									// 'D' '6'   13*15+6
	str[1] = 208;									// 'D' '0'   13*16+0


	str[0] = ('D' - 55) * 16 + '6' - 48;
	str[1] = ('D' - 55) * 16 + '0' - 48;


	printf("%s", str);
	getchar();
}

char *change(char *str) {
	char *tempstr = malloc(strlen(str) + 1);				//strlen
	//memset(tempstr, 0, sizeof(str) + 1);
	int x = 0, y = 0;
	char assii_1, assii_2;

	while (tempstr[x]) {
		if ((tempstr[x] = str[y]) == '%') {

			//y+1,y+2
			if (str[y + 1] >= 'A') {
				assii_1 = str[y + 1] - 55;
			}
			else {
				assii_1 = str[y + 1] - 48;
			}

			if (str[y + 2] >= 'A') {
				assii_2 = str[y + 2] - 55;
			}
			else {
				assii_2 = str[y + 2] - 48;
			}

			tempstr[x] = assii_1 * 16 + assii_2;
			y += 2;

		}
		x++;
		y++;
	}

	tempstr[x] = '\0';

	return tempstr;

}

void main() {
	char str[128] = "%D6%DC%C8%F0%B8%A3";
	printf("%s", change(str));

	system("pause");
}