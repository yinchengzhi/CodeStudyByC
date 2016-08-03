#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

char *path = "G:\\BigData.txt";
#define N 15186998


int getN(char *path) {
	FILE *pf = fopen(path, "r");

	if (pf == NULL) {
		return -1;
	}
	else {
		int i = 0;

		while (!feof(pf)) {
			char str[256] = { 0 };
			fgets(str, 256, pf);
			i++;
		}
		return i;
		fclose(pf);
	}
}

void space(char *path, int num) {
	char ** pathes = malloc(sizeof(char*)*num);
	for (int i = 0; i < num; i++) {
		pathes[i] = malloc(sizeof(char) * 256);
		sprintf(pathes[i], "G:\\BigData.txt%d", i + 1);
		printf("\n%s", pathes[i]);
	}

	//100 10 10
	//100 9	8*12+4
	FILE *pf = fopen(path, "r");

	if (pf == NULL) {
		return -1;
	}
	else {
		if (N%num == 0) {
			//num个,N/num
			for (int i = 0; i < num; i++) {
				FILE *pfw = fopen(path[i], "w");			//写入
				for (int j = 0; j < N / num; j++) {
					char str[1024] = { 0 };
					fgets(str, 1024, pf);
					fputs(str, pfw);					//读取一行写入一行
				}
				fclose(pfw);
			}
		}
		else {

			//100	9	8*12+4

			for (int i = 0; i < num - 1; i++) {
				FILE *pfw = fopen(path[i], "w");			//写入
				for (int j = 0; j < N / (num - 1); j++) {
					char str[1024] = { 0 };
					fgets(str, 1024, pf);
					fputs(str, pfw);					//读取一行写入一行
				}
				fclose(pfw);
			}

			{
				FILE *pfw = fopen(path[num - 1], "w");			//写入
				for (int j = 0; j < N % (num - 1); j++) {
					char str[1024] = { 0 };
					fgets(str, 1024, pf);
					fputs(str, pfw);					//读取一行写入一行
				}
				fclose(pfw);
			}


		}
		fclose(pf);
	}

}

void merge(char *newpath) {

}


void main() {

	//int num = getN(path);
	//printf("%d", num);

	int num;
	scanf("%d", &num);
	space(path, num);


	system("pause");
}