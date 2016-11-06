#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void main() {

	while(1){
		for (int i = 0; i < 10; i++) {
			ShellExecuteA(NULL, "open", "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\10\\pipe\\Debug\\¿Í»§¶Ë.exe");
			Sleep(100);
		}
	}
}
