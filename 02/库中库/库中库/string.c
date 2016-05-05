
#include"string.h"


void setbackground(const char*str) {
	setlocale(LC_ALL, str);
}

void init(void *p, char ch){							//ch = w, ch = a;
	if (ch == 'w') {
		struct StringW *pw = p;							//ָ������ת����ȷ������
		pw->p = NULL;
		pw->memlength = 0;
	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//ָ������ת����ȷ������
		pa->p = NULL;
		pa->memlength = 0;
	}
	else {
		abort();										//�쳣
	}
}

void initwithstring(void *p, char ch,const void *pstr) {
	if (ch == 'w') {
		struct StringW *pw = p;							//ָ������ת����ȷ������
		pw->p = NULL;
		pw->memlength = 0;

		wchar_t *pstrbak = pstr;						//ת��Ϊ���ַ�
		pw->p = malloc(wcslen(pstrbak) + 2);			//�����ڴ棬���ַ�������+1 (wchar_t)
		pw->memlength = wcslen(pstrbak) + 2;			//�ڴ泤��
		wcscpy(pw->p, pstrbak);							//����
		
	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//ָ������ת����ȷ������
		pa->p = NULL;
		pa->memlength = 0;

		char *pstrbak = pstr;							//ת��Ϊխ�ַ�
		pa->p = malloc(strlen(pstrbak) + 1);			//�����ڴ棬���ַ�������+1 (wchar_t)
		pa->memlength = strlen(pstrbak) + 1;			//�ڴ泤��
		strcpy(pa->p, pstrbak);							//����
	}
	else {
		abort();										//�쳣
	}
}

void showstring(const void *p, char ch) {
	if (ch == 'w') {
		struct StringW *pw = p;							//ָ������ת����ȷ������
		if (pw->p != NULL) {
			wprintf(L"%ls\n", pw->p);
		}

	}
	else if (ch == 'a') {
		struct StringA *pa = p;							//ָ������ת����ȷ������
		if (pa->p != NULL) {
			printf("%s\n", pa->p);
		}
	}
	else {
		abort();										//�쳣
	}
}