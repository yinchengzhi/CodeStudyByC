#include"array.h"


void initwithnull(struct dataarray *pdataarray, char datatape[10], int elemsize) {

	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;				//��С
	strcpy(pdataarray->datatape, datatape);			//ȷ������
}

//"char"  char

void initwitharray(struct dataarray *pdataarray, char datatape[10], int elemsize, void *parray, int n) {
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;				//��С
	strcpy(pdataarray->datatape, datatape);			//ȷ������

	if (strcmp(pdataarray->datatape, "stringa")==0) {

		stringa *pa = parray;						//ָ������ת��
		pdataarray->elemsize = sizeof(stringa);		//Ԫ�ش�С

		pdataarray->p = malloc(sizeof(stringa)*n);	//�����ڴ�
		memcpy(pdataarray->p, parray, sizeof(stringa)*n);
		pdataarray->length = n;						//��¼����


	}

}

void showarray(struct dataarray *pdataarray, char datatape[10]) {
	
	stringa* pa = pdataarray->p;
	if(strcmp(pdataarray->datatape,"stringa") == 0){
		for (int i = 0; i < pdataarray->length; i++) {

			printf("%s ", pa[i].p);					//��ӡ�ַ���
		}

		printf("\n");

	}
}


void backaddone(struct dataarray *pdataarray,void *parray) {		//����һ��Ԫ�صĵ�ַ

	if (strcmp(pdataarray->datatape, "stringa") == 0) {

		pdataarray->p = realloc(pdataarray->p, sizeof(stringa)*(pdataarray->length + 1));		//��չ����ĳ���
		stringa *pa = pdataarray->p;								//�����׵�ַ
		stringa *palast = parray;									//ת������

		pa[pdataarray->length].p = palast->p;
		pa[pdataarray->length].memlength = palast->memlength;
		pdataarray->length += 1;
	}

}