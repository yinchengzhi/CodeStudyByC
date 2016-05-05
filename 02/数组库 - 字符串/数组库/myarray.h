#pragma once			//包含的时候，只包含一次
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define datatype char*

// int *
// struct

struct array{
	datatype *pstart;		//数组首地址
	int length;				//长度
	int sortstat;           //有序或者无序  0无序，1有序
};

struct Res{
	datatype **ppstart;		//创建指针数组
	int n;
};


void init(struct array *parr);
void initwithdata(struct array *parr,datatype data);
void initwitharray(struct array *parr, datatype *pdata,int datalength);

void show(struct array *parr,void(*pfun)(datatype *pdata));
void showdata(datatype* pdata);
int isequal(datatype *pdata1, datatype *pdata2);							//相等返回0，不等返回非0

void addobject(struct array *parr, datatype data);
void addobjects(struct array *parr, datatype *pdata, int datalength);
datatype *findfirst(struct array *parr,datatype data, int (*pfun)(datatype *pdata1, datatype *pdata2));		//查找

struct Res findall(struct array *parr, datatype data);		//查找全部

void insertobject(struct array *parr, datatype data, datatype insertdata);		//根据位置来插入
void insertobjects(struct array *parr, datatype data, datatype *pdata, int datalength);

void deletefirstobject(struct array *parr, datatype data);
void deleteallobject(struct array *parr, datatype data);

void changefirstobject(struct array *parr, datatype data, datatype newdata);
void changeallobject(struct array *parr, datatype data, datatype newdata);


//实现多线程查找，
//排序，快速，选择，插入，二分插入，堆，冒泡   //从左向右
//插值查找，二分查找
//初始化with可变参数
//