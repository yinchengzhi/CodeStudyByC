
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>			//本地化
#include<string.h>
#include<memory.h>

struct StringA{
	char *p;
	int memlength;			//内存长度
};


struct StringW {
	wchar_t *p;
	int memlength;			//内存长度
};

//内聚

typedef struct StringA stringa;
typedef struct StringW stringw;			//缩写

void setbackground(const char*str);
void init(void *p, char ch);		//ch = w, ch = a;
void initwithstring(void *p, char ch,const void *pstr);
void showstring(const void *p, char ch);
