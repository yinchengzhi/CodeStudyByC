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
	p->length = 0;											//初始化
}


void initwithstring(struct Dataarray*p, char *str) {
	init(p);
	int length = getnum(str);										//获取长度
	p->pdataarray = malloc(sizeof(struct data)*length);	
	p->length = length;												//标识长度

	int alllength = strlen(str);									//取长度
	for (char *p = str; p < str + alllength; p++) {
		if (*p == ' ') {
			*p = '\0';												//代表终止
		}
	}

	//遍历字符串
	int i = 0;

	for (char *px = str; px < str + alllength; px += strlen(px) + 1) {
		char *pnew = malloc(sizeof(char)*(strlen(px) + 1));			//分配内存
		strcpy(pnew, px);											//拷贝字符串

		//printf("-%s-\n", px);
		initdatawithstring(&p->pdataarray[i], pnew);				//根据字符串初始化一个结构体
		i++;
	}

}


void showall(struct Dataarray *p) {

	printf("\n");
	for (int i = 0; i < p->length; i++) {
		//p->pdataarray[i];
		showdata(p->pdataarray + i);								//传递地址显示
	}
}

void deleteall(struct Dataarray *p) {

	printf("\n");
	for (int i = 0; i < p->length; i++) {
		free(p->pdataarray[i].pstr);								//释放内存
	}

	free(p->pdataarray);											//清空
	p->pdataarray = NULL;											
	p->length = 0;

}


void findfirstbyQQ(struct Dataarray *p, long long QQ) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("找到了第一个%lld,pass=%s\n",QQ,p->pdataarray[i].pstr);
			break;
		}
	}
	if (!flag) {
		printf("没有找到\n");
	}
}

void findallbyQQ(struct Dataarray *p, long long QQ) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("找到了第一个%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
		}
	}
	if (!flag) {
		printf("没有找到\n");
	}
}

void findfirstbypassword(struct Dataarray *p, char *passstr) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("找到了第一个%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			break;
		}
	}

	if (p1 == NULL) {
		printf("没有找到\n");
	}
}

void findallbypassword(struct Dataarray *p, char *passstr) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("找到了第一个%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
		}
	}

	if (p1 == NULL) {
		printf("没有找到\n");
	}
}

void changefirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("找到了第一个%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//保持QQ号码不能改变
			changedata(p->pdataarray + i, pdata);
			break;
		}
	}
	if (!flag) {
		printf("没有找到\n");
	}
}


void changeallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int flag = 0;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			flag = 1;
			printf("找到了第一个%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//保持QQ号码不能改变
			changedata(p->pdataarray + i, pdata);
		}
	}
	if (!flag) {
		printf("没有找到\n");
	}
}



void changefirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	char *p1 = NULL;
	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("找到了第一个%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;													//保持QQ号码不能改变
			changedata(p->pdataarray + i, pdata);												//修改
			break;
		}
	}

	if (p1 == NULL) {
		printf("没有找到\n");
	}

}


void changeallbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	char *p1 = NULL;

	for (int i = 0; i < p->length; i++) {
		p1 = strstr(p->pdataarray[i].pstr, passstr);
		if (p1 != NULL) {
			printf("找到了第一个%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			pdata->QQ = p->pdataarray[i].QQ;												//保持QQ号码不能改变
			changedata(p->pdataarray + i, pdata);											//修改
		}
	}

	if (p1 == NULL) {
		printf("没有找到\n");
	}
}


void deletefirstbypassword(struct Dataarray *p, char *passstr) {
	int curr = -1;

	for (int i = 0; i < p->length; i++) {

		char *pfind = strstr(p->pdataarray[i].pstr, passstr);
		if (pfind != NULL) {
			curr = i;									//保存找到下标
			break;
		}
	}
	if (curr == -1) {
		printf("没有找到，无法删除！");
	}
	else {
		free(p->pdataarray[curr].pstr);					//释放内存
		for (int i = curr; i < p->length - 1; i++) {
			p->pdataarray[i] = p->pdataarray[i + 1];
		}

		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//压缩内存
	}
}


void deletefirstbyQQ(struct Dataarray *p, long long QQ) {
	int curr = -1;

	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			curr = i;									//保存找到下标
			break;
		}
	}
	if (curr == -1) {
		printf("没有找到，无法删除！");
	}
	else {
		free(p->pdataarray[curr].pstr);					//释放内存
		for (int i = curr; i < p->length - 1; i++) {
			p->pdataarray[i] = p->pdataarray[i + 1];
		}

		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//压缩内存
	}
}

void deleteallbypassword(struct Dataarray *p, char *passstr) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		p->pdataarray[i] = p->pdataarray[j];											//结构体之间的赋值
		int mylength = p->length;														//保存长度
		if (i >= mylength || j >= mylength) {											//超过原来的长度
			break;
		}

		char *pres = strstr(p->pdataarray[i].pstr,passstr);

		if (pres!=NULL) {
			free(p->pdataarray[i].pstr);												//释放内存
			j++;
			k++;
		}
		else {
			i++;
			j++;																		//同步
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//压缩内存
}

void deleteallbyQQ(struct Dataarray *p, long long QQ) {									//双指针
	int i = 0;
	int j = 0;
	int k = 0;
	while (1) {
		p->pdataarray[i] = p->pdataarray[j];											//结构体之间的赋值
		int mylength = p->length;														//保存长度
		if (i >= mylength || j >= mylength) {											//超过原来的长度
			break;
		}
		if (p->pdataarray[i].QQ == QQ) {
			free(p->pdataarray[i].pstr);												//释放内存
			j++;
			k++;
		}
		else {
			i++;
			j++;																		//同步
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*p->length);				//压缩内存
}



void backinsert(struct Dataarray *p, struct data *pdata) {
	p->length += 1;
	p->pdataarray = realloc(p->pdataarray,sizeof(struct data)*(p->length));				//拓展内存

	p->pdataarray[p->length - 1] = *pdata;
}




void insertfirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {

	int curr = -1;
	for (int i = 0; i < p->length; i++) {
		if (QQ == p->pdataarray[i].QQ) {
			curr = i;
			printf("找到了第一个%lld,pass=%s\n", QQ, p->pdataarray[i].pstr);
			break;
		}
	}
	
	if (curr==-1) {
		printf("没有找到\n");
	}
	else {
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length+1));	   //拓展内存

		for (int i = p->length - 1; i >=curr; i--) {								   //往后移动
			p->pdataarray[i + 1] = p->pdataarray[i];
		}

		p->pdataarray[curr] = *pdata;												   //插入
		p->length += 1;
	}

}
void insertallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata) {
	int i = 0;
	int j = 0;

	while (1) {
		p->pdataarray[i] = p->pdataarray[j];													//结构体之间的赋值
		if (i >= p->length || j >= p->length) {													//超过原来的长度
			break;
		}
		if (p->pdataarray[i].QQ == QQ) {
			p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length + 1));	    //拓展内存
			for (int l = p->length - 1; l >= i; l--) {
				p->pdataarray[l + 1] = p->pdataarray[l];
			}

			p->pdataarray[i] = *pdata;
			p->length += 1;

			i += 2;																				//前插
			j += 2;

		}
		else {
			i++;
			j++;																				//同步
		}
	}
}


void insertfirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata) {
	int curr = -1;
	for (int i = 0; i < p->length; i++) {
		if (passstr == p->pdataarray[i].pstr) {
			curr = i;
			printf("找到了第一个%lld,pass=%s\n", p->pdataarray[i].QQ, p->pdataarray[i].pstr);
			break;
		}
	}

	if (curr == -1) {
		printf("没有找到\n");
	}
	else {
		p->pdataarray = realloc(p->pdataarray, sizeof(struct data)*(p->length + 1));		  //拓展内存
		for (int i = p->length - 1; i >= curr; i--) {
			p->pdataarray[i + 1] = p->pdataarray[i];										  //往后移动
		}

		p->pdataarray[curr] = *pdata;														  //插入
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

			p->pdataarray[i] = *pdata;														//前插
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