#include"init.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct data{
	long long QQ;
	char *pstr;				//ָ��
	unsigned char length;	//255
};



void initwithstructdata(struct data*p,long long QQ,char *pstr);

void showdata(const struct data *p);						//��ʾ��������
void changedata(struct data*p, struct data*newp);			//ǳ����
void changedatadeep(struct data*p,struct data*newp);		//���

void initdatawithstring(struct data *p, char *initstr);
void newinitdatawithstring(struct data *p, char *initstr);