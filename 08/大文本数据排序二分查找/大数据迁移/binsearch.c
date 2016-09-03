
#include "binsearch.h"

void binsearch(char *searchstr) {
	int tou = 0;
	int wei = N - 1;
	int flag = 0;

	while (tou <= wei) {
		int zhong = (tou + wei) / 2;
		char zhongstr[256] = { 0 };
		FILE *pf1 = fopen(indexpath, "rb");
		FILE *pf2 = fopen(sortpath, "rb");

		int indexnum = 0;
		fseek(pf1, zhong * sizeof(int), SEEK_SET);
		fread(&indexnum, sizeof(int), 1, pf1);							//读索引zhong到indexnum

		fseek(pf2, indexnum, SEEK_SET);

		fgets(zhongstr, 128, pf2);										//读取

		fclose(pf1);
		fclose(pf2);

		eatN(zhongstr);
		char pnewzhongstr[256] = { 0 };
		sprintf(pnewzhongstr, zhongstr);
		eatg(pnewzhongstr);												//遇到-就终止

		int res = strcmp(pnewzhongstr, searchstr);						//1,0,-1

		if (res == 0) {
			flag = 1;
			printf("%s", zhongstr);
			break;
		}
		else if (res == 1) {
			wei = zhong - 1;
		}
		else {
			tou = zhong + 1;
		}
	}

	if (flag) {
		printf("\nfind!\n");
	}
	else {
		printf("\n not find!\n");
	}

}