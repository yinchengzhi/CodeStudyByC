#define  _CRT_SECURE_NO_WARNINGS

#include<Windows.h>
#include<string.h>
#include<stdio.h>

char dllpath[1024] = { 0 };

void inject(DWORD dwprocessid) {
	if (dwprocessid == 0) {
		printf("���̱����Ч");
		return;
	}

	//�ԷǶ�ռ�ķ�ʽ���������
	HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwprocessid);
	if (hprocess == NULL) {
		printf("���̴���Ч");
		return;
	}

	int length = strlen(dllpath) + 1;
	//�����ڴ棬�����������ڲ�,���Զ�д
	LPVOID lpremotedlname = VirtualAllocEx(hprocess, NULL, length, MEM_COMMIT, PAGE_READWRITE);

	if (lpremotedlname == NULL) {
		printf("���̷����ڴ�ʧ��");
		return;
	}

	//��·��д�뵽��������
	if (WriteProcessMemory(hprocess, lpremotedlname, dllpath, length, NULL) == FALSE) {
		printf("�ڴ�д����Ч");
		return;
	}

	HMODULE hmodule = GetModuleHandleA("kernel32.dll");														//��ȡϵͳ��dll�ӿ�
	LPTHREAD_START_ROUTINE fnstart = (LPTHREAD_START_ROUTINE)GetProcAddress(hmodule, "LoadLibraryA");		//��ȡ�����ӿ�

	if (fnstart == 0) {
		printf("��ȡ��ַʧ��");
		return;
	}

	//����һ��Զ���߳�
	HANDLE hremoteThread = CreateRemoteThread(hprocess, NULL, 0, fnstart, dllpath, 0, NULL);

	if (hremoteThread == NULL) {
		printf("�����߳�ʧ��");
		return;
	}

	//�ȴ�
	if (WaitForSingleObject(hremoteThread, INFINITE) != WAIT_OBJECT_0) {
		printf("�̵߳ȴ�ʧ��");
		return;
	}

	CloseHandle(hremoteThread);
	CloseHandle(hmodule);
	CloseHandle(hprocess);

}

void main() {
	
	//��ȡ��ǰ·��
	GetCurrentDirectoryA(1024, dllpath);
	strcat(dllpath, "\\dll.dll");							//����

	DWORD dwprocessid = 5776;								//���ݽ���idע��

	inject(dwprocessid);

	system("pause");
}