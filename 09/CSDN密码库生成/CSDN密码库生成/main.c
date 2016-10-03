#include"list.h"
#include<Windows.h>

PINFO phead = NULL;

int isoktoscanf(char *str) {
	char *p = strstr(str, "#");
	if (p != NULL) {
		if (strstr(p + 1, "#") != NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void eatspace(char *str) {
	int i = 0;
	int j = 0;
	while ((str[i] = str[j++]) != '\0') {				//双指针错位
		if (str[i] != ' ') {
			i++;
		}
	}
}

void fileload() {
	FILE *pf = fopen("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\09\\CSDN密码库生成\\csdn.txt", "r");

	printf("\n开始读取!");

	while (!feof(pf)) {
		char str[100] = { 0 };
		char password[100] = { 0 };

		fgets(str, 100, pf);
		char *p1 = strstr(str, "#");
		char *p2 = strstr(p1 + 1, "#");
		*p1 = '\0';
		*p2 = '\0';
		strcpy(password, p1 + 1);					//拷贝字符串
		eatspace(password);							

		if (isin(phead, password) == 0) {
			phead = addback(phead, password);
		}

	}

	fclose(pf);

	sortByci(phead);
	writetofile(phead, "G:\\ci.txt");

	sortBypass(phead);
	writetofile(phead, "G:\\pass.txt");
}

void main() {

	fileload();
	system("pause");
}

void main1() {

	PINFO phead = NULL;


	char *str[10] = { "123","1234","456","789","2345","123",
		"456","789","1234","123" };

	for (int i = 0; i < 10; i++) {
		if (isin(phead,str[i])==0) {
			phead = addback(phead, str[i]);
		}
	}

	show(phead);

	sortByci(phead);
	printf("\n\n");
	show(phead);

	sortBypass(phead);
	printf("\n\n");
	show(phead);

	writetofile(phead, "C:\\X.txt");
	system("C:\\X.txt");

	system("pause");
}