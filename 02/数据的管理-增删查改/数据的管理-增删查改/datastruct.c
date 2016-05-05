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
	p->length = strlen(px + 4);							//长度
	p->pstr = malloc(sizeof(char)*(p->length + 1));		//拓展内存
	strcpy(p->pstr, px + 4);							//拷贝字符串
}

void showdata(const struct data *p) {

	if (p != NULL && p->pstr!=NULL) {
		printf("%lld<-->%s\n", p->QQ, p->pstr);			//显示数据
	}
	else {
		abort();										//异常
	}
}


void changedata(struct data*p, struct data*newp) {		//浅拷贝
	if (p->pstr != NULL) {
		free(p->pstr);									//释放内存
	}
	(*p) = (*newp);										//直接拷贝
}

void changedatadeep(struct data*p,struct data*newp) {	//深拷贝
	if (p->pstr != NULL) {
		free(p->pstr);									//释放内存
	}

	(*p) = (*newp);										//直接拷贝
	p->pstr = malloc(strlen(newp->pstr)+1);
	strcpy(p->pstr, newp->pstr);						//拷贝
}
