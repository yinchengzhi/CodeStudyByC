#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAILSLOT "\\\\.\\mailslot\\yinchengzhi"

void main() {


	//��һ�����ƣ��ڶ���д�룬����������������Ѿ����ڵ�

	HANDLE hmailslot = CreateFileA(MAILSLOT, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hmailslot == INVALID_HANDLE_VALUE) {
		printf("��ʧ��");
	}

	while (1) {

		system("pause");
		char str[10] = "123456789";
		scanf("%s", str);

		LPBYTE lpmsg = (LPBYTE)str;												//ת����ָ������
		int wok = 0;

		//д����Ϣ����һ��������ڶ���д���ڴ��׵�ַ�����������ȣ����ĸ�д��ɹ�����wok����
		WriteFile(hmailslot, lpmsg, 10, &wok, NULL);

	}

	CloseHandle(hmailslot);											//�ر�
	system("pause");

}