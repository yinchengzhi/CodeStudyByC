
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>			//���ػ�
#include<string.h>
#include<memory.h>

struct StringA{
	char *p;
	int memlength;			//�ڴ泤��
};


struct StringW {
	wchar_t *p;
	int memlength;			//�ڴ泤��
};

//�ھ�

typedef struct StringA stringa;
typedef struct StringW stringw;			//��д

void setbackground(const char*str);
void init(void *p, char ch);		//ch = w, ch = a;
void initwithstring(void *p, char ch,const void *pstr);
void showstring(const void *p, char ch);
