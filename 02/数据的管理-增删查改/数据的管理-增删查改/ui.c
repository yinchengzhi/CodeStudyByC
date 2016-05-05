#include"ui.h"
#include"dataarray.h"

struct Dataarray *pdata = NULL;


char uistr[1000] = { " 0.����\n \
1.��ʾ��������\n \
2.ɾ����������\n \
3.��ѯ\n \
4.�޸�����\n \
5.����\n \
6.����\n \
7.ɾ��\n \
8.�˳�\n \
9.β������\n \
A.����\n " };


void help() {
	printf("%s", uistr);
}


void uimain() {

	pdata = malloc(sizeof(struct Dataarray));
	initwithstring(pdata, str);
	help();
	while (1) {
		char ch = getch();				//����Ҫ����س�
		switch (ch)
		{
		case '0':
			help();
			break;
		case '1':
			showall(pdata);
			break;
		case '2':
			deleteall(pdata);			//�ͷ��ڴ�
			break;
		case '3':
		{
			printf("\nС����ѡ���ѯ��ʽ\n1.����QQ��ѯ��һ��\n2.����QQ��ѯ����\n3.���������ѯ��һ��\n4.���������ѯ����\n");
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
			printf("\nС����ѡ���޸ķ�ʽ\n1.����QQ�޸ĵ�һ��\n2.����QQ�޸�����\n3.���������޸ĵ�һ��\n4.���������޸�����\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				char newpassstr[100] = { 0 };
				printf("�����ѯ��QQ�˺���:");
				scanf("%lld", &QQ);
				printf("\n���������ĳ�:");
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
				printf("�����ѯ��QQ�˺��ǣ�");
				scanf("%lld", &QQ);
				printf("\n���������ĳ�:\n");
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
				printf("\n���������ĳ�:\n");
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
				printf("\n���������ĳ�:\n");
				scanf("%s", newpassstr);
				struct data newdata;
				newinitdatawithstring(&newdata,newpassstr);
				changeallbypassword(pdata, passstr, &newdata);				//��������
				break;
			}
			default:
				break;
			}
			break;
		}
		case '5':
		{
			printf("\n1.����QQ����\n2.������������\n");
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
			printf("\nС����ѡ��ɾ����ʽ\n1.����QQɾ����һ��\n2.����QQɾ������\n3.��������ɾ����һ��\n4.��������ɾ������\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				scanf("%lld", &QQ);
				printf("Ҫɾ����%lld\n", QQ);
				deletefirstbyQQ(pdata, QQ);
				break;
			}
			case '2':
			{
				long long QQ;
				scanf("%lld", &QQ);
				printf("Ҫɾ����%lld\n", QQ);
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
			printf("����������Ҫβ�������QQ�˺�:");
			scanf("%lld", &QQ);
			printf("����������Ҫβ�������QQ����:");
			scanf("%s", passstr);
			struct data data1;
			initwithstructdata(&data1, QQ, passstr);
			backinsert(pdata, &data1);
			break;
		}
		case 'A':
		{
			printf("\nС����ѡ����뷽ʽ\n1.����QQ�����һ��\n2.����QQ��������\n");
			char newch = getchar();
			getchar();
			switch (newch)
			{
			case '1':
			{
				long long QQ;
				printf("�������ĸ�QQ�˺�ǰ���룺");
				scanf("%lld", &QQ);
				long long newQQ;
				char passstr[100] = { 0 };
				printf("����������Ҫβ�������QQ�˺�:");
				scanf("%lld", &newQQ);
				printf("����������Ҫβ�������QQ����:");
				scanf("%s", passstr);
				struct data data1;
				initwithstructdata(&data1, newQQ, passstr);
				insertfirstbyQQ(pdata,QQ,&data1);
				break;
			}
			case '2':
			{
				long long QQ;
				printf("�������ĸ�QQ�˺�ǰ���룺");
				scanf("%lld", &QQ);
				long long newQQ;
				char passstr[100] = { 0 };
				printf("����������Ҫβ�������QQ�˺�:");
				scanf("%lld", &newQQ);
				printf("����������Ҫβ�������QQ����:");
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