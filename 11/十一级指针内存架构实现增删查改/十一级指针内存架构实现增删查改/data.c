#include"data.h"

char *path = "G:\\BigData.txt";
char ***********allP = NULL;

void init() {
	allP = malloc(sizeof(char*) * 10);								//����ָ������
	memset(allP, '\0', sizeof(char*) * 10);							//����
	FILE *pf = fopen(path, "r");

	if (pf==NULL) {
		printf("�ļ���ʧ��");
		return;
	}

}