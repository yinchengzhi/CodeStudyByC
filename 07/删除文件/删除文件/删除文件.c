#include<stdio.h>
void main(){

	//remove函数返回值为0，那么删除成功，返回-1 那么删除不成功!

	char *FileName = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.xlsx";
	int res = remove(FileName);			//删除文件 传入路径
	if (res == 0) {
		printf("删除成功!");
	}
	else {
		printf("删除失败!");
	}
	printf("%d", res);
	getchar();

}