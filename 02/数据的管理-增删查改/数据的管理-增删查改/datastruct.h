#include"init.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct data{
	long long QQ;
	char *pstr;				//指针
	unsigned char length;	//255
};



void initwithstructdata(struct data*p,long long QQ,char *pstr);

void showdata(const struct data *p);						//显示单个数据
void changedata(struct data*p, struct data*newp);			//浅拷贝
void changedatadeep(struct data*p,struct data*newp);		//深拷贝

void initdatawithstring(struct data *p, char *initstr);
void newinitdatawithstring(struct data *p, char *initstr);