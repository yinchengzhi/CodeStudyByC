/*
   This program's purpose is generate the random and fake QQ Number 
   and QQ Password and write all of it to one txt file.Make it become
   the big data txt file.But,this program need to update,It's have a bug
   when the txt file's size become approximately 427 MB,My program have 
   broken down by immediately.
*/


//Code By yinchengzhi 

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>


//QQ�˺������ʽ���£�
//1319148052----YNU1500621032

//rand()%m  ����һ�� 0 �� m-1 �������


//����9��12λ���QQ��


char *getRandomQQNumber() {									

	char *QQNumber = (char*)malloc(sizeof(char) * 13);		//��̬�����ڴ桪���趨13λ
	int i, Number;
	int RandomQQLength = rand() % 4 + 9;					//���������9��11��rand()%4����0-3�����߼���9������9��12

	for (i = 0; i < RandomQQLength; i++) {					
		Number = rand() % 10;
		if (i == 0 && Number == 0) {
			continue;
		}
		QQNumber[i] = Number + '0';							//���͵�����ת��Ϊ�ַ�
	}

	QQNumber[RandomQQLength] = '\0';
	return QQNumber;
}

//����6��20λ�����QQ����

char *getRandomQQPass() {						

	char *QQPassWord = (char*)malloc(sizeof(char) * 21);	//��̬�����ڴ桪���趨20λ
	int RandomQQLength = rand() % 15 + 6;					//����6��19,rand()%15����0-14�����߼���6������6��20
	int i, flag;

	for (i = 0; i < RandomQQLength; i++) {
		flag = rand() % 3;

		switch (flag)
		{
		case 0:
			QQPassWord[i] = 'A' + rand() % 26;
			break;
		case 1:
			QQPassWord[i] = 'a' + rand() % 26;
			break;
		case 2:
			QQPassWord[i] = '0' + rand() % 10;
			
		default:
			QQPassWord[i] = 'x';
			break;
		}
	}

	QQPassWord[RandomQQLength] = '\0';

	return QQPassWord;
}



void main() {

	srand((unsigned)time(NULL));									//�������������,srand��Ҫ����ѭ��֮�⡣

	char *QQNumber = getRandomQQNumber();							//������ɵ����QQ����
	char *QQPassWord = getRandomQQPass();							//������ɵ����QQ����

	//for (int i = 0; i < 50; i++) {
	//	QQNumber = getRandomQQNumber();							
	//	QQPassWord = getRandomQQPass();
	//	printf("%s----%s\n", QQNumber, QQPassWord);
	//}


	char path[100] = "G:\\BigData.txt";
	FILE *pf = fopen(path, "rb+");
	if (pf == NULL) {
		printf("�ļ���ʧ��!");
		printf("error");
	}
	else {
		//��λ�ļ�ָ�뵽β��
		fseek(pf, 0, SEEK_END);						//��λ���ļ���ĩβ��ƫ����Ϊ0
		long long length = ftell(pf);
		if (length == -1) {
			printf("�����ļ�����ʧ��!");
		}
		else {
			while (length < 536870912) {			//536870912�ֽ�(b)=512���ֽ�(mb)
				length = ftell(pf);
				QQNumber = getRandomQQNumber();
				QQPassWord = getRandomQQPass();
				fprintf(pf, "%s----%s\r\n", QQNumber, QQPassWord);
			}

			printf("д�����!�ļ�����Ϊ%lld",length);
		}
		fclose(pf);
	}
	system("pause");
}