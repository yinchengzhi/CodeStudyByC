#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//fgetc fputc fgets fputs fgetwc fputwc fgetws fputws fread fwrite //���������

void main1() {
	FILE *pf = fopen("G:\\5555.txt", "w");

	fputs("Hello Google", pf);						//û��ʵʱ��д��

	system("pause");
	fclose(pf);
}


void main() {
	FILE *pf = fopen("G:\\6.txt", "w+");			//w ģʽ����д
	fputs("Hello Google", pf);						//û��ʵʱ��д�� û����Ч
	
	fflush(pf);										//fclose,fflush ������ ��Ч
	//rewind(pf);
	
	int ch = fgetc(pf);
	if (ch == EOF) {								// EOF �������쳣
		if (feof(pf)) {
			printf("end");
			clearerr(pf);							//�����ļ���״̬,�ļ�ָ�벻��ǰ��
		}

		if (ferror(pf)) {
			printf("ferror");
			clearerr(pf);							//ferror�����ļ���״̬
		}
	}

	//ch = fgetc(pf);
	//putchar(ch);		

	//if (ferror(pf)) {
	//	printf("ferror");
	//}


	printf("\n");

	while (!feof(pf)) {
		ch = fgetc(pf);
		putchar(ch);
	}

	fclose(pf);

	system("pause");
}