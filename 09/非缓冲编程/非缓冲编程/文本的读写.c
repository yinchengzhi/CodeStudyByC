#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<fcntl.h>			//�ļ���
#include<sys\stat.h>		//ϵͳ�ײ�

//�������ݰ�ȫ Ҫ���ϸ�
//���̣���꣬�Կ��豸

char path[128] = "G:\\BigDataSort.txt";
char newpath[128] = "G:\\renren.txt";

void main12() {

	int fhdr = _open(path, O_RDONLY);
	int fhdw = _open(newpath, _O_CREAT | O_WRONLY);
	
	if (fhdr == -1 || fhdw == -1) {
		return -1;									//����ʧ��
	}
	else {
		while (!_eof(fhdr)) {
			char str[256] = { 0 };
			int length = _read(fhdr, str, 256);		//��ȡ
			_write(fhdw, str, length);				//д��
		}

		_close(fhdr);								//�ļ������Թر�����
		_close(fhdw);								//
	}

	system("pause");
}

//fgets
void main() {

	int fhdr = _open(path, O_RDONLY);
	int fhdw = _open(newpath, _O_CREAT | O_WRONLY);

	if (fhdr == -1 || fhdw == -1) {
		return -1;									//����ʧ��
	}
	else {
		while (!_eof(fhdr)) {
			char str[1024] = { 0 };
			int length = _read(fhdr, str, 1024);	//��ȡ
			char *p = strstr(str, "����");

			if (p) {
				printf("%s\n", str);
			}
		}

		_close(fhdr);								//�ļ������Թر�����
	}

	system("pause");
}