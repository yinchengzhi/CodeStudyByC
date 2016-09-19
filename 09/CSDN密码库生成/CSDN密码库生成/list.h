#include<stdio.h>
#include<stdlib.h>

struct passinfo{
	char password[20];
	int ci;
	struct passinfo *pNext;
}INFO, *PINFO;
