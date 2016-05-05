
#include"string.h"


void setbackground(const char*str) {
	setlocale(LC_ALL, str);
}

void init(void *p, char ch){							//ch = w, ch = a;
	if (ch == 'w') {
		struct StringW *pw = p;							//指针类型转换，确定类型
		pw->p = NULL;
		pw->memlength = 0;
	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//指针类型转换，确定类型
		pa->p = NULL;
		pa->memlength = 0;
	}
	else {
		abort();										//异常
	}
}

void initwithstring(void *p, char ch,const void *pstr) {
	if (ch == 'w') {
		struct StringW *pw = p;							//指针类型转换，确定类型
		pw->p = NULL;
		pw->memlength = 0;

		wchar_t *pstrbak = pstr;						//转换为宽字符
		pw->p = malloc(wcslen(pstrbak) + 2);			//分配内存，求字符串长度+1 (wchar_t)
		pw->memlength = wcslen(pstrbak) + 2;			//内存长度
		wcscpy(pw->p, pstrbak);							//拷贝
		
	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//指针类型转换，确定类型
		pa->p = NULL;
		pa->memlength = 0;

		char *pstrbak = pstr;							//转换为窄字符
		pa->p = malloc(strlen(pstrbak) + 1);			//分配内存，求字符串长度+1 (wchar_t)
		pa->memlength = strlen(pstrbak) + 1;			//内存长度
		strcpy(pa->p, pstrbak);							//拷贝
	}
	else {
		abort();										//异常
	}
}

void showstring(const void *p, char ch) {
	if (ch == 'w') {
		struct StringW *pw = p;							//指针类型转换，确定类型
		if (pw->p != NULL) {
			wprintf(L"%ls\n", pw->p);
		}

	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//指针类型转换，确定类型
		if (pa->p != NULL) {
			printf("%s\n", pa->p);
		}
	}
	else {
		abort();										//异常
	}
}