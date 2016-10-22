
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAILSLOT "\\\\.\\mailslot\\yinchengzhi"


void main() {
	//名称  数量     等待时间  		安全属性
	HANDLE hmailslot = CreateMailslotA(MAILSLOT, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hmailslot == NULL) {
		printf("创建失败");
	}
	else {

		while (1) {
			system("pause");
			DWORD dxNextSize = 0;						//标识下一个的大小
			DWORD dxMsgCount = 0;						//消息数量
			DWORD readCount = 0;						//读取成功的数量


			//GetMailslotInfo(
			//	_In_      HANDLE hMailslot,				//文件名	
			//	_Out_opt_ LPDWORD lpMaxMessageSize,
			//	_Out_opt_ LPDWORD lpNextSize,			//标记下一个字符串长度多少
			//	_Out_opt_ LPDWORD lpMessageCount,		//多少条消息 	
			//	_Out_opt_ LPDWORD lpReadTimeout
			//);

			if (GetMailslotInfo(hmailslot, NULL, &dxNextSize, &dxMsgCount, NULL)) {
				for (int i = 0; i < dxMsgCount; i++) {
					LPBYTE lpbuf = malloc(dxNextSize + 1);		//分配内存

							//读取		//首地址，大小		//读的个数
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