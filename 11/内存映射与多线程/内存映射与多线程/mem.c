#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

//有限的内存之下怎么干活
//索引载入内存，多线程
//索引映射为内存

char path[256] = "G:\\BigData.txt";
char indexpath[256] = "G:\\QQindex8848.txt";

#define N 18175317

struct {
	char *pfilestart;
	char *pfileend;
	char *pindexfilestart;
	char *pindexfileend;
}infoall = { 0 };																//保存映射的两个文件，头地址，尾地址

//映射文件，文件是独家享有
void map1() {
	HANDLE hfile = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//打开一个文件
	
	if (hfile == INVALID_HANDLE_VALUE) {
		printf("打开文件失败");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//获取文件大小
	
	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//读写
		0,
		GetFileSize(hfile, NULL) + 1,											//大小
		NULL);

	if (hmap == NULL) {
		printf("映射失败");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//创建一个指针，存储映射以后的首地址
	if (pvfile == NULL) {
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("映射成功");
	char *pstart = pvfile;														//首地址
	char *pend = pstart + GetFileSize(hfile, NULL);								//结束地址

	infoall.pfileend = pend;													//保存地址
	infoall.pfilestart = pstart;					

}

void map2() {
	HANDLE hfile = CreateFileA(indexpath, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);						//打开一个文件

	if (hfile == INVALID_HANDLE_VALUE) {
		printf("打开文件失败");
		system("pause");
	}

	printf("\n%d", GetFileSize(hfile, NULL));									//获取文件大小

	HANDLE hmap = CreateFileMappingA(hfile, NULL, PAGE_READWRITE | SEC_COMMIT,	//读写
		0,
		GetFileSize(hfile, NULL) + 1,											//大小
		NULL);

	if (hmap == NULL) {
		printf("映射失败");
		CloseHandle(hfile);
		system("pause");
	}

	PVOID pvfile = MapViewOfFile(hmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	//创建一个指针，存储映射以后的首地址
	if (pvfile == NULL) {
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(hmap);
		system("pause");
	}

	puts("映射成功");
	char *pstart = pvfile;														//首地址
	char *pend = pstart + GetFileSize(hfile, NULL);								//结束地址

	infoall.pindexfileend = pend;										    	//保存地址
	infoall.pindexfilestart = pstart;
}

//读取索引到内存
struct index{
	int *pindex;																//地址
	int length;	
}allindex = { 0 };

void readmem() {
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));

	FILE *pfw = fopen(indexpath, "rb");
	fread(allindex.pindex, sizeof(int), N, pfw);
	fclose(pfw);
}



//  0 1 2 3 9
struct info {
	int *pstart;			//索引的首地址
	int length;				//长度
	int id;					//编号
	char findstr[20];		//查找的字符串
};

void run(void *p) {
	struct info *pi = p;
	for (int i = 0; i < pi->length - 1; i++) {								//限定

		char *start = infoall.pfilestart + pi->pstart[i];					//起始地址
		char *end = infoall.pfilestart + pi->pstart[i + 1];					//结束地址

		char *str = calloc(500, 1);											//分配内存用于拷贝字符串，文件整块，没有\0,有\n
		if (str != NULL) {													//分配成功
			strncpy(str, start, pi->pstart[i + 1] - pi->pstart[i]);			//拷贝字符串
			if (str != NULL) {
				char *ps = strstr(str, pi->findstr);						//检索
				if (ps != NULL) {
					printf("%s", str);
				}
			}

		}
		free(str);															//释放
	}
}

void test1() {
	printf("please input");
	char str[100];
	scanf("%s", str);
#define nthread 100
	struct info pthread[nthread] = { 0 };
	HANDLE hd[nthread] = { 0 };												//线程参数,线程句柄
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			pthread[i].length = N / nthread;
			pthread[i].pstart = allindex.pindex + i*(N / nthread);
			strcpy(pthread[i].findstr, str);
			_beginthread(run, 0, &pthread[i]);
		}
	}
	else {
		for (int i = 0; i < nthread - 1; i++) {
			pthread[i].id = i;
			pthread[i].length = N / (nthread - 1);
			pthread[i].pstart = allindex.pindex + i*(N / (nthread - 1));
			strcpy(pthread[i].findstr, str);
			_beginthread(run, 0, &pthread[i]);
		}

		int i = nthread - 1;
		pthread[i].id = i;
		pthread[i].length = N % (nthread - 1);
		pthread[i].pstart = allindex.pindex + i*(N / (nthread - 1));
		strcpy(pthread[i].findstr, str);
		_beginthread(run, 0, &pthread[i]);

	}

	WaitForMultipleObjects(nthread, hd, TRUE, INFINITE);

	system("pause");
}



//  0 1 2 3 9
struct minfo {
	int *pstart;
	int length;
	int id;
	char findstr[20];
};

void mrun(void *p) {
	struct minfo *pi = p;
	for (int i = 0; i < pi->length - 1; i++) {
		char *start = infoall.pfilestart + pi->pstart[i];					//起始地址
		char *end = infoall.pfilestart + pi->pstart[i + 1];					//结束地址
		char *str = calloc(500, 1);											//分配内存用于拷贝字符串
		if (str != NULL) {													//分配成功
			strncpy(str, start, pi->pstart[i + 1] - pi->pstart[i]);			//拷贝字符串
			if (str != NULL) {
				char *ps = strstr(str, pi->findstr);
				if (ps != NULL) {
					printf("%s", str);
				}
			}

		}
		free(str);															//释放
	}
}

void test2() {
	printf("please input");
	char str[100];
	scanf("%s", str);
#define nthread 100
	struct minfo pthread[nthread] = { 0 };
	HANDLE hd[nthread] = { 0 };												//线程参数,线程句柄
	if (N%nthread == 0) {
		for (int i = 0; i < nthread; i++) {
			pthread[i].id = i;
			pthread[i].length = N / nthread;
			pthread[i].pstart = infoall.pindexfilestart + i*(N / nthread);
			strcpy(pthread[i].findstr, str);
			_beginthread(mrun, 0, &pthread[i]);
		}
	}
	else {
		for (int i = 0; i < nthread - 1; i++) {
			pthread[i].id = i;
			pthread[i].length = N / (nthread - 1);
			pthread[i].pstart = (int*)allindex.pindex + i*(N / (nthread - 1));
			strcpy(pthread[i].findstr, str);
			_beginthread(mrun, 0, &pthread[i]);
		}

		int i = nthread - 1;
		pthread[i].id = i;
		pthread[i].length = N % (nthread - 1);
		pthread[i].pstart = (int*)allindex.pindex + i*(N / (nthread - 1));
		strcpy(pthread[i].findstr, str);
		_beginthread(mrun, 0, &pthread[i]);

	}

	WaitForMultipleObjects(nthread, hd, TRUE, INFINITE);

	system("pause");
}




void main() {

	readmem();
	map1();																//一旦被映射，文件被锁定
	map2();
	test1();
	//test2();

	getchar();

}