#include<stdio.h>
#include<stdlib.h>

//�ڴ�й©,��һǿ�Ƶ���malloc

struct mem{
	void *p;					//��¼����ĵ�ַ
	int memlength;				//��¼����ĳ���
};

struct MyStruct{
	struct mem*p;				//����һ��ָ������	pp[i] = p;i++;
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