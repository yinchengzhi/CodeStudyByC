#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//�������ݶ�
#pragma data_seg("fangfangdata")
int fang = 0;
#pragma data_seg()

#pragma comment(linker,"/SECTION:fangfangdata,RWS")

void main() {

	if (fang>0) {
		printf("����ֻ������һ��");
		//system("pause");
		MessageBoxA(0, "no", "no", 0);
		return;
	}

	fang++;


	system("pause");
}