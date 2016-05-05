#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct MyStruct{
	int id;
	char str[10];
};

void main1(){
	//struct MyStruct my[10];
	//struct MyStruct *p = (struct MyStruct[10]){0};

	//struct MyStruct my[] = { {10,"20"},{10,"20"} };
	//struct MyStruct *p = (struct MyStruct[]){ {10, "20"}, { 10,"20" } };

	//struct MyStruct my[] = { 10,"20",10,"20" };
	//struct MyStruct *p = (struct MyStruct[]){ 10, "20", 10,"20" };

	struct MyStruct my[] = { {0},{0} };

}

struct CSDN {
	char name[100];
	char password[100];
	char email[100];
}csdndata[3]={
	{"zdg","123456","zdg@csdn.com"},
	{"LaoZheng","6734819343910","chengmingzheng@csdn.com"},
	{"fstao","43617386431","524672142@qq.com"}
}, *csdnp;

void main2() {
	csdnp = (struct CSDN[]) {
		{"zdg", "123456", "zdg@csdn.com"},
		{ "LaoZheng","6734819343910","chengmingzheng@csdn.com" },
		{ "fstao","43617386431","524672142@qq.com" }
	};

	for (int i = 0; i < sizeof(csdndata)/sizeof(csdndata[0]); i++) {
		//char *p = strstr(csdndata[i].email, "524672142@qq.com");
		//char *p = strstr((&csdndata[i])->email, "524672142@qq.com");
		//char *p = strstr(csdnp[i].email, "524672142@qq.com");
		//char *p = strstr((csdnp+i)->email, "524672142@qq.com");
		char *p = strstr((*(csdnp + i)).email, "524672142@qq.com");

		if (p != NULL) {
			puts(csdndata[i].password);
		}
	}

	system("pause");
}



