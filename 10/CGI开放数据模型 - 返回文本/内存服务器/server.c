#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
#define MAX_CONNECT 128
int startthreadnum = 10;														//һ��ʼ��0���̴߳���
char pipename[128] = "\\\\.\\Pipe\\cloudpipeA";

#define path "C:\\xampp\\cgi-bin\\kaifang.txt"
char randpath[1000] = "";
char **g_pp;																	//ȫ�ֵĶ���ָ��
int imax = 15151574;															//��ʾ�ж�����

char *pmem = NULL;																//�����ڴ棬�����ַ���

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

void loadfromfile() {
	g_pp = (char**)malloc(sizeof(char*)*imax);
	memset(g_pp, '\0', sizeof(char*)*imax);

	FILE *pf = fopen(path, "r");												//���ļ���·��
	if (pf == NULL) {
		printf("�ļ���ʧ��!");
		return -1;
	}
	else {
		for (int i = 0; i < imax; i++) {
			char str[1024] = { 0 };
			fgets(str, 1024, pf);												//���ж�ȡ
			str[1024 - 1] = '\0';
			int strlength = strlen(str);

			g_pp[i] = malloc(sizeof(char)*(strlength + 1));						//����/0
			if (g_pp[i] != NULL) {
				strcpy(g_pp[i], str);											//����������ڴ�
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

		//·������
		char *pmem = malloc(SIZE);
		memset(pmem, 0, SIZE);
		search(searchstr, pmem);
		memset(szbuf, 0, sizeof(szbuf));										//����

		WriteFile(curpipe.hpipe, pmem, strlen(pmem), &nwrite, NULL);			//д��

		DisconnectNamedPipe(curpipe.hpipe);										//�Ͽ�
	}
	return 0;
}

void search(char *str,char *psave) {
	if (g_pp != NULL) {
		for (int i = 0; i < imax; i++) {
			if (g_pp[i] != NULL) {
				char *p = strstr(g_pp[i], str);									//�ҵ����ص�ַ���Ҳ�������null
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
	search("��ΰ", pmem);
	printf("%s", pmem);

	system("pause");
}