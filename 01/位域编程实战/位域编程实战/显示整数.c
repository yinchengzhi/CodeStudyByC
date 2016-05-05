#include<stdio.h>
#include<stdlib.h>

//现代手机，电脑，低位低字节，unix服务器

//按照字节读取二进制
struct bits{
	unsigned char ch1 : 1;	//01
	unsigned char ch2 : 1;
	unsigned char ch3 : 1;
	unsigned char ch4 : 1;
	unsigned char ch5 : 1;
	unsigned char ch6 : 1;
	unsigned char ch7 : 1;
	unsigned char ch8 : 1;
};

void main1() {
	printf("%d\n", sizeof(struct bits));

	int data = -1;
	int length = 4;
	struct bits *p = &data;

	while (length--){
		printf("%d%d%d%d	%d%d%d%d\n",
			((p + length)->ch8),
			((p + length)->ch7),
			((p + length)->ch6),
			((p + length)->ch5),
			((p + length)->ch4),
			((p + length)->ch3),
			((p + length)->ch2),
			((p + length)->ch1)
			);
	}
	system("pause");
}