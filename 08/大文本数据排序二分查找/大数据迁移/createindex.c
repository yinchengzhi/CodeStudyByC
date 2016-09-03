#include "createsort.h"

int init() {

	printf("索引数组开始分配\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));											//分配内存
	printf("索引数组完成分配\n");

	printf("开始读取\n");

	FILE *pf = fopen(sortpath, "rb");												// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {

		int alllength = 0;

		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);

			allindex.pindex[i] = alllength;											//错位 , 从0开始
			int length = strlen(str);
			alllength += length;
			allindex.pindex[i] = alllength;
		}
		fclose(pf);
	}

	printf("结束读取\n");

	printf("开始写入\n");
	FILE *pfw = fopen(indexpath, "wb");												//写入索引
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("结束写入\n");

	free(allindex.pindex);

	printf("开始读取\n");
	FILE *pfr1 = fopen(indexpath, "rb");											//写入索引
	fread(allindex.pindex, sizeof(int), allindex.length, pfr1);
	fclose(pfr1);
	printf("结束读取\n");

	return 0;
}


void quick() {
	printf("索引数组开始分配\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));										//分配内存
	printf("索引数组完成分配\n");

	printf("开始读取\n");
	FILE *pfr = fopen("index.txt", "rb");											//写入索引
	fread(allindex.pindex, sizeof(int), allindex.length, pfr);
	fclose(pfr);
	printf("结束读取\n");

}

