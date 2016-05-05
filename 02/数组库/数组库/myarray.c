#include "myarray.h"



void init(struct array *parr) {
	if (parr != NULL) {
		parr->pstart = NULL;
		parr->length = 0;
		parr->sortstat = 0;
	}
	else {
		printf("init error");
	}
}

void initwithdata(struct array *parr, datatype data) {
	if (parr != NULL) {
		parr->pstart = malloc(sizeof(datatype));
		*(parr->pstart) = data;				//初始化
		parr->length = 1;
		parr->sortstat = 0;
	}
	else {
		printf("initwithdata error");
	}
}

void initwitharray(struct array *parr, datatype *pdata, int datalength) {
	if (parr != NULL) {
		parr->pstart = malloc(sizeof(datatype)*datalength);				//分配数组的长度
		memcpy(parr->pstart, pdata, sizeof(datatype)*datalength);		//内存拷贝
		parr->length = datalength;
		parr->sortstat = 0;
	}
	else {
		printf("initwitharray error");
	}

}
void show(struct array *parr) {
	if (parr == NULL||parr->pstart==NULL||parr->length==0) {
		printf("没有数据咋打印？");
		return;
	}
	else {
		//5 0-4
		printf("\n数组此时状态\n");
		for (int i = 0; i < parr->length; i++) {
			printf("%4d", parr->pstart[i]);				//打印数据
		}
	}
}

void addobject(struct array *parr, datatype data) {
	if (parr != NULL) {
		if (parr->pstart == NULL||parr->length==0) {
			initwithdata(parr, data);
		}
		else {
			//5 a[4]
			parr->pstart = realloc(parr->pstart, (parr->length + 1)*sizeof(datatype));			//拓展内存
			parr->pstart[parr->length] = data;		//插入
			parr->length += 1;						//长度自增
		}
	}
	else {
		printf("addobject error");
	}
}
void addobjects(struct array *parr, datatype *pdata, int datalength) {
	if (parr != NULL) {
		if (parr->pstart == NULL || parr->length == 0) {
			initwitharray(parr, pdata, datalength);			//调用初始化
		}
		else {
			//12345  a[4] & a[5]
			parr->pstart = realloc(parr->pstart, (parr->length + datalength)*sizeof(datatype));			//拓展内存
			memcpy(parr->pstart + parr->length,pdata, datalength*sizeof(datatype));
			parr->length += datalength;						//长度自增
		}
	}
	else {
		printf("addobjects error");
	}
}

datatype *findfirst(struct array *parr, datatype data) {
	if (parr == NULL || parr->pstart == NULL || parr->length == 0) {
		printf("没有数据咋查找！");
		return NULL;
	}
	else {
		datatype *pfind = NULL;
		for (int i = 0; i < parr->length; i++) {
			if (parr->pstart[i]==data) {
				pfind = &parr->pstart[i];				//parr->pstart + i;
				break;
			}
		}

		return pfind;
	}
}


void insertobject(struct array *parr, datatype data, datatype insertdata) {				//根据位置来插入

	if (parr != NULL) {
		datatype *pfind = findfirst(parr, data);
		if (pfind == NULL) {
			printf("can not insertobject error");
		}
		else {
			int curr = pfind - parr->pstart;											//指针相减确定下标，当前数据的下标
			parr->pstart = realloc(parr->pstart, (parr->length + 1)*sizeof(datatype));	//拓展内存

			for (int i = parr->length - 1; i >= curr; i--) {
				parr->pstart[i + 1] = parr->pstart[i];									//往后移动
			}

			parr->pstart[curr] = insertdata;											//插入数据
			parr->length += 1;															//长度自增
		}
	}
	else {
		printf("insertobject error");
	}
}

void insertobjects(struct array *parr, datatype data, datatype *pdata, int datalength) {
	if (parr != NULL) {
		datatype *pfind = findfirst(parr, data);
		if (pfind == NULL) {
			printf("can not insertobject error");
		}
		else {
			int curr = pfind - parr->pstart;											//指针相减确定下标，当前数据的下标
			parr->pstart = realloc(parr->pstart, (parr->length + datalength)*sizeof(datatype));	//拓展内存

			for (int i = parr->length - 1; i >= curr; i--) {
				parr->pstart[i + datalength] = parr->pstart[i];							//往后移动
			}

			//parr->pstart[curr] = insertdata;											//插入数据

			memcpy(parr->pstart + curr, pdata, datalength*sizeof(datatype));

			parr->length += datalength;													//长度自增
		}
	}
	else {
		printf("insertobject error");
	}
}


void deletefirstobject(struct array *parr, datatype data) {
	if (parr != NULL) {
		datatype *pfind = findfirst(parr, data);
		if (pfind == NULL) {
			printf("can not find delete error!");
		}
		else {
			int curr = pfind - parr->pstart;										    //指针相减确定下标，当前数据的下标
			for (int i = curr; i < parr->length - 1; i++) {
				parr->pstart[i] = parr->pstart[i + 1];									//删除从后向前移动
			}
			parr->length -= 1;
			parr->pstart = realloc(parr->pstart, (parr->length)*sizeof(datatype));		//压缩
		}
	}
	else {
		printf("delete error!");
	}
}


void deleteallobject(struct array *parr, datatype data) {
	if (parr != NULL) {
		for (int *pcurr = findfirst(parr, data); pcurr != NULL; pcurr = findfirst(parr, data)) {
			deletefirstobject(parr, data);
		}
	}
	else {
		printf("delete error!");
	}
}


void changefirstobject(struct array *parr, datatype data, datatype newdata) {
	if (parr != NULL) {
		datatype *pfind = findfirst(parr, data);
		if (pfind == NULL) {
			printf("can not find change error!");
		}
		else {
			*pfind = newdata;
		}
	}
	else {
		printf("change error!");
	}
}
void changeallobject(struct array *parr, datatype data, datatype newdata) {
	if (parr != NULL) {
		for (int *pcurr = findfirst(parr, data); pcurr != NULL; pcurr = findfirst(parr, data)) {
			changefirstobject(parr, data, newdata);
		}
	}
	else {
		printf("delete error!");
	}
}

struct Res findall(struct array *parr, datatype data) {
	struct Res ResA;
	ResA.n = 0;
	for (int i = 0; i < parr->length; i++) {
		if (data == parr->pstart[i]) {					   //基本完成
			ResA.n++;
		}
	}

	ResA.ppstart = malloc(sizeof(datatype *)*ResA.n);
	int j = 0;	//代表下标

	for (int i = 0; i < parr->length; i++) {
		if (data == parr->pstart[i]) {					    //基本完成
			ResA.ppstart[j++] = parr->pstart + i;			//保存地址
		}
	}

	return ResA;

}