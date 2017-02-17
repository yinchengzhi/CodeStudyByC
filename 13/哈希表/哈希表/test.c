#include<stdio.h>
#include<stdlib.h>


//md5��ϣ,˲���봫,���ݳ���

unsigned int SDBMHash(char *str) {
	unsigned int hash = 0;
	while (*str) {
		//equivalent to:hash = 65599*hash+(*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}
	
	return (hash & 0x7FFFFFFF);
}

void main() {

	printf("%u", SDBMHash("haihua"));
	printf("\n%u", SDBMHash("haihuai"));
	printf("\n%u", SDBMHash("haihuaifang"));


	system("pause");
}