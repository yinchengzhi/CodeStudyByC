#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//限定程序 只能打开
#define SIZE 4096
#define MAX_CONNECT 128
int startthreadnum = 10;														//一开始有0个线程存在
char pipename[128] = "\\\\.\\Pipe\\cloudpipeA";

#define path "C:\\xampp\\cgi-bin\\kaifang.txt"
char randpath[1000] = "";
char **g_pp;																	//全局的二级指针
int imax = 15151574;															//标示有多少行

char *pmem = NULL;																//分配内存，容纳字符串

typedef struct info
{
	HANDLE hthread;
	HANDLE hpipe;
	HANDLE hevent;
}PIPE_ST;

PIPE_ST pipeinst[MAX_CONNECT];													//128个结构体

void run() {
	time_t ts;
	srand((unsigned int)time(&ts));
	sprintf(randpath, "C:\\xampp\\cgi-bin\\%.txt", rand());
}

void loadfromfile() {
	g_pp = (char**)malloc(sizeof(char*)*imax);
	memset(g_pp, '\0', sizeof(char*)*imax);

	FILE *pf = fopen(path, "r");												//读文件打开路径
	if (pf == NULL) {
		printf("文件打开失败!");
		return -1;
	}
	else {
		for (int i = 0; i < imax; i++) {
			char str[1024] = { 0 };
			fgets(str, 1024, pf);												//按行读取
			str[1024 - 1] = '\0';
			int strlength = strlen(str);

			g_pp[i] = malloc(sizeof(char)*(strlength + 1));						//处理/0
			if (g_pp[i] != NULL) {
				strcpy(g_pp[i], str);											//拷贝分配的内存
			}
		}

		fclose(pf);
	}
}

DWORD WINAPI serverThread(void *lp) {

	DWORD nread = 0;
	DWORD nwrite = 0;
	DWORD dwbyte = 0;

	char szbuf[SIZE] = { 0 };
	PIPE_ST curpipe = *(PIPE_ST*)lp;											//获取当前结构体
	OVERLAPPED overlap = { 0,0,0,0,curpipe.hevent };							//初始化一个

	while (1) {
		memset(szbuf, 0, sizeof(szbuf));										//数据清理
		ConnectNamedPipe(curpipe.hpipe, &overlap);								//连接上，信息写入overlap
		WaitForSingleObject(curpipe.hevent, INFINITE);							//等待

																				//检测IO,如果完成就跳出
		if (!GetOverlappedResult(curpipe.hpipe, &overlap, &dwbyte, TRUE)) {
			break;
		}

		if (!ReadFile(curpipe.hevent, szbuf, SIZE, &nread, NULL)) {
			puts("read fail");
			break;
		}

		char searchstr[100] = { 0 };
		sscanf(szbuf, "%s", searchstr);											//去读查询

		//路径配置
		char *pmem = malloc(SIZE);
		memset(pmem, 0, SIZE);
		search(searchstr, pmem);
		memset(szbuf, 0, sizeof(szbuf));										//清零

		WriteFile(curpipe.hpipe, pmem, strlen(pmem), &nwrite, NULL);			//写入

		DisconnectNamedPipe(curpipe.hpipe);										//断开
	}
	return 0;
}

void search(char *str,char *psave) {
	if (g_pp != NULL) {
		for (int i = 0; i < imax; i++) {
			if (g_pp[i] != NULL) {
				char *p = strstr(g_pp[i], str);									//找到返回地址，找不到返回null
				if (p != NULL) {
					strcat(psave, g_pp[i]);
					strcat(psave, "<br>");
				}
			}
		}
	}
}

void start() {
	for (int i = 0; i < startthreadnum; i++) {
		pipeinst[i].hpipe = CreateNamedPipeA(
			pipename,															//管道名称
			PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,							//管道读写属性
			PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,					//消息模式，读模式，等待模式阻塞
			10,																	//最大个数
			0,																	//输出缓冲区的大小
			0,																	//输入缓冲区的大小
			1000,																//超时，无限等待
			NULL);

		if (pipeinst[i].hpipe == INVALID_HANDLE_VALUE) {
			printf("\n%d失败", i);
			return;
		}
		//创建事件

		pipeinst[i].hevent = CreateEventA(NULL, FALSE, FALSE, FALSE);
		//创建线程
		pipeinst[i].hthread = CreateThread(NULL, 0, serverThread, &pipeinst[i], 0, NULL);

	}

	printf("server start");
}

void end() {
	for (int i = 0; i < 10; i++) {
		CloseHandle(pipeinst[i].hthread);
		CloseHandle(pipeinst[i].hevent);
		CloseHandle(pipeinst[i].hpipe);
	}
}

void main() {
	loadfromfile();

	//start();
	char *pmem = malloc(SIZE);
	memset(pmem, 0, SIZE);
	search("吴伟", pmem);
	printf("%s", pmem);

	system("pause");
}