
#include<stdio.h>
#include<stdlib.h>

int main() {
	char ch;
	printf("缓冲区的有效数据是%d\n", stdin->_cnt);
	printf("指向缓冲区的指针%p\n", stdin->_ptr);
	printf("缓冲区的起始地址%p\n", stdin->_base);
	printf("缓冲区的大小%d\n", stdin->_bufsiz);
	printf("文件标识符%d\n", stdin->_file);

	ch = getchar();
	printf("当前获取的字符是%c\n", ch);
	printf("缓冲区的有效数据是%d\n", stdin->_cnt);
	printf("指向缓冲区的指针%p\n", stdin->_ptr);
	printf("缓冲区的起始地址%p\n", stdin->_base);
	printf("缓冲区的大小%d\n", stdin->_bufsiz);
	printf("文件标识符%d\n", stdin->_file);

	ch = getchar();
	printf("当前获取的字符是%c\n", ch);
	printf("缓冲区的有效数据是%d\n", stdin->_cnt);
	printf("指向缓冲区的指针%p\n", stdin->_ptr);
	printf("缓冲区的起始地址%p\n", stdin->_base);
	printf("缓冲区的大小%d\n", stdin->_bufsiz);
	printf("文件标识符%d\n", stdin->_file);

	ch = getchar();
	printf("当前获取的字符是%c\n", ch);
	printf("缓冲区的有效数据是%d\n", stdin->_cnt);
	printf("指向缓冲区的指针%p\n", stdin->_ptr);
	printf("缓冲区的起始地址%p\n", stdin->_base);
	printf("缓冲区的大小%d\n", stdin->_bufsiz);
	printf("文件标识符%d\n", stdin->_file);

	//fflush(stdin);                                     //有效数据  清零，指针回到起始地址
	//rewind(stdin);                                     //文件回到开头，有效数据清零，指针回到起始地址


	/*
	stdin->_cnt = 0;                                     //有效数据清零，缓冲区没有有效的字符
	stdin->_ptr = stdin->_base;                          //让文件当前指针回到文件的基地址
	*/

	printf("当前获取的字符是%c\n", ch);
	printf("缓冲区的有效数据是%d\n", stdin->_cnt);
	printf("指向缓冲区的指针%p\n", stdin->_ptr);
	printf("缓冲区的起始地址%p\n", stdin->_base);
	printf("缓冲区的大小%d\n", stdin->_bufsiz);
	printf("文件标识符%d\n", stdin->_file);

	system("pause");

}