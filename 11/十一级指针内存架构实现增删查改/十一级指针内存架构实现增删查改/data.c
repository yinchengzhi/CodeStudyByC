#include"data.h"

char *path = "G:\\BigData.txt";
char ***********allP = NULL;

void init() {
	allP = malloc(sizeof(char*) * 10);								//����ָ������
	memset(allP, '\0', sizeof(char*) * 10);							//����
	FILE *pf = fopen(path, "r");

	if (pf==NULL) {
		printf("�ļ���ʧ��");
		return;
	}
	else {
		for (int i = 0; i < allN; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);										//��ȡ
			char *tmpstr = convertQQ(str);							//��ȡQQ��
		}
	}
}

char *convertQQ(char*str) {
	int length = strlen(str);										//��ȡ����
	char *tmp = malloc(length + 1);
	strcpy(tmp, str);												//����,���������Զ�����
	char *p = strchr(tmp, '-');
	if (p != NULL) {
		*p = '\0';
	}
	int count = strlen(tmp);										//��ȡQQ���ȣ�8λ
	//1121464690
	if (count < 10) {
		//'0'==48
		for (int i = 10; i >= 0; i--, count--) {					//10	8
			if (count>=0) {											//�ƶ�8��
				tmp[i] = tmp[count];
			}
			else {
				//���0
				tmp[i] = '0';
			}
		}
	}

	return tmp;
}

int isallnum(char *str){											//�ж��ַ���
	while (*str) {
		str++;
		if (*str < '0' || *str>'9') {
			return 0;
		}
		str++;
	}
	return 1;
}