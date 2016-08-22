#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct csdn{
	char name[22];
	char password[43];
	char email[52];
};

int namemax = -1;
int passmax = -1;
int mailmax = -1;

void init(struct csdn *pdata, char *str) {
	for (char *p = str; *p != '\0'; p++) {
		if (*p == '#') {
			*p = '\0';
		}
	}

	strcpy(pdata->name, str);
	char *pstr1 = str + strlen(str) + 1;
	strcpy(pdata->password, pstr1);
	char *pstr2 = pstr1 + strlen(pstr1) + 1;
	strcpy(pdata->email, pstr2);

	//printf("%s,%s,%s", pdata->name, pdata->password, pdata->email);

}

void getMax(char *str) {
	for (char *p = str; *p != '\0'; p++) {
		if (*p == '#') {
			*p = '\0';
		}
	}
	int max1 = strlen(str);
	if (max1 > namemax) {
		namemax = max1;													//获取姓名的最大长度
	}

	char *pstr1 = str + strlen(str) + 1;
	int max2 = strlen(pstr1);
	if (max2 > passmax) {
		passmax = max2;													//获取密码的最大长度
	}

	char *pstr2 = pstr1 + strlen(pstr1) + 1;
	int max3 = strlen(pstr2);
	if (max3 > mailmax) {
		mailmax = max3;													//获取email的最大长度
	}
}


void readfiletxt() {

	FILE *pfr = fopen("csdn.txt", "r");									//读取大数据CSDN.txt
	FILE *pfw = fopen("csdn.bin", "wb");								//读取大数据CSDN.txt

	if (pfr == NULL) {
		return;
	}
	else {
		while (!feof(pfr)) {
			char str[256] = { 0 };
			fgets(str, 256, pfr);
			struct csdn csdn1;
			init(&csdn1, str);
			fwrite(&csdn1, sizeof(struct csdn), 1, pfw);				//写入
			//getMax(str);
		}
	}


	fclose(pfr);
	fclose(pfw);
}

int getfilesize(char *path) {
	FILE *pf = fopen(path, "rb");
	if (pf==NULL) {
		return -1;
	}
	else {
		fseek(pf, 0, SEEK_END);
		int length = ftell(pf);
		fclose(pf);
		return length;
	}
}

void main() {
	//struct csdn csdn1;
	//char str[100] = "bamyl # 7618595 # bamyl@etang.com";
	//init(&csdn1, str);
	//readfiletxt();
	//printf("%d%d%d", namemax, passmax, mailmax);

	int size = getfilesize("csdn.bin");
	printf("%d\n", size);
	printf("%d\n", size / sizeof(struct csdn));

	FILE *pf = fopen("csdn.bin", "rb+");										//打开csdn大数据bin文件

	while (1) {
		printf("请输入你要读取的第N个元素:");
		int N;
		scanf("%d", &N);
		struct csdn csdn1 = { 0 };
		fseek(pf, sizeof(struct csdn)*(N - 1), SEEK_SET);						//移动到这个位置，SEEK_SET开头
		fread(&csdn1, sizeof(struct csdn), 1, pf);

		printf("%s,%s,%s\n", csdn1.name, csdn1.password, csdn1.email);

	}

	fclose(pf);
	system("pause");
}