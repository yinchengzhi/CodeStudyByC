#include"data.h"

char *path = "G:\\BigData.txt";
char ***********allP = NULL;

void init() {
	allP = malloc(sizeof(char*) * 10);								//非陪指针数组
	memset(allP, '\0', sizeof(char*) * 10);							//清零
	FILE *pf = fopen(path, "r");

	if (pf==NULL) {
		printf("文件打开失败");
		return;
	}

}