

#include<stdio.h>
#include<stdlib.h>


void showp(FILE *p) {
    printf("\n\n");
    printf("\n��������Ч����%d",p->_cnt);
    printf("\n������ָ��%p,%c", p->_ptr,*(p->_ptr));
    printf("\n��������ʼ��ַ%p", p->_base);
    printf("\n�������Ĵ�С%d", p->_bufsiz);
    printf("\n���������ļ�����%d", p->_file);
}

int main() {

    char x;
    showp(stdin);
    x = getchar();
    putchar(x);
    showp(stdin);
    x = getchar();
    showp(stdin);
    x = getchar();
    showp(stdin);
    fflush(stdin);
    showp(stdin);


    char path[150] = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.txt";
    FILE *pf = fopen(path, "r");
    while (!feof(pf)) {
        char ch = fgetc(pf);
        showp(pf);
    }

    fclose(pf);


    system("pause");
    return 0;
}

