
#define _CRT_SECURE_NO_WARNINGS												//ȥ����ȫ���

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main() {

	FILE *ptemp;						//����һ���ļ�ָ��
	char path[100];						//·��������ʱ�ļ���
	tmpnam(path);						//����һ����ʱ�ļ��������浽path

	//һ���ڳ������ڴ��̵ĸ�Ŀ¼

	char *p = path;
	while (*p != '\0') {				//���û�н����ͼ���
		if (*p == '.') {				//�滻�ַ�������
			*p = 'x';
		}
		p++;							//ָ����ǰ�ƶ�
	}

	strcat(path, ".txt");				//���Ϻ�����ַ������ӵ�����


	ptemp = fopen(path, "w+");			//���տɶ���д��·��
	printf("·����%s\n", path);

	if (ptemp == NULL) {
		printf("�ļ���ʧ��!");
	}

	//д���ı�

	fputs("�����������й������ж��. ������ǡ���������߹���¥. ����: ���䲻��", ptemp);
	fputs("�����������й������ж��. ������ǡ���������߹���¥. ����: ���䲻��", ptemp);

	rewind(ptemp);						//�ļ�ָ���ƶ�����ͷ
	char str[512];
	fgets(str, 512, ptemp);				//���ļ���ȡ����
	printf("%s", str);					//����ַ���

	fclose(ptemp);
										//���ܻ���Ҫ�õ�����ʱ�ļ��������ַ�ʽ��д
	system("pause");
}