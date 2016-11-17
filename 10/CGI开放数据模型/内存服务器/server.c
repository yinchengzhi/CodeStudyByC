#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
#define MAX_CONNECT 128
int startthreadnum = 10;														//һ��ʼ��0���̴߳���
char pipename[128] = "\\\\.\\Pipe\\cloudpipe";

#define path "C:\\xampp\\cgi-bin\\kaifang.txt"
char randpath[1000] = "";
char **g_pp;																	//ȫ�ֵĶ���ָ��
int imax = 15151574;															//��ʾ�ж�����

typedef struct info
{
	HANDLE hthread;
	HANDLE hpipe;
	HANDLE hevent;
}PIPE_ST;

PIPE_ST pipeinst[MAX_CONNECT];													//128���ṹ��

void run() {
	time_t ts;
	srand((unsigned int)time(&ts));
	sprintf(randpath, "C:\\xampp\\cgi-bin\\%.txt", rand());
}

DWORD WINAPI serverThread(void *lp) {

	DWORD nread = 0;
	DWORD nwrite = 0;
	DWORD dwbyte = 0;

	char szbuf[SIZE] = { 0 };
	PIPE_ST curpipe = *(PIPE_ST*)lp;											//��ȡ��ǰ�ṹ��
	OVERLAPPED overlap = { 0,0,0,0,curpipe.hevent };							//��ʼ��һ��

	while (1) {
		memset(szbuf, 0, sizeof(szbuf));										//��������
		ConnectNamedPipe(curpipe.hpipe, &overlap);								//�����ϣ���Ϣд��overlap
		WaitForSingleObject(curpipe.hevent, INFINITE);							//�ȴ�

																				//���IO,�����ɾ�����
		if (!GetOverlappedResult(curpipe.hpipe, &overlap, &dwbyte, TRUE)) {
			break;
		}

		if (!ReadFile(curpipe.hevent, szbuf, SIZE, &nread, NULL)) {
			puts("read fail");
			break;
		}

		char searchstr[100] = { 0 };
		sscanf(szbuf, "%s", searchstr);											//ȥ����ѯ

		run();
		//·������
		search(searchstr, randpath);
		memset(szbuf, 0, sizeof(szbuf));										//����
		sprintf(szbuf, "%s", randpath);
		WriteFile(curpipe.hpipe, randpath, strlen(randpath), &nwrite, NULL);	//д��

		DisconnectNamedPipe(curpipe.hpipe);										//�Ͽ�
	}
	return 0;
}

void search(char *str, char *randpath) {
	FILE *pf = fopen(randpath , "w");											//д��ģʽ��
	if (g_pp != NULL) {
		for (int i = 0; i < imax; i++) {
			if (g_pp[i] != NULL) {
				char *p = strstr(g_pp[i], str);									//�ҵ����ص�ַ���Ҳ�������null
				if (p != NULL) {
					puts(g_pp[i]);												//��ӡ
					fputs(g_pp[i], pf);											//������ļ�
				}
			}
		}
	}
	fclose(pf);																	//�ر�
}

void start() {
	for (int i = 0; i < startthreadnum; i++) {
		pipeinst[i].hpipe = CreateNamedPipeA(
			pipename,															//�ܵ�����
			PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,							//�ܵ���д����
			PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,					//��Ϣģʽ����ģʽ���ȴ�ģʽ����
			10,																	//������
			0,																	//����������Ĵ�С
			0,																	//���뻺�����Ĵ�С
			1000,																//��ʱ�����޵ȴ�
			NULL);

		if (pipeinst[i].hpipe == INVALID_HANDLE_VALUE) {
			printf("\n%dʧ��", i);
			return;
		}
		//�����¼�

		pipeinst[i].hevent = CreateEventA(NULL, FALSE, FALSE, FALSE);
		//�����߳�
		pipeinst[i].hthread = CreateThread(NULL, 0, serverThread, &pipeinst[i], 0, NULL);

	}

	printf("server start");
}

void end() {

}

void main() {
	loadfromfile();
	start();

	system("pause");
}