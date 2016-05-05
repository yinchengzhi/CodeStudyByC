#include"ui.h"
#include"dataarray.h"

struct Dataarray *pdata = NULL;


char uistr[1000] = { " 0.帮助\n \
1.显示所有数据\n \
2.删除所有数据\n \
3.查询\n \
4.修改数据\n \
5.排序\n \
6.清屏\n \
7.删除\n \
8.退出\n \
9.尾部增加\n \
A.插入\n " };


void help() {
	printf("%s", uistr);
}


void uimain() {

	pdata = malloc(sizeof(struct Dataarray));
	initwithstring(pdata, str);
	help();
	while (1) {
		char ch = getch();				//不需要输入回车
		switch (ch)
		{
		case '0':
			help();
			break;
		case '1':
			showall(pdata);
			break;
		case '2':
			deleteall(pdata);			//释放内存
			break;
		case '3':
		{
			printf("\n小伙子选择查询方式\n1.根据QQ查询第一个\n2.根据QQ查询所有\n3.根据密码查询第一个\n4.根据密码查询所有\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				scanf("%lld", &QQ);
				findfirstbyQQ(pdata, QQ);
				break;
			}
			case '2':
			{
				long long QQ;
				scanf("%lld", &QQ);
				findallbyQQ(pdata, QQ);
				break;
			}
			case '3':
			{
				char passstr[100] = { 0 };
				scanf("%s", passstr);
				findfirstbypassword(pdata, passstr);
				break;
			}
			case '4':
			{
				char passstr[100] = { 0 };
				scanf("%s", passstr);
				findallbypassword(pdata, passstr);
				break;
			}
			default:
				break;
			}
			break;
		}
		case '4':
		{
			printf("\n小伙子选择修改方式\n1.根据QQ修改第一个\n2.根据QQ修改所有\n3.根据密码修改第一个\n4.根据密码修改所有\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				char newpassstr[100] = { 0 };
				printf("你想查询的QQ账号是:");
				scanf("%lld", &QQ);
				printf("\n你想把密码改成:");
				scanf("%s", newpassstr);
				struct data newdata;
				newinitdatawithstring(&newdata, newpassstr);
				changefirstbyQQ(pdata, QQ, &newdata);
				break;
			}
			case '2':
			{
				long long QQ;
				char newpassstr[100] = { 0 };
				printf("你想查询的QQ账号是：");
				scanf("%lld", &QQ);
				printf("\n你想把密码改成:\n");
				scanf("%s", newpassstr);
				struct data newdata;
				newinitdatawithstring(&newdata, newpassstr);
				changeallbyQQ(pdata, QQ, &newdata);
				break;
			}
			case '3':
			{
				char passstr[100] = { 0 };
				char newpassstr[100] = { 0 };
				scanf("%s", passstr);
				printf("\n你想把密码改成:\n");
				scanf("%s", newpassstr);
				struct data newdata;
				newinitdatawithstring(&newdata, newpassstr);
				changefirstbypassword(pdata, passstr, &newdata);
				break;
			}
			case '4':
			{
				char passstr[100] = { 0 };
				char newpassstr[100] = { 0 };
				scanf("%s", passstr);
				printf("\n你想把密码改成:\n");
				scanf("%s", newpassstr);
				struct data newdata;
				newinitdatawithstring(&newdata,newpassstr);
				changeallbypassword(pdata, passstr, &newdata);				//查找所有
				break;
			}
			default:
				break;
			}
			break;
		}
		case '5':
		{
			printf("\n1.根据QQ排序\n2.根据密码排序\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				sortbyQQ(pdata);
				break;
			}
			case '2':
			{
				sortbypass(pdata);
				break;
			}
			default:
				break;
			}
			break;
		}
		case '6':
			system("cls");
			break;
		case '7':
		{
			printf("\n小伙子选择删除方式\n1.根据QQ删除第一个\n2.根据QQ删除所有\n3.根据密码删除第一个\n4.根据密码删除所有\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				scanf("%lld", &QQ);
				printf("要删除的%lld\n", QQ);
				deletefirstbyQQ(pdata, QQ);
				break;
			}
			case '2':
			{
				long long QQ;
				scanf("%lld", &QQ);
				printf("要删除的%lld\n", QQ);
				deleteallbyQQ(pdata, QQ);
				break;
			}
			case '3':
			{
				char passstr[100] = { 0 };
				scanf("%s", passstr);
				deletefirstbypassword(pdata, passstr);
				break;
			}
			case '4':
			{
				char passstr[100] = { 0 };
				scanf("%s", passstr);
				deleteallbypassword(pdata, passstr);
				break;
			}
			default:
				break;
			}
			break;
		}
		case '8':
			exit(0);
			break;
		case '9':
		{
			long long QQ;
			char passstr[100] = { 0 };
			printf("请输入你想要尾部插入的QQ账号:");
			scanf("%lld", &QQ);
			printf("请输入你想要尾部插入的QQ密码:");
			scanf("%s", passstr);
			struct data data1;
			initwithstructdata(&data1, QQ, passstr);
			backinsert(pdata, &data1);
			break;
		}
		case 'A':
		{
			printf("\n小伙子选择插入方式\n1.根据QQ插入第一个\n2.根据QQ插入所有\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				printf("你想在哪个QQ账号前插入：");
				scanf("%lld", &QQ);
				long long newQQ;
				char passstr[100] = { 0 };
				printf("请输入你想要尾部插入的QQ账号:");
				scanf("%lld", &newQQ);
				printf("请输入你想要尾部插入的QQ密码:");
				scanf("%s", passstr);
				struct data data1;
				initwithstructdata(&data1, newQQ, passstr);
				insertfirstbyQQ(pdata,QQ,&data1);
				break;
			}
			case '2':
			{
				long long QQ;
				printf("你想在哪个QQ账号前插入：");
				scanf("%lld", &QQ);
				long long newQQ;
				char passstr[100] = { 0 };
				printf("请输入你想要尾部插入的QQ账号:");
				scanf("%lld", &newQQ);
				printf("请输入你想要尾部插入的QQ密码:");
				scanf("%s", passstr);
				struct data data1;
				initwithstructdata(&data1, newQQ, passstr);
				insertallbyQQ(pdata, QQ, &data1);
				break;
			}

			}
			break;
		}
		}
	}
}