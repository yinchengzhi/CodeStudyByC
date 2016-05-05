#include"init.h"
#include"datastruct.h"


struct Dataarray {
	struct data* pdataarray;
	int length;						//数组的长度
};


void init(struct Dataarray *p);
void initwithstring(struct Dataarray*p, char *str);
void showall(struct Dataarray *p);
void deleteall(struct Dataarray *p);

void findfirstbyQQ(struct Dataarray *p, long long QQ);
void findallbyQQ(struct Dataarray *p, long long QQ);

void findfirstbypassword(struct Dataarray *p,char *passstr);
void findallbypassword(struct Dataarray *p, char *passstr);

void changefirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata);
void changeallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata);

void changefirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata);
void changeallbypassword(struct Dataarray *p, char *passstr, struct data*pdata);

int combyQQ(void *p1, void *p2);
int combypass(void *p1,void *p2);

void sortbyQQ(struct Dataarray *p);
void sortbypass(struct Dataarray *p);


//删除，尾部插入，根据位置随机插入
void deletefirstbypassword(struct Dataarray *p, char *passstr);
void deletefirstbyQQ(struct Dataarray *p, long long QQ);

void deleteallbypassword(struct Dataarray *p, char *passstr);
void deleteallbyQQ(struct Dataarray *p, long long QQ);

void insertfirstbyQQ(struct Dataarray *p, long long QQ, struct data*pdata);
void insertallbyQQ(struct Dataarray *p, long long QQ, struct data*pdata);

void insertfirstbypassword(struct Dataarray *p, char *passstr, struct data*pdata);
void insertallbypassword(struct Dataarray *p, char *passstr, struct data*pdata);

void backinsert(struct Dataarray *p, struct data *pdata);