#include<stdio.h>
void main(){

	//remove��������ֵΪ0����ôɾ���ɹ�������-1 ��ôɾ�����ɹ�!

	char *FileName = "C:\\Users\\Ollydebug\\Desktop\\CodeCStudy\\07\\1.xlsx";
	int res = remove(FileName);			//ɾ���ļ� ����·��
	if (res == 0) {
		printf("ɾ���ɹ�!");
	}
	else {
		printf("ɾ��ʧ��!");
	}
	printf("%d", res);
	getchar();

}