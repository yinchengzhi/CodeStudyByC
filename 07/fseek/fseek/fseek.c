

#include<stdio.h>
#include<stdlib.h>


void showp(FILE *p) {
    printf("\n\n");
    printf("\n缓冲区有效数据%d",p->_cnt);
    printf("\n缓冲区指针%p,%c", p->_ptr,*(p->_ptr));
    printf("\n缓冲区开始地址%p", p->_base);
    printf("\n缓冲区的大小%d", p->_bufsiz);
    printf("\n缓冲区的文件描述%d", p->_file);
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

