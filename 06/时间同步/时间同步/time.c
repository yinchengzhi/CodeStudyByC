//#include<stdio.h>
//#include<stdlib.h>
//#include<Windows.h>
//
//void main() {
//
//	HANDLE time1 = CreateWaitableTimerA(NULL, TRUE, "haihua");
//	if (time1 == NULL) {
//		printf("创建失败");
//	}
//
//	LARGE_INTEGER mytime;
//	mytime.QuadPart = -50000000;							//0.1微妙，万分之一毫秒
//
//	if (!SetWaitableTimer(time1,&mytime,0,0,0,0)) {
//		printf("设置失败");
//	}
//
//	if (WaitForSingleObject(time1,INFINITE)==WAIT_OBJECT_0) {
//		printf("wait ok!");
//	}
//	else {
//		printf("wait no!");
//	}
//
//	system("pause");
//}