#define _CRT_SECURE_NO_WARNINGS							//�رհ�ȫ

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\�ļ������޸Ĳ���ʾ-test";
	char outputpath[100] = "F:\\list.txt";

	remove(outputpath);									//ÿ����ִ�� ��Ҫɾ�����ļ�

	char CMD[100];

														//��ʽ���ַ���ָ��鿴���е�txt�ļ�
	sprintf(CMD, "dir /b %s\\*.txt > %s",path,outputpath);
	system(CMD);

														//ִ��ָ������ļ��У����ļ��б������һ���ļ�
	char show[50];
	sprintf(show, "type %s", outputpath);				//��ʽ���ַ���ָ����ʾ�ļ�
	system(show);										//��ʾ�ļ�

	FILE *pf = fopen(outputpath, "r");					//���ն��ķ�ʽ��list�б��ļ�

	if (pf == NULL) {
		printf("�ļ���ʧ��");
		return;
	}

	char filename[128];									//�ַ������ڱ����ļ���
	while (fgets(filename, 128, pf)) {					//ֻҪ�ܶ�ȡ����һֱ��ȡ��ȥ����ȡʧ�ܷ���0����ֹѭ��
		char temppath[100];								//�����ȡ�����ļ�����·��
		int length = strlen(filename);					//��ȡ�ַ����ĳ���
		filename[length - 1] = '\0';					//���һ���س����滻Ϊ'\0'
		sprintf(temppath, "%s\\%s",path,filename);		//��ʽ���ַ���������
		printf("\n%s\n", temppath);						//���·��

		//ʵ��β������	�й��������
		{
			FILE *fp = fopen(temppath, "a+");			//׷��д���ģʽ��
			fputs("\n�й��������", fp);					//д���ַ���������β��д�룩
			fclose(fp);									//�ر��ļ�
		}

		char cmdShow[100];								//��ʾ�ļ�ָ����ַ���
		sprintf(cmdShow, "type %s", temppath);			//�ַ�����ӡ
		system(cmdShow);
	}

	fclose(pf);											//�ر��ļ�

	system("pause");
}