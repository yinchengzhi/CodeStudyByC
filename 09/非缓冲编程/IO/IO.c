#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>			//�ļ���
#include<sys\stat.h>		//ϵͳ�ײ�

//�������ݰ�ȫ Ҫ���ϸ�
//���̣���꣬�Կ��豸

void main1() {

	char str[256] = { 0 };
	scanf("%s", str);

	int fhd = _open("G:\\mem.txt", O_WRONLY | O_CREAT);				//O_CREATE O_WRONLY
	if (fhd == -1) {
		printf("�򲻿�");
	}
	else {
		_write(fhd, str, sizeof(str));								//������Ч
		_close(fhd);												//�ر��ļ�
	}

	system("pause");
}

void main2() {

	char str[256] = { 0 };
	int fhd = _open("G:\\mem.txt", O_RDONLY | O_TEXT);

	if (fhd == -1) {
		printf("�򲻿�");
	}
	else {
		_read(fhd, str, 256);
		puts(str);
		_close(fhd);												//�ر��ļ�
	}

	system("pause");
}