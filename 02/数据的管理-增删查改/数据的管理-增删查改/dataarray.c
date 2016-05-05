#include"dataarray.h"


int combyQQ(void *p1, void *p2) {

	struct data*pd1 = p1;
	struct data*pd2 = p2;

	if (pd1->QQ == pd2->QQ) {
		return 0;
	}
	else if (pd1->QQ>pd2->QQ){
		return 1;
	}
	else {
		return -1;
	}
}

int combypass(void *p1, void *p2) {
	struct data*pd1 = p1;
	struct data*pd2 = p2;

	return strcmp(pd1->pstr, pd2->pstr);
}

void sortbyQQ(struct Dataarray *p) {
	qsort(p->pdataarray,p->length,sizeof(struct data),combyQQ);
}

void sortbypass(struct Dataarray *p) {
	qsort(p->pdataarray, p->length, sizeof(struct data), combypass);
}


void init(struct Dataarray *p) {
	p->pdataarray = NULL;
	p->length = 0;											//��ʼ��
}


void initwithstring(struct Dataarray*p, char *str) {
	init(p);
	int length = getnum(str);										//��ȡ����
	p->pdataarray = malloc(sizeof(struct data)*length);	
	p->length = length;												//��ʶ����

	int alllength = strlen(str);									//ȡ����
	for (char *p = str; p < str + alllength; p++) {
		if (*p == ' ') {
			*p = '\0';												//������ֹ
		}
	}

	//�����ַ���
	int i = 0;

	for (char *px = str; px < str + alllength; px += strlen(px) + 1) {
		char *pnew = malloc(sizeof(char)*(strlen(px) + 1));			//�����ڴ�
		strcpy(pnew, px);											//�����ַ���

		//printf("-%s-\n", px);
		initdatawithstring(&p->pdataarray[i], pnew);				//�����ַ�����ʼ��һ���ṹ��
		i++;
	}

}


void showall(struct Dataarray *p) {

	printf("\n");
	for (int i = 0; i < p->length; i++) {
		//p->pdataarray[i];
		showdata(p->pdataarray + i);								//���ݵ�ַ��ʾ
	}
}

void deleteall(struct Dataarray *p) {

	printf("\n");
	for (int i = 0; i < p->length; i++) {
		free(p->pdataarray[i].pstr);								//�ͷ��ڴ�
	}

	free(p->pdataarray);											//���
	p->pdataarray = NULL;											
	p->length = 0;

}


void findfirstbyQQ(struct Dataarray *p, long long QQ) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("�ҵ��˵�һ��%lld,pass=%s\n",QQ,p->pdataarray[i].pstr);
			break;
		}
	}
	if (!flag) {
		printf("û���ҵ�\n");
	}
}

void findallbyQQ(struct Dataarray *p, long long QQ) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("�ҵ��˵�һ��%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
		}
	}
	if (!flag) {
		printf("û���ҵ�\n");
	}
}

void findfirstbypassword(struct Dataarray *p, char *passstr) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("�ҵ��˵�һ��%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			break;
		}
	}

	if (p1 == NULL) {
		printf("û���ҵ�\n");
	}
}

void findallbypassword(struct Dataarray *p, char *passstr) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("�ҵ��˵�һ��%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
		}
	}

	if (p1 == NULL) {
		printf("û���ҵ�\n");
	}
}

void changefirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("�ҵ��˵�һ��%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//����QQ���벻�ܸı�
			changedata(p->pdataarray + i, pdata);
			break;
		}
	}
	if (!flag) {
		printf("û���ҵ�\n");
	}
}


void changeallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("�ҵ��˵�һ��%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//����QQ���벻�ܸı�
			changedata(p->pdataarray + i, pdata);
		}
	}
	if (!flag) {
		printf("û���ҵ�\n");
	}
}



void changefirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	char *p1 = NULL;
	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("�ҵ��˵�һ��%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//����QQ���벻�ܸı�
			changedata(p->pdataarray + i, pdata);												//�޸�
			break;
		}
	}

	if (p1 == NULL) {
		printf("û���ҵ�\n");
	}

}


void changeallbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("�ҵ��˵�һ��%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;												//����QQ���벻�ܸı�
			changedata(p->pdataarray + i, pdata);											//�޸�
		}
	}

	if (p1 == NULL) {
		printf("û���ҵ�\n");
	}
}


void deletefirstbypassword(struct Dataarray *p, char *passstr) {
	int curr = -1;

	for (int i = 0; i < p->length; i++) {

		char *pfind = strstr(p->pdataarray[i].pstr, passstr);
		if (pfind != NULL) {
			curr = i;									//�����ҵ��±�
			break;
		}
	}
	if (curr == -1) {
		printf("û���ҵ����޷�ɾ����");
	}
	else {
		free(p->pdataarray[curr].pstr);					//�ͷ��ڴ�
		for (int i = curr; i < p->length - 1; i++) {
			p->pdataarray[i] = p->pdataarray[i + 1];
		}

		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//ѹ���ڴ�
	}
}


void deletefirstbyQQ(struct Dataarray *p, long long QQ) {
	int curr = -1;

	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			curr = i;									//�����ҵ��±�
			break;
		}
	}
	if (curr == -1) {
		printf("û���ҵ����޷�ɾ����");
	}
	else {
		free(p->pdataarray[curr].pstr);					//�ͷ��ڴ�
		for (int i = curr; i < p->length - 1; i++) {
			p->pdataarray[i] = p->pdataarray[i + 1];
		}

		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//ѹ���ڴ�
	}
}

void deleteallbypassword(struct Dataarray *p, char *passstr) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		p->pdataarray[i] = p->pdataarray[j];											//�ṹ��֮��ĸ�ֵ
		int mylength = p->length;														//���泤��
		if (i >= mylength || j >= mylength) {											//����ԭ���ĳ���
			break;
		}

		char *pres = strstr(p->pdataarray[i].pstr,passstr);

		if (pres!=NULL) {
			free(p->pdataarray[i].pstr);												//�ͷ��ڴ�
			j++;
			k++;
		}
		else {
			i++;
			j++;																		//ͬ��
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//ѹ���ڴ�
}

void deleteallbyQQ(struct Dataarray *p, long long QQ) {									//˫ָ��
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		p->pdataarray[i] = p->pdataarray[j];											//�ṹ��֮��ĸ�ֵ
		int mylength = p->length;														//���泤��
		if (i >= mylength || j >= mylength) {											//����ԭ���ĳ���
			break;
		}
		if (p->pdataarray[i].QQ == QQ) {
			free(p->pdataarray[i].pstr);												//�ͷ��ڴ�
			j++;
			k++;
		}
		else {
			i++;
			j++;																		//ͬ��
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//ѹ���ڴ�
}



void backinsert(struct Dataarray *p, struct data *pdata) {
	p->length += 1;
	p->pdataarray = realloc(p->pdataarray,sizeof(struct data)*(p->length));				//��չ�ڴ�

	p->pdataarray[p->length - 1] = *pdata;
}




void insertfirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {

	int curr = -1;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			curr = i;
			printf("�ҵ��˵�һ��%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			break;
		}
	}
	
	if (curr==-1) {
		printf("û���ҵ�\n");
	}
	else {
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length+1));	   //��չ�ڴ�

		for (int i = p->length - 1; i >=curr; i--) {								   //�����ƶ�
			p->pdataarray[i + 1] = p->pdataarray[i];
		}

		p->pdataarray[curr] = *pdata;												   //����
		p->length += 1;
	}

}
void insertallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int i = 0;
	int j = 0;

	while (1) {
		p->pdataarray[i] = p->pdataarray[j];													//�ṹ��֮��ĸ�ֵ
		if (i >= p->length || j >= p->length) {													//����ԭ���ĳ���
			break;
		}
		if (p->pdataarray[i].QQ == QQ) {
			p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length + 1));	    //��չ�ڴ�
			for (int l = p->length - 1; l >= i; l--) {
				p->pdataarray[l + 1] = p->pdataarray[l];
			}

			p->pdataarray[i] = *pdata;
			p->length += 1;

			i += 2;																				//ǰ��
			j += 2;

		}
		else {
			i++;
			j++;																				//ͬ��
		}
	}
}


void insertfirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	int curr = -1;
	for (int i = 0; i < p->length; i++) {
		if (passstr == p->pdataarray[i].pstr) {
			curr = i;
			printf("�ҵ��˵�һ��%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			break;
		}
	}

	if (curr == -1) {
		printf("û���ҵ�\n");
	}
	else {
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length + 1));		  //��չ�ڴ�
		for (int i = p->length - 1; i >= curr; i--) {
			p->pdataarray[i + 1] = p->pdataarray[i];										  //�����ƶ�
		}

		p->pdataarray[curr] = *pdata;														  //����
		p->length += 1;
	}
}


void insertallbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	int i = 0;
	int j = 0;

	while (1) {
		p->pdataarray[i] = p->pdataarray[j];
		if (i >= p->length || j >= p->length) {
			break;
		}
		if (p->pdataarray[i].pstr == passstr) {
			p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length + 1));
			for (int l = p->length - 1; l >= i; l--) {
				p->pdataarray[l + 1] = p->pdataarray[l];
			}

			p->pdataarray[i] = *pdata;														//ǰ��
			p->length += 1;

			i += 2;
			j += 2;
		}
		else {
			i++;
			j++;
		}

	}
}