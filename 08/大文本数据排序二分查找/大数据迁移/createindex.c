#include "createsort.h"

int init() {

	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));											//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");

	FILE *pf = fopen(sortpath, "rb");												// \r\n -> \n
	if (pf == NULL) {
		return -1;
	}
	else {

		int alllength = 0;

		for (int i = 0; i < N; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);

			allindex.pindex[i] = alllength;											//��λ , ��0��ʼ
			int length = strlen(str);
			alllength += length;
			allindex.pindex[i] = alllength;
		}
		fclose(pf);
	}

	printf("������ȡ\n");

	printf("��ʼд��\n");
	FILE *pfw = fopen(indexpath, "wb");												//д������
	fwrite(allindex.pindex, sizeof(int), allindex.length, pfw);
	fclose(pfw);
	printf("����д��\n");

	free(allindex.pindex);

	printf("��ʼ��ȡ\n");
	FILE *pfr1 = fopen(indexpath, "rb");											//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr1);
	fclose(pfr1);
	printf("������ȡ\n");

	return 0;
}


void quick() {
	printf("�������鿪ʼ����\n");
	allindex.length = N;
	allindex.pindex = calloc(N, sizeof(int));										//�����ڴ�
	printf("����������ɷ���\n");

	printf("��ʼ��ȡ\n");
	FILE *pfr = fopen("index.txt", "rb");											//д������
	fread(allindex.pindex, sizeof(int), allindex.length, pfr);
	fclose(pfr);
	printf("������ȡ\n");

}

