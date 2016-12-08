#include"data.h"

char *path = "G:\\Bigdata.txt";
char *sortpath = "G:\\Bigdatasort.txt";

void main() {

	//int num;
	//scanf("%d", &num);

	//char *p = convertQQ("77025077----yincheng");
	//printf("%s", p);

	init();
	//while (1) {
	//	char str[100] = { 0 };
	//	printf("请输入要查找的QQ:%s", str);
	//	scanf("%s", str);
	//	search(str);
	//	puts("search over");
	//}

	while (1) {
		int num;
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			char str[100] = { 0 };
			printf("请输入要查找的QQ", str);
			scanf("%s", str);
			search(str);
			puts("search over");
			break;
		}

		case 2:
		{
			char str[100] = { 0 };
			printf("请输入要删除的QQ", str);
			scanf("%s", str);
			search(str);
			puts("delete over");
			break;
		}

		case 3:
		{
			char str[100] = { 0 };
			printf("请输入要插入的QQ", str);
			scanf("%s", str);

			char str1[100] = { 0 };
			printf("请输入要插入的QQpass", str1);
			scanf("%s", str1);

			insert(str, str1);
			puts("insert over");

			break;
		}
		case 4:
		{
			char str[100] = { 0 };
			printf("请输入要change的QQ", str);
			scanf("%s", str);

			char str1[100] = { 0 };
			printf("请输入要change的QQpass", str1);
			scanf("%s", str1);

			changeit(str, str1);
			puts("change over");
			break;
		}

		default:
			break;
		}
	}

	system("pause");
}

void sorttofile() {

}