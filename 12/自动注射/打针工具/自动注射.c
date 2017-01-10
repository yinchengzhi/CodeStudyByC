#define  _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<string.h>
#include<stdio.h>

char dllpath[1024] = { 0 };

void inject(DWORD dwprocessid) {
	if (dwprocessid == 0) {
		printf("进程编号无效");
		return;
	}

	//以非独占的方式打开这个进程
	HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwprocessid);
	if (hprocess == NULL) {
		printf("进程打开无效");
		return;
	}

	int length = strlen(dllpath) + 1;
	//分配内存，在其他进程内部,可以读写
	LPVOID lpremotedlname = VirtualAllocEx(hprocess, NULL, length, MEM_COMMIT, PAGE_READWRITE);

	if (lpremotedlname == NULL) {
		printf("进程分配内存失败");
		return;
	}

	//将路径写入到其他进程
	if (WriteProcessMemory(hprocess, lpremotedlname, dllpath, length, NULL) == FALSE) {
		printf("内存写入无效");
		return;
	}

	HMODULE hmodule = GetModuleHandleA("kernel32.dll");														//获取系统的dll接口
	LPTHREAD_START_ROUTINE fnstart = (LPTHREAD_START_ROUTINE)GetProcAddress(hmodule, "LoadLibraryA");		//获取函数接口

	if (fnstart == 0) {
		printf("获取地址失败");
		return;
	}

	//开启一个远程线程
	HANDLE hremoteThread = CreateRemoteThread(hprocess, NULL, 0, fnstart, dllpath, 0, NULL);

	if (hremoteThread == NULL) {
		printf("开启线程失败");
		return;
	}

	//等待
	if (WaitForSingleObject(hremoteThread, INFINITE) != WAIT_OBJECT_0) {
		printf("线程等待失败");
		return;
	}

	CloseHandle(hremoteThread);
	CloseHandle(hmodule);
	CloseHandle(hprocess);

}

void main() {
	
	//获取当前路径
	GetCurrentDirectoryA(1024, dllpath);
	strcat(dllpath, "\\dll.dll");							//链接

	DWORD dwprocessid = 5776;								//根据进程id注射

	inject(dwprocessid);

	system("pause");
}