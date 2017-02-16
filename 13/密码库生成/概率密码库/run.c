#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char path[512] = "G:\\BigData.txt";
char pathsortbypass[512] = "G:\\QQpasswordsort.txt";
char pathsortbyci[512] = "G:\\QQpasswordsortci.txt";

#define N 10001296
		//10001295

struct info{
	char str[17];
	int ci;
};

struct info *pall = NULL;

void writetofile() {
	time_t start, end;
	time(&start);

	FILE *pf = fopen(pathsortbyci, "w");

	for (int i = 0; i < N; i++) {
		if (pall[i].ci != 0) {
			char strall[100] = { 0 };
			sprintf(strall, "%d %s", pall[i].ci, pall[i].str);					//打印进去
			fputs(strall, pf);													//写入
		}
	}

	fclose(pf);

	time(&end);
	printf("sort花费%f秒\n", difftime(end, start));
}

int com(void *p1, void *p2) {
	struct info *pinfo1 = p1;
	struct info *pinfo2 = p2;
	if (pinfo1->ci > pinfo2->ci) {
		return -1;
	}
	else if(pinfo1->ci<pinfo2->ci){
		return 1;
	}
	else {
		return 0;
	}
}

void sort() {
	time_t start, end;
	time(&start);

	qsort(pall, N, sizeof(struct info), com);

	time(&end);
	printf("sort花费%f秒\n", difftime(end, start));
}

void init() {
	time_t start, end;
	time(&start);

	pall = calloc(N, sizeof(struct info));					//分配内存
	if (pall == NULL) {
		puts("calloc fail!");
		return;
	}
	FILE *pf = fopen(pathsortbypass, "r");
	for (int i = 0; i < N; i++) {
		char str[50] = { 0 };
		fgets(str, 50, pf);									//读取
		//12----asdfg
		if (*str >= '0'&&*str <= '9') {
			int length = strlen(str);						//1----123456
			if (length >= 11) {
				char *pfind = strstr(str, "----");
				if (*pfind != NULL) {
					*pfind = '\0';
					pall[i].ci = atoi(str);					//获取字符串
					strcpy(pall[i].str, pfind + 4);			//读取
				}
			}
		}
	}


	fclose(pf);
	time(&end);
	printf("文件读取花费%f秒\n", difftime(end, start));

}


int getN(char *patpathsortbypassh) {
	int i = 0;
	FILE *pf = fopen(pathsortbypass, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		while (!feof(pf)) {
			char str[50] = { 0 };
			fgets(str, 50, pf);
			i++;
			//if (*str >= '0'&&*str <= '9') {
			//	int length = strlen(str);						//1----123456
			//	if (length >= 11) {
			//		i++;
			//	}
			//}

		}
		fclose(pf);
		return i;
	}
}


void main() {

	//printf("%d", getN(pathsortbypass));

	init();
	sort();
	writetofile();

	system("pause");
}