#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����ַ���
char str[1024] = "521276402----hanlei@19940403 \
286738260----WEIPEI559720 \
501223616----feng66532008 \
851400824----shuidongwo520 \
1340382355----huang.512yang. \
1061817115----fz62wangyong1983 \
347232860----20080811 \
1028181591----7404850554 \
120539543----0.0123456789 \
754229005----460228214 \
819781633----zmt1993826 \
1319148052----YNU1500621032 \
904972448----zhouxiaowen.520 \
750134133----1292857988 \
438905700----320675 \
379644978----7758521tao \
346083956----devl,1017 \
562193724----5361a749 \
286124126----xuqiang1988 \
4008167599----234567 \
937350113----MAWENcxn1020 \
873589635----qqco*1341HUA \
853249795----5385939d ";

struct info{
	long long QQ;
	char password[16];
};

struct infos{
	struct info* pinfo;
	int length;
}myinfos;

int getnum(char *str) {										//�ַ�������
	
	int i = 0;
	for (char *p = strstr(str, "----"); p != NULL;p = strstr(p+4,"----")) {
		i++;
	}
	return i;
}

void initmem() {
	int length = getnum(str);								//��ȡ����
	myinfos.pinfo = malloc(sizeof(struct info)*length);		//�����ڴ�
	myinfos.length = length;								//��ʶ����
}

void initdata(char *str) {
	int length = strlen(str);
	for (char *p = str; p < str + length; p++) {
		if (*p ==' ') {										//�ո�ת��\0
			*p ='\0';
		}
	}
	for (char *px = str,ch=0;px<str+length;ch++) {
		//printf("\n%s %d", px,ch);							//�����±���
		char *pnew = malloc(sizeof(char)*strlen(px) + 1);	//�����ڴ�
		strcpy(pnew, px);									//����px�ĸ���
		//521276402\0----hanlei@19940403 \					pnew  pwei+4

		char *pwei = strstr(pnew, "----");
		*pwei = '\0';
		myinfos.pinfo[ch].QQ;

		sscanf(pnew, "%lld", &myinfos.pinfo[ch].QQ);		//ɨ���ַ�����longlong
		sprintf(myinfos.pinfo[ch].password,"%s",pwei+4);	//��������		

		px += strlen(px)+1;
	}
}

void showalldata() {
	for (int i = 0; i < myinfos.length; i++) {
		printf("\nQQ=%lld,password=%s", myinfos.pinfo[i].QQ, myinfos.pinfo[i].password);
	}
}


void help() {
	printf("\n1.��ʾ����");
	printf("\n2.ɾ������");
	printf("\n3.��������");
	printf("\n4.��������");
	printf("\n5.��������");
	printf("\n6.��ʾȫ������");
	printf("\n7����QQ����");
	printf("\n8.����");
	printf("\n9.help\n");
}

void showdatastatic() {
	printf("\n����%d������", myinfos.length);
}

void deletedata() {

}


void main() {
	initmem();
	initdata(str);
	help();
	while (1) {
		char ch = getch();									//getchar()ʵʱ��ȡ
		//getchar();										//����س�
		putchar(ch);
		switch (ch)
		{
		case '1':
			showdatastatic();
			break;
		case '6':
			showalldata();
			break;
		case '8':
			system("cls");
			break;
		case '9':
			help();
			break;
		default:
			break;
		}
	}

	system("pause");
}


