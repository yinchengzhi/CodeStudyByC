#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define	allN	10000000

void init();
char *convertQQ(char*str);

void search(char *str);
void deleteit(char *str);
void insert(char *str, char *pass);
void changeit(char *str, char *newpass);

void assignmem(char **pp, int deep, char *str);