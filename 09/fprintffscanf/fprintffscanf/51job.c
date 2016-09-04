#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct jobinfo{
	int id;
	char email[50];
	char password[50];

}INFO,*PINFO;																	//INFO结构体,PINFO指针

void main() {
	PINFO p = calloc(2435,sizeof(INFO));										//分配内存

	FILE *pfr = fopen("G:\\BigData.txt", "r");
	FILE *pfw = fopen("C:\\51job.txt", "w");

	for (int i = 0; i < 2435; i++) {
		fscanf(pfr, "%d%s%s", &p[i].id, p[i].email, p[i].password);				//挖掘作用
		//fprintf(stdout, "%d %s %s\n", p[i].id, p[i].email, p[i].password);
		fprintf(pfw, "%d %s \n", p[i].id, p[i].email);
	}

	fclose(pfr);
	fclose(pfw);

	system("C:\\51job.txt");
	system("pause");
}