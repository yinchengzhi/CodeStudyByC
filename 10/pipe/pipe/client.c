#include<stdio.h>
#include<Windows.h>

//�޶����� ֻ�ܴ�
#define SIZE 4096
char pipename[128] = "yinchengpipe";
HANDLE m_pipe = NULL;							//�ܵ��ľ��

void start() {
	m_pipe = CreateNamedPipeA(pipename,							//�ܵ�����
		PIPE_ACCESS_DUPLEX,										//�ܵ���д����
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,	//��Ϣģʽ����ģʽ���ȴ�ģʽ����
		PIPE_UNLIMITED_INSTANCES,								//������
		SIZE,													//����������Ĵ�С
		SIZE,													//���뻺�����Ĵ�С
		0,														//��ʱ�����޵ȴ�
		NULL);

}

void test() {
	HANDLE mutex = OpenMutexA(MUTEX_ALL_ACCESS, TRUE, "yinchengzhiserver");
	if (mutex == NULL) {
		mutex = CreateMutexA(NULL, TRUE, "yinchengzhiserver");

	}
	else {
		MessageBoxA(0, "only one", "only one", 0);
		exit(0);
	}

}


void main() {

	test();
	start();

	system("pause");
}