
#define _CRT_SECURE_NO_WARNINGS					//�رհ�ȫ���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void maincha() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�ļ�����ɾ�Ĳ�.txt";
	FILE *pf = fopen(path, "r");				//���ն��ķ�ʽ���ļ�
	if (pf == NULL) {
		printf("�ļ���ʧ��");
	}
	else {

		//fgets�ķ���ֵΪ0���͵����ļ�ĩλ���ܶ���һֱ����ȥ
		char str[100];
		char findstr[50] = "ɵ��";

		while (fgets(str,100,pf)) {				//���ļ�����ȡ�ַ�������󳤶�Ϊ100

			char *p = strstr(str, findstr);
			if (p != NULL) {
				printf("�ҵ�              %s", str);			//��Ļ����ַ���
			}

			printf("%s", str);					//��Ļ����ַ���
		}

		fclose(pf);

	}


	system("pause");
}