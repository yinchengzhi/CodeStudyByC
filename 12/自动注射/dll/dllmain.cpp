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
		//ע�䵽���̵�ʱ��ִ��
	case DLL_THREAD_ATTACH:
		//ע�䵽���̣������߳�������ʱ��
	case DLL_THREAD_DETACH:
		//�߳̽���
	case DLL_PROCESS_DETACH:
		//���̽����Ĳ���
		break;
	}
	return TRUE;
}

