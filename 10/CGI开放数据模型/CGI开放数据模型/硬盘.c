#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char strpath[256] = "kaifang.txt";

char *change(char *str) {
	char *tempstr = malloc(strlen(str) + 1);				//strlen
															//memset(tempstr, 0, sizeof(str) + 1);
	int x = 0, y = 0;
	char assii_1, assii_2;

	while (tempstr[x]) {
		if ((tempstr[x] = str[y]) == '%') {

			//y+1,y+2
			if (str[y + 1] >= 'A') {
				assii_1 = str[y + 1] - 55;
			}
			else {
				assii_1 = str[y + 1] - 48;
			}

			if (str[y + 2] >= 'A') {
				assii_2 = str[y + 2] - 55;
			}
			else {
				assii_2 = str[y + 2] - 48;
			}

			tempstr[x] = assii_1 * 16 + assii_2;
			y += 2;

		}
		x++;
		y++;
	}
	tempstr[x] = '\0';
	return tempstr;
}

void showlist(char str[256]) {
	FILE *pf;												//�ļ�ָ��
	pf = fopen(strpath, "r");								//��ȡ
	if (pf == NULL) {
		printf("�ļ���ʧ��!");
	}
	else {
		//feof(pf)�����ļ�ĩβ����1�����򷵻�0
		while (!feof(pf)) {									//û�е��ļ�ĩβ�ͼ���
			char readstr[1024] = { 0 };
			fgets(readstr, 1024, pf);						//��ȡһ��
			char *p = strstr(readstr, str);					//�ַ�������
			if (p != NULL) {
				puts(readstr);								//��ӡ
				puts("<br>");
				// fputs(readstr,pfw);						//д��
			}
		}
		fclose(pf);
	}

}

void main() {

	printf("Content-type:text/html\n\n");					//����
	
	//system("ipconfig");
	system("mkdir 1");
	char szpost[256] = { 0 };
	gets(szpost);
	printf("%s", szpost);

	char *p1 = strchr(szpost, '&');
	if (p1 != NULL) {
		*p1 = '\0';
	}

	printf("<br>%s", szpost + 5);
	printf("<br>%s", change(szpost + 5));

	char *p2 = strchr(p1 + 1, '&');
	if (p2 != NULL) {
		*p2 = '\0';
	}
	printf("<br>%s", p1 + 6);
	printf("<br>%s", change(p1 + 6));

	showlist(change(szpost + 5));


}