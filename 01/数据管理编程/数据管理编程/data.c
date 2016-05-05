#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链接字符串
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

int getnum(char *str) {										//字符串检索
	
	int i = 0;
	for (char *p = strstr(str, "----"); p != NULL;p = strstr(p+4,"----")) {
		i++;
	}
	return i;
}

void initmem() {
	int length = getnum(str);								//获取个数
	myinfos.pinfo = malloc(sizeof(struct info)*length);		//分配内存
	myinfos.length = length;								//标识长度
}

void initdata(char *str) {
	int length = strlen(str);
	for (char *p = str; p < str + length; p++) {
		if (*p ==' ') {										//空格转换\0
			*p ='\0';
		}
	}
	for (char *px = str,ch=0;px<str+length;ch++) {
		//printf("\n%s %d", px,ch);							//当作下标用
		char *pnew = malloc(sizeof(char)*strlen(px) + 1);	//开辟内存
		strcpy(pnew, px);									//保存px的副本
		//521276402\0----hanlei@19940403 \					pnew  pwei+4

		char *pwei = strstr(pnew, "----");
		*pwei = '\0';
		myinfos.pinfo[ch].QQ;

		sscanf(pnew, "%lld", &myinfos.pinfo[ch].QQ);		//扫描字符串到longlong
		sprintf(myinfos.pinfo[ch].password,"%s",pwei+4);	//拷贝密码		

		px += strlen(px)+1;
	}
}

void showalldata() {
	for (int i = 0; i < myinfos.length; i++) {
		printf("\nQQ=%lld,password=%s", myinfos.pinfo[i].QQ, myinfos.pinfo[i].password);
	}
}


void help() {
	printf("\n1.显示数据");
	printf("\n2.删除数据");
	printf("\n3.插入数据");
	printf("\n4.查找数据");
	printf("\n5.查找数据");
	printf("\n6.显示全部数据");
	printf("\n7对于QQ排序");
	printf("\n8.清屏");
	printf("\n9.help\n");
}

void showdatastatic() {
	printf("\n还有%d条数据", myinfos.length);
}

void deletedata() {

}


void main() {
	initmem();
	initdata(str);
	help();
	while (1) {
		char ch = getch();									//getchar()实时获取
		//getchar();										//缓冲回车
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


