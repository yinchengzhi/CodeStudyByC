#include"list.h"


//β������
PINFO addback(PINFO phead, char password[20]) {
	PINFO pnew = calloc(1, sizeof(INFO));							//�����ڴ�
	strcpy(pnew->password, password);								//��������
	pnew->ci = 1;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;												//ֱ�Ӳ���
	}
	else {
		pnew->pNext = phead;
		phead = pnew;												//ͷ��
	}
	return phead;
}

//����
PINFO sortByci(PINFO phead) {
	for (PINFO p1 = phead; p1 != NULL; p1 = p1->pNext) {
		for (PINFO p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p2->pNext != NULL) {
				if (p2->ci < p2->pNext->ci) {
					int citemp = p2->ci;									//��������
					p2->ci = p2->pNext->ci;
					p2->pNext->ci = citemp;

					char passtemp[100];
					strcpy(passtemp, p2->password);
					strcpy(p2->password, p2->pNext->password);
					strcpy(p2->pNext->password, passtemp);
				}
			}
		}
	}
}

//����
PINFO sortBypass(PINFO phead) {
	for (PINFO p1 = phead; p1 != NULL; p1 = p1->pNext) {
		for (PINFO p2 = phead; p2 != NULL; p2 = p2->pNext) {
			if (p2->pNext != NULL) {
				if (strcmp(p2->password, p2->pNext->password) < 0) {
					int citemp = p2->ci;									//��������
					p2->ci = p2->pNext->ci;
					p2->pNext->ci = citemp;

					char passtemp[100];
					strcpy(passtemp, p2->password);
					strcpy(p2->password, p2->pNext->password);
					strcpy(p2->pNext->password, passtemp);
				}
			}
		}
	}
}

//��ʾ
PINFO show(PINFO phead) {
	if (phead == NULL) {
		return;
	}
	else {
		printf("%s,%d\n", phead->password, phead->ci);
		show(phead->pNext);
	}

	return phead;
}

//�жϴ������
int isin(PINFO phead, char password[20]) {
	PINFO p = phead;
	while (p != NULL) {
		if (strcmp(p->password, password) == 0) {
			p->ci += 1;
			return 1;							//����
		}
		p = p->pNext;
	}
	return 0;									//���������ڲ�
}

//д�뵽�ļ�
void writetofile(PINFO phead) {

}