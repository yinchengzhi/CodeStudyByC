#define _CRT_SECURE_NO_WARNINGS							//ȥ����ȫ���

#include<stdio.h>
#include<stdlib.h>

//ftell������ȡ�ļ�ָ�뵱ǰλ������ļ����ж��ٸ��ֽ�
//���Ի�ȡ��ǰ�ж��ٸ��ֽ�
//һ������ͳ���ļ��Ĵ�С

void main1() {

	char path[100] = "G:\\MaterialPowerMenu-master.zip";
	FILE *pf = fopen(path, "rb");					//���ն����Ƶķ�ʽ���ж�ȡ�ļ��������ļ�ָ��
	if (pf == NULL) {								//��ʧ��
		printf("�ļ���ʧ��!");
		perror("error");							//��ʾ������Ϣ
	}
	else {
		//��λ�ļ�ָ�뵽β��
		fseek(pf, 0, SEEK_END);						//��λ���ļ���ĩβ��ƫ����Ϊ0
		int length = ftell(pf);						//��ȡ�ļ��ĳ���
		if (length == -1) {
			printf("�����ļ�����ʧ�ܣ�");
		}
		else {
			printf("��ǰ�ļ���%d���ֽ�", length);
		}

		fclose(pf);									//�ر��ļ�
	}

	system("pause");
}


void main2() {

	char path[100] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\ftell.txt";

	//Windows��  ���н���Ϊ�����ַ�/r/n
	//Linux��    ���н���Ϊһ���ַ�
	//Windows��  �ļ�����Ҫ������,Linux���Զ�����һ��������,������ռһ���ֽ�


	FILE *pf = fopen(path, "rb");					//���ն����Ƶķ�ʽ���ж�ȡ�ļ��������ļ�ָ��
	if (pf == NULL) {								//��ʧ��
		printf("�ļ���ʧ��!");
		perror("error");							//��ʾ������Ϣ
	}
	else {
		//��λ�ļ�ָ�뵽β��
		fseek(pf, 0, SEEK_END);						//��λ���ļ���ĩβ��ƫ����Ϊ0
		int length = ftell(pf);						//��ȡ�ļ��ĳ���
		if (length == -1) {
			printf("�����ļ�����ʧ�ܣ�");
		}
		else {
			printf("��ǰ�ļ���%d���ֽ�", length);
		}

		fclose(pf);									//�ر��ļ�
	}

	system("pause");
}



//Linux�µı��

#include<stdio.h>
void main() {

	int length = 0;
	char path[60] = "/home/yincheng/Desktop/1.txt";
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		return;
	}
	else {
		fseek(pf, 0, SEEK_END);
		length = ftell(pf);
		if (length == -1) {
			printf("fail!");
		}
		else {
			printf("length=%d", length);
		}

		fclose(pf);
	}
}