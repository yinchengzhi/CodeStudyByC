#include<stdio.h>
#include<stdlib.h>

//内存泄漏,第一强制调用malloc

struct mem{
	void *p;					//记录分配的地址
	int memlength;				//记录分配的长度
};

struct MyStruct{
	struct mem*p;				//分配一个指针数组	pp[i] = p;i++;
	int i;
};


int i = 0;
void*  mymalloc(size_t _Size) {
	i++;
	void *p = malloc(_Size);
	return p;
}

void myfree(void* _Block) {
	i--;
	free(_Block);
}

void main() {
	void *p1 = mymalloc(14);
	void *p2 = mymalloc(14);
	void *p3 = mymalloc(14);
	void *p4 = mymalloc(14);

	//myfree(p1);
	printf("%d", i);
	system("pause");
}