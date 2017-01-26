#include<stdio.h>
#define huahuafindWC 10

//	if else,两端编译，体积变大
//	代码编译,有选择的编译，让程序体积变小
void main1() {

#if huahuafindWC==1
	printf("拉");
#else
	printf("憋");

#endif
	getchar();
}

#define isdebug 0

void test() {

#if isdebug 1
	printf("test");							//调试状态,
#endif

}

void main2() {
	test();
	getchar();
}

//'b' 北京	's'四川,	   'h'菏泽	'a'美帝
#define huahuaspeak	'b'

void main3() {

#if huahuaspeak=='b'
	puts("海华 love you 1314");
#elif huahuaspeak=='h'
	puts("俺很稀罕你");
#elif huahuaspeak=='a'
	puts("i love you for ever");
#elif huahuaspeak=='s'
	puts("老子喜欢你，不喜欢我，你先人板板的");
#endif

}

//ifdef 如果定义了执行某一段，
#define Debug
void main4x() {

#ifdef Debug
	printf("海华love fangfang");
#endif 
	getchar();
}


#define fangfangisin

void main() {

#ifndef fangfangisin
	printf("芳芳，俺思念你");
#endif // !fangfangisin


	getchar();
}