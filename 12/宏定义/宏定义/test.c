
void showit() {
	printf("代码在%d行\n", __LINE__);
	printf("代码编译时间%s %s\n", __DATE__, __TIME__);
	printf("文件名%s\n", __FILE__);
	printf("函数名%s\n", __FUNCTION__);
}