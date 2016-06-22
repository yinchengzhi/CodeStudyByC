#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(char *str) {

	char *p = str;
	while (*p != '\0') {
		if (*p == '\r' || *p == '\n') {
			*p = '\0';
		}
		p++;
	}

	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		str[i] ^= 3;
	}
}

void main() {

	FILE *pfr = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\datac.txt", "r");
	while (!feof(pfr)) {
		char str[1024] = { 0 };
		fgets(str, 1023, pfr);
		run(str);
		char *p = strstr(str, "562193724");
		//char *p1 = strstr(str, "ÎâÎ°");
		//char *p2 = strstr(str, "ÄÚÃÉ¹Å");
		//if (p1 != NULL && p2 != NULL) {
		//	printf("%s\n", p);
		//}

		if (p != NULL) {
			printf("%s\n", p);
		}
	}

	fclose(pfr);

	system("pause");
}