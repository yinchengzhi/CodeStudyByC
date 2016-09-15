#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char path[256] = "G:\\test.txt";

typedef struct haihualove{
	char allstr[1024];
	int id;
	char name[10];
	char sex[3];
	int age;
	int tall;
	char study[10];
	char marry[10];
	char where[10];
	double price;
}H,*PH;

PH ph;

void init() {

	ph = calloc(100, sizeof(H));										//¿ª±Ù¿Õ¼ä

	FILE *pf = fopen(path, "r");

	for (int i = 0; i < 101; i++) {
		if (i >= 1) {
			char str[2048] = { 0 };
			fgets(str, 2048, pf);
			strcpy(ph[i - 1].allstr, str);
			sscanf(str, "%d %s %s %d %d %s %s %s", &ph[i - 1].id, ph[i - 1].name,
				ph[i - 1].sex, &ph[i - 1].age, &ph[i - 1].tall, ph[i - 1].study,
				ph[i - 1].marry, ph[i - 1].where, ph[i - 1].price);
		}
	}

	system("pause");
}

void main() {

	init();

	for (int i = 0; i < 100; i++) {

		if (strcmp(ph[i].marry, "ÒÑ»é") == 0) {

		}

		//if (ph[i].age < 20 && ph[i].tall>165) {
		//	printf("%s", ph[i].allstr);
		//}
	}
	system("pause");
}



void main1() {

	FILE *pf = fopen(path, "r");
	
	while (!feof(pf)){
		char str[2048] = { 0 };
		fgets(str, 2048, pf);
		printf("%s", str);
		printf("\n\n\n\n");
	}

	system("pause");
}