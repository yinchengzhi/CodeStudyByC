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
	else {
		for (int i = 0; i < allN; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);										//读取
			char *tmpstr = convertQQ(str);							//获取QQ号
		}
	}
}

char *convertQQ(char*str) {
	int length = strlen(str);										//获取长度
	char *tmp = malloc(length + 1);
	strcpy(tmp, str);												//拷贝,避免数据自动回收
	char *p = strchr(tmp, '-');
	if (p != NULL) {
		*p = '\0';
	}
	int count = strlen(tmp);										//获取QQ长度，8位
	//1121464690
	if (count < 10) {
		//'0'==48
		for (int i = 10; i >= 0; i--, count--) {					//10	8
			if (count>=0) {											//移动8个
				tmp[i] = tmp[count];
			}
			else {
				//填充0
				tmp[i] = '0';
			}
		}
	}

	return tmp;
}

int isallnum(char *str){											//判断字符串
	while (*str) {
		str++;
		if (*str < '0' || *str>'9') {
			return 0;
		}
		str++;
	}
	return 1;
}