#include"createsort.h"

int initmem() {
	g_pp = calloc(N, sizeof(char *));						    						 //分配指针数组
	FILE *pf = fopen(filepath, "r");
	if (pf == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);							    	   		     			 //读取
			g_pp[i] = calloc(strlen(str) + 1, sizeof(char));
			//eatN(g_pp[i]);
			
			if (g_pp[i] != NULL) {
				//sprintf(g_pp[i], str);					     							  //打印进去
				strcpy(g_pp[i], str);
				eatN(g_pp[i]);
			}

			//printf("%s", g_pp[i]);													 //显示测试
		}
	}

	return 0;
}


int com(void *p1, void *p2) {
	char **pp1 = p1;
	char **pp2 = p2;

	return strcmp(*pp1, *pp2);
}

void sort() {
	qsort(g_pp, N, sizeof(char *), com);
}

void show() {
	printf("\n此时状态:\n");
	for (int i = 0; i < N; i++) {
		printf("\n%s", g_pp[i]);
	}
}

void writetofile() {
	FILE *pf = fopen(sortpath, "w");

	for (int i = 0; i < N; i++) {

		char temp[100] = { 0 };
		//printf("\n%s", temp);
		sprintf(temp, "%s\n", g_pp[i]);									//可能会产生误差
		//printf("\n%s", temp);

		//strcpy(temp, g_pp[i]);
		fputs(temp, pf);
	}

	fclose(pf);
}
