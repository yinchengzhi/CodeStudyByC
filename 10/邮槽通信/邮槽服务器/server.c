
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAILSLOT "\\\\.\\mailslot\\yinchengzhi"


void main() {
	//����  ����     �ȴ�ʱ��  		��ȫ����
	HANDLE hmailslot = CreateMailslotA(MAILSLOT, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hmailslot == NULL) {
		printf("����ʧ��");
	}
	else {

		while (1) {
			system("pause");
			DWORD dxNextSize = 0;						//��ʶ��һ���Ĵ�С
			DWORD dxMsgCount = 0;						//��Ϣ����
			DWORD readCount = 0;						//��ȡ�ɹ�������


			//GetMailslotInfo(
			//	_In_      HANDLE hMailslot,				//�ļ���	
			//	_Out_opt_ LPDWORD lpMaxMessageSize,
			//	_Out_opt_ LPDWORD lpNextSize,			//�����һ���ַ������ȶ���
			//	_Out_opt_ LPDWORD lpMessageCount,		//��������Ϣ 	
			//	_Out_opt_ LPDWORD lpReadTimeout
			//);

			if (GetMailslotInfo(hmailslot, NULL, &dxNextSize, &dxMsgCount, NULL)) {
				for (int i = 0; i < dxMsgCount; i++) {
					LPBYTE lpbuf = malloc(dxNextSize + 1);		//�����ڴ�

							//��ȡ		//�׵�ַ����С		//���ĸ���
					ReadFile(hmailslot, lpbuf, dxNextSize, &readCount, NULL);
					printf("\n%s", lpbuf);
				}
			}
			else {
				printf("error");
			}
		}
	}

	system("pause");

}