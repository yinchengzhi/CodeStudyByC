#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<fcntl.h>			//�ļ���
#include<sys\stat.h>		//ϵͳ�ײ�

//�������ݰ�ȫ Ҫ���ϸ�
//���̣���꣬�Կ��豸

struct info {
	char name[100];
	double db;

};

void main1x() {

	struct info infos[8] = { {"zengbin1",9876.5 },{"zengbin2",8876.5 },
	{"zengbinreal",1888876.5 },{"zengbin4",1876.5 },{ "zengbin5",2876.5 } ,{ "zengbinchangesex",8888876.5 }
	,{ "zengbin7",4876.5 },{ "zengbin38",38876.5 } };

	int fhdw = _open("G:\\zen.bin", O_CREAT | O_BINARY | O_WRONLY);
	if (fhdw == -1) {
		return;
	}
	else {
		_write(fhdw, infos, sizeof(infos));
		_close(fhdw);
	}


	//printf("\n%d", sizeof(struct info));



	system("pause");
}

void main2x() {

	struct info infos[8] = { 0 };
	int fhdr = _open("G:\\zen.bin", O_BINARY | O_RDONLY);

	if (fhdr == -1) {
		return;
	}
	else {
		_read(fhdr, infos, sizeof(infos));
		_close(fhdr);
	}

	for (int i = 0; i < 8; i++) {
		printf("�������� %s ���޼۸� %f\n", infos[i].name, infos[i].db);
	}

	system("pause");
}


void main() {

	struct info info1 = { 0 };
	int fhdr = _open("G:\\zen.bin", O_BINARY | O_RDONLY);

	if (fhdr == -1) {
		return;
	}
	else {

		while (1) {
			int num;
			scanf("%d", &num);
			_lseek(fhdr, sizeof(info1)*(num - 1), SEEK_SET);
			_read(fhdr, &info1, sizeof(info1));
			printf("�������� %s ���޼۸� %f\n", info1.name, info1.db);
		}

		//_lseek(fhdr, sizeof(info1)*(num - 1), SEEK_SET);
		//_read(fhdr, &info1, sizeof(info1));
		_close(fhdr);
	}

	system("pause");
}


