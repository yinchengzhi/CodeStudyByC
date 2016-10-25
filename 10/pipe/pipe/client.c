#include<stdio.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
char pipename[128] = "yinchengpipe";

void test() {
	HANDLE mutex = OpenMutexA(MUTEX_ALL_ACCESS, TRUE, "yinchengzhiserver");
	if (mutex == NULL) {
		mutex = CreateMutexA(NULL, TRUE, "yinchengzhiserver");

	}
	else {
		MessageBoxA(0, "only one", "only one", 0);
		exit(0);
	}

}


void main() {

	test();


	system("pause");
}