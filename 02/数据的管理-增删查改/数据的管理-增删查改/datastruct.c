#include"datastruct.h"

void initwithstructdata(struct data*p, long long QQ, char *pstr) {

	p->QQ = QQ;
	p->length = strlen(pstr) + 1;
	p->pstr = malloc(sizeof(char)*(p->length));
	strcpy(p->pstr, pstr);
}


void newinitdatawithstring(struct data *p, char *initstr) {
	p->pstr = malloc(sizeof(char)*(strlen(initstr)+1));
	strcpy(p->pstr, initstr);
}


void initdatawithstring(struct data *p, char *initstr){
	char *px = strstr(initstr, "----");
	*px = '\0';
	sscanf(initstr, "%lld", &p->QQ);					
	p->length = strlen(px + 4);							//����
	p->pstr = malloc(sizeof(char)*(p->length + 1));		//��չ�ڴ�
	strcpy(p->pstr, px + 4);							//�����ַ���
}

void showdata(const struct data *p) {

	if (p != NULL && p->pstr!=NULL) {
		printf("%lld<-->%s\n", p->QQ, p->pstr);			//��ʾ����
	}
	else {
		abort();										//�쳣
	}
}


void changedata(struct data*p, struct data*newp) {		//ǳ����
	if (p->pstr != NULL) {
		free(p->pstr);									//�ͷ��ڴ�
	}
	(*p) = (*newp);										//ֱ�ӿ���
}

void changedatadeep(struct data*p,struct data*newp) {	//���
	if (p->pstr != NULL) {
		free(p->pstr);									//�ͷ��ڴ�
	}

	(*p) = (*newp);										//ֱ�ӿ���
	p->pstr = malloc(strlen(newp->pstr)+1);
	strcpy(p->pstr, newp->pstr);						//����
}
