// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

_declspec(dllexport) void autoadd() {
	int *p = (int*)0x4f57c18;
	*p = 5048;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		autoadd();
		//注射到进程的时候执行
	case DLL_THREAD_ATTACH:
		//注射到进程，当作线程启动的时候
	case DLL_THREAD_DETACH:
		//线程结束
	case DLL_PROCESS_DETACH:
		//进程结束的操作
		break;
	}
	return TRUE;
}

