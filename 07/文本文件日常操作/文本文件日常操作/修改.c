
#define _CRT_SECURE_NO_WARNINGS					//�رհ�ȫ���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
   �޸ģ�
   ��һ����ʱ�ļ���������ȡ�ַ�����Ȼ��д�룬����Ҫ�޸ĵľ��滻
   ɾ��ԭ�����ļ�������ʱ�ļ�����������һ���ص㣬���Դ�����ļ�
*/

void mainChange() {
	char path[200] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�ļ�����ɾ�Ĳ�.txt";
	char temppath[200] = { 0 };							//��ʱ�ļ���·��

	FILE *pf = fopen(path, "r");						//���ն��ķ�ʽ���ļ�
	if (pf == NULL) {
		printf("�ļ���ʧ��");
	}
	tmpnam(temppath);									//����һ����ʱ�ļ�
	FILE *ptemp = fopen(temppath, "w");					//д���ģʽ����

	if (ptemp == NULL) {
		printf("��ʱ�ļ�����ʧ��");
	}

	char str[120];
	char findstr[30] = "һȺ��Ů";

	while (fgets(str, 120, pf)) {				//��ԭ�����ļ���ȡ�ַ���,���ж�ȡ���ܶ���һֱ����ȥ
		char *p = strstr(str, findstr);					//�ַ�������

		if (p == NULL) {
			fputs(str, ptemp);

		}
		else {
			//�ҵ�����Ҫ�޸ĵ��ַ�����
			//���޸ĺõ��ַ��������ȥ
			fputs("�����������й������ж��. ������ǡ��ʧ�㸾Ů����¥. ����: ���Ǳ���\n", ptemp);
		}
	}

	fclose(pf);
	fclose(ptemp);										//�ر��ļ�
	remove(path);										//ɾ��ԭ�����ļ�
	rename(temppath, path);								//����ʱ�ļ�����Ϊԭ�����ļ�

	system("C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�ļ�����ɾ�Ĳ�.txt");
	system("pause");
}






