#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

char path[1024] = "C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q.exe";

//C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q1.exe
//C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q2.exe
//C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q3.exe

int getfilesize(char *path) {
	FILE *pf = fopen(path, "rb");
	if (pf == NULL) {
		return -1;
	}
	else {
		fseek(pf, 0, SEEK_END);
		int size = ftell(pf);								//��ȡ��ǰָ������ļ���ͷ�ĳ���
		fclose(pf);											//��ȡ�ļ���С
		return size;
	}
}


void space(char *path,int n) {

	char **pathes;
	pathes = malloc(sizeof(char*)*n);						//����ָ������
	for (int i = 0; i < n; i++) {
		pathes[i] = malloc(sizeof(char) * 1024);
		sprintf(pathes[i], "C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q%d.exe", i + 1);
		//printf("\n%s", pathes[i]);						//��ʾ·��
	}

	FILE *pf = fopen(path, "rb");
	if (pf == NULL) {
		return;
	}
	else {
		int size = getfilesize(path);							//��ȡ�ļ�
		//100	10	10
		//100	8	100/7	14*7+2=100
		if (size%n == 0) {
			for (int i = 0; i < n; i++) {
				FILE *pfw = fopen(pathes[i], "wb");		
				for (int j = 0; j < size / n; j++) {
					fputc(fgetc(pf),pfw);					//��ȡһ���ַ�Ȼ��д��
				}
				fclose(pfw);
			}
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				FILE *pfw = fopen(pathes[i], "wb");
				for (int j = 0; j < size/(n - 1); j++) {
					fputc(fgetc(pf), pfw);					//��ȡһ���ַ�Ȼ��д��
				}
				fclose(pfw);
			}

			{
				FILE *pfw = fopen(pathes[n - 1], "wb");
				for (int i = 0; i < size%n; i++) {
					fputc(fgetc(pf), pfw);					//��ȡһ���ַ�Ȼ��д��
				}
				fclose(pfw);
			}
		}
		fclose(pf);
	}
}

void merge(char *newpath, int n) {
	char **pathes;
	pathes = malloc(sizeof(char*)*n);						//����ָ������
	for (int i = 0; i < n; i++) {
		pathes[i] = malloc(sizeof(char) * 1024);
		sprintf(pathes[i], "C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\Q%d.exe", i + 1);
		//printf("\n%s", pathes[i]);						//��ʾ·��
	}

	FILE *pfw = fopen(newpath, "wb");
	for (int i = 0; i < n; i++) {
		int length = getfilesize(pathes[i]);
		if (length == -1) {
			return;
		}
		else {
			FILE *pfr = fopen(pathes[i], "rb");
			for (int j = 0; j < length; j++) {
				fputc(fgetc(pfr), pfw);						//д��
			}
			fclose(pfr);
		}
	}
	fclose(pfw);
}


void main() {

	int num;
	scanf("%d", &num);									//�ָ�Ϊnum��
	space(path, num);
	merge("C:\\Users\\Ollydebug\\Desktop\\test1\\�и���ϲ�\\MMM.exe", num);
	system("pause");
}