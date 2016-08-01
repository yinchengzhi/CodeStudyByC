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
}

void main() {

	//int num = getN(path);
	//printf("%d", num);

	int num;
	scanf("%d", &num);
	space(path, num);


	system("pause");
}