#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *path = "C:\\Users\\Ollydebug\\Desktop\\test1\\�²�����.txt";
char *pathjia = "C:\\Users\\Ollydebug\\Desktop\\test1\\�²�����jia.txt";
char *pathjie = "C:\\Users\\Ollydebug\\Desktop\\test1\\�²�����jie.txt";


//�ı��ļ�		��ȡ	    \r\n -->  \n   д��	\n->\r\n				//��ȡ�ļ������ƵĴ�С�������϶���rb
//�����Ƶķ�ʽ				 -->\r\n
//��ȡ�ļ���С,�����϶���rb�����һ��Ҫ��r,����ַ�����\n.��Ҫ����++
//int ch = fgetc(pf).	�����ַ������,���
//�ı��ļ����ܣ����е��ַ���һ���ܷ�ʽ�����Զ�д�ı����м��ܣ�
//�ı��ļ�����������ܣ��������ı�.	��ȡ	    \r\n -->  \n   д��	\n->\r\n


int getfilesize(char *path) {
	FILE *pf = fopen(path, "rb");									//��ȡ�ļ������ƵĴ�С�������϶���rb
	if (pf == NULL) {
		return -1;
	}
	else {
		//fseek(pf, 0, SEEK_END);									//�ļ�ָ���ƶ���ĩβ
		//int length = ftell(pf);
		int length = 0;						
		
		//fgetc�������س�
		int ch;
		while ((ch = fgetc(pf))!=EOF) {								//-1 ,'-','1'
			//if (ch == '\n') {
			//	puts("�س�");
			//}
			//putchar(ch);
			length++;
		}

		fclose(pf);

		return length;
	}
}

void tbw() {
	FILE *pf = fopen("d:\\1.txt","wb");
	for (int i = 0; i < 5; i++) {
		fputc('A', pf);
	}
	fclose(pf);
}

void tbr() {
	FILE *pf = fopen("d:\\1.txt", "rb");
	char ch;
	while ((ch = fgetc(pf))!=EOF) {
		printf("\n%d", ch);
	}
	fclose(pf);
}


//�ı�����
void runjiajie(char *path,char *newpath) {
	FILE *pfr = fopen(path, "r");
	FILE *pfw = fopen(newpath, "w");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {
		int ch;		//������������쳣
		//-1	char ch^3	
		//100	��char�������洢���ܻ������������Ե���ʧ��
		//99
		while ((ch = fgetc(pfr)) != EOF) {
			fputc(ch ^ 3, pfw);									// ��A��	\n --> \r\n
		}

		fclose(pfr);
		fclose(pfw);

	}
}


void runjiajiewithpassword(char *path, char *newpath,char *password) {
	FILE *pfr = fopen(path, "rb");
	FILE *pfw = fopen(newpath, "wb");

	if (pfr == NULL || pfw == NULL) {
		return;
	}
	else {

		//110	15	7*15+5

		int alllength = getfilesize(path);						//���峤��
		int passlength = strlen(password);						//���볤��

		printf("\n%d,%d", alllength, passlength);

		for (int i = 0; i < alllength / passlength; i++) {
			for (int k = 0; k < passlength; k++) {
				int ch = fgetc(pfr);
				fputc(ch^password[k], pfw);
			}
		}

		for (int j = 0; j < alllength%passlength; j++) {
			int ch = fgetc(pfr);
			fputc(ch^password[j], pfw);
		}

		fclose(pfr);
		fclose(pfw);

	}
}



int getfilesizet(char *path) {
	FILE *pf = fopen(path, "rb");									//��ȡ�ļ������ƵĴ�С�������϶���rb
	if (pf == NULL) {
		return -1;
	}
	else {
		//fseek(pf, 0, SEEK_END);									//�ļ�ָ���ƶ���ĩβ
		//int length = ftell(pf);
		int length = 0;

		//fgetc�������س�
		char ch;
		while ((ch = fgetc(pf)) != EOF) {								//-1 ,'-','1'
			if (ch == '\n') {
				puts("�س�");
			}
			putchar(ch);
			length++;
		}

		fclose(pf);

		return length;
	}
}


void main() {


	//printf("%d,%d\n", '\r', '\n');

	//tbw();
	//tbr();
	//printf("%d", getfilesize(path));

	runjiajiewithpassword(path, pathjia,"wuwei");
	runjiajiewithpassword(pathjia, pathjie,"wuwei");


	system("pause");
}