#pragma once			//������ʱ��ֻ����һ��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define datatype char*

// int *
// struct

struct array{
	datatype *pstart;		//�����׵�ַ
	int length;				//����
	int sortstat;           //�����������  0����1����
};

struct Res{
	datatype **ppstart;		//����ָ������
	int n;
};


void init(struct array *parr);
void initwithdata(struct array *parr,datatype data);
void initwitharray(struct array *parr, datatype *pdata,int datalength);

void show(struct array *parr,void(*pfun)(datatype *pdata));
void showdata(datatype* pdata);
int isequal(datatype *pdata1, datatype *pdata2);							//��ȷ���0�����ȷ��ط�0

void addobject(struct array *parr, datatype data);
void addobjects(struct array *parr, datatype *pdata, int datalength);
datatype *findfirst(struct array *parr,datatype data, int (*pfun)(datatype *pdata1, datatype *pdata2));		//����

struct Res findall(struct array *parr, datatype data);		//����ȫ��

void insertobject(struct array *parr, datatype data, datatype insertdata);		//����λ��������
void insertobjects(struct array *parr, datatype data, datatype *pdata, int datalength);

void deletefirstobject(struct array *parr, datatype data);
void deleteallobject(struct array *parr, datatype data);

void changefirstobject(struct array *parr, datatype data, datatype newdata);
void changeallobject(struct array *parr, datatype data, datatype newdata);


//ʵ�ֶ��̲߳��ң�
//���򣬿��٣�ѡ�񣬲��룬���ֲ��룬�ѣ�ð��   //��������
//��ֵ���ң����ֲ���
//��ʼ��with�ɱ����
//