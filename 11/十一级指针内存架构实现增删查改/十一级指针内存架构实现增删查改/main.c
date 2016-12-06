#include"data.h"

void main() {

	//int num;
	//scanf("%d", &num);

	//char *p = convertQQ("77025077----yincheng");
	//printf("%s", p);

	init();
	while (1) {
		char str[100] = { 0 };
		printf("请输入要查找的QQ:%s", str);
		scanf("%s", str);
		search(str);
		puts("search over");
	}

	system("pause");
}