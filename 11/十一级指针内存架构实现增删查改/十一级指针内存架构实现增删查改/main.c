#include"data.h"

char *path = "G:\\Bigdata.txt";
char *sortpath = "G:\\QQhaihuaSort.txt";

void main() {

	//int num;
	//scanf("%d", &num);

	//char *p = convertQQ("77025077----yincheng");
	//printf("%s", p);

	init();
	printf("init over sorttofile start");
	sorttofile();
	printf("\n sorttofile end");

	//while (1) {
	//	char str[100] = { 0 };
	//	printf("������Ҫ���ҵ�QQ:%s", str);
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
			printf("������Ҫ���ҵ�QQ", str);
			scanf("%s", str);
			search(str);
			puts("search over");
			break;
		}

		case 2:
		{
			char str[100] = { 0 };
			printf("������Ҫɾ����QQ", str);
			scanf("%s", str);
			deleteit(str);
			puts("delete over");
			break;
		}

		case 3:
		{
			char str[100] = { 0 };
			printf("������Ҫ�����QQ", str);
			scanf("%s", str);

			char str1[100] = { 0 };
			printf("������Ҫ�����QQpass", str1);
			scanf("%s", str1);

			insert(str, str1);
			puts("insert over");

			break;
		}
		case 4:
		{
			char str[100] = { 0 };
			printf("������Ҫchange��QQ", str);
			scanf("%s", str);

			char str1[100] = { 0 };
			printf("������Ҫchange��QQpass", str1);
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

void memtofile(char **p, int deep, FILE *pf) {

	if (p == NULL) {
		return;
	}
	if (deep == 1) {
		for (int i = 0; i < 10; i++) {
			if (p[i] != NULL) {
				fputs(p[i], pf);										//д��
			}
		}
		
		return;
	}

	for (int i = 0; i < 10; i++) {
		memtofile(p[i], deep - 1, pf);									//�ݹ�д��
	}
}

void sorttofile() {
	FILE*pf = fopen(sortpath, "w");
	memtofile(allP, 10, pf);											//д��


	fclose(pf);


}