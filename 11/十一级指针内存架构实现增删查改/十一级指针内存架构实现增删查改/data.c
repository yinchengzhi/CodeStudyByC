#include"data.h"

char *path = "G:\\BigData.txt";
char ***********allP = NULL;
//allp[1][2][3][4]

void init() {
	allP = malloc(sizeof(char*) * 10);											//����ָ������
	memset(allP, '\0', sizeof(char*) * 10);										//����
	FILE *pf = fopen(path, "r");

	if (pf == NULL) {
		printf("�ļ���ʧ��");
		return;
	}
	else {
		for (int i = 0; i < allN; i++) {
			char str[50] = { 0 };
			fgets(str, 50, pf);													//��ȡ
			char *tmpstr = convertQQ(str);										//��ȡQQ��
			if (isallnum(tmpstr)) {
				assignmem(&allP, 11, tmpstr);
				strcpy(allP[getnum(tmpstr[0])]
					[getnum(tmpstr[1])]
				[getnum(tmpstr[2])]
				[getnum(tmpstr[3])]
				[getnum(tmpstr[4])]
				[getnum(tmpstr[5])]
				[getnum(tmpstr[6])]
				[getnum(tmpstr[7])]
				[getnum(tmpstr[8])]
				[getnum(tmpstr[9])], str);
			}
		}
	}

	fclose(pf);
}

char *convertQQ(char*str) {
	int length = strlen(str);													//��ȡ����
	char *tmp = malloc(length + 1);
	strcpy(tmp, str);															//����,���������Զ�����
	char *p = strchr(tmp, '-');
	if (p != NULL) {
		*p = '\0';
	}
	int count = strlen(tmp);													//��ȡQQ���ȣ�8λ
	//1121464690
	if (count < 10) {
		//'0'==48
		for (int i = 10; i >= 0; i--, count--) {								//10	8
			if (count >= 0) {													//�ƶ�8��
				tmp[i] = tmp[count];
			}
			else {
				//���0
				tmp[i] = '0';
			}
		}
	}

	return tmp;
}

int isallnum(char *str) {														//�ж��ַ����Ƿ��зǷ��ַ�
	while (*str) {
		str++;
		if (*str < '0' || *str>'9') {
			return 0;
		}
		str++;
	}
	return 1;
}

int getnum(char ch) {
	return ch - '0';															//0 1
}

//1214646913
//

void assignmem(char **pp, int deep, char *str) {
	if (deep == 1) {
		pp[getnum(*(str + 10 - deep))] = malloc(sizeof(char) * 50);
		memset(pp[getnum(*(str + 10 - deep))], 0, sizeof(char) * 50);
		return;
	}

	if (deep == 11) {
		assignmem(*pp, deep - 1, str);											//�ݹ����
		return;
	}

	//�������֣�ÿһλ
	if (pp[getnum(*(str + 10 - deep))]) {										//!=0
		assignmem(pp[getnum(*(str + 10 - deep))], deep - 1, str);				//�ݹ����
	}
	else {
		pp[getnum(*(str + 10 - deep))] = malloc(sizeof(char*) * 10);
		memset(pp[getnum(*(str + 10 - deep))], 0, sizeof(char*) * 10);
		assignmem(pp[getnum(*(str + 10 - deep))], deep - 1, str);				//�ݹ����
	}
}

void search(char *str) {
	if (isallnum(str) == 0) {
		return;
	}
	if (strlen(str) > 10) {
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10) {															//77025077
		for (int i = 10; i >= 0; i--, count--) {
			if (count >= 0) {
				tmp[i] = str[count];
			}
			else {
				tmp[i] = '0';
			}
		}
	}
	else {
		printf("���Ϸ�");
		return;
	}

	//0
	if (allP[getnum(tmp[0])]) {
		if (allP[getnum(tmp[0])][getnum(tmp[1])]) {
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])]) {
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])]) {
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])]) {
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])]) {
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])]) {
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])]) {
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])]) {
										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]) {
											free(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = NULL;
											printf("%s\n", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("û���ҵ�");

}

void deleteit(char *str) {
	if (isallnum(str) == 0) {
		return;
	}
	if (strlen(str) > 10) {
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10) {															//77025077
		for (int i = 10; i >= 0; i--, count--) {
			if (count >= 0) {
				tmp[i] = str[count];
			}
			else {
				tmp[i] = '0';
			}
		}
	}
	else {
		printf("���Ϸ�");
		return;
	}

	//0
	if (allP[getnum(tmp[0])]) {
		if (allP[getnum(tmp[0])][getnum(tmp[1])]) {
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])]) {
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])]) {
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])]) {
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])]) {
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])]) {
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])]) {
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])]) {

										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]) {

											//free(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											//allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = NULL;

											printf("%s\n", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											printf("�Ѿ�����");
											return;
										}
										else {
											int length = strlen(pass);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = calloc(length + 1, 1);
											strcpy(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])], pass);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("û���ҵ�");
}


void insert(char *str, char *pass) {
	if (isallnum(str) == 0) {
		return;
	}
	if (strlen(str) > 10) {
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10) {															//77025077
		for (int i = 10; i >= 0; i--, count--) {
			if (count >= 0) {
				tmp[i] = str[count];
			}
			else {
				tmp[i] = '0';
			}
		}
	}
	else {
		printf("���Ϸ�");
		return;
	}

	//0
	if (allP[getnum(tmp[0])]) {
		if (allP[getnum(tmp[0])][getnum(tmp[1])]) {
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])]) {
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])]) {
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])]) {
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])]) {
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])]) {
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])]) {
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])]) {

										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]) {

											printf("%s\n", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											printf("�Ѿ�����");
											return;
										}
										else {
											int length = strlen(pass);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = calloc(length + 1, 1);
											strcpy(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])], pass);
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("û���ҵ�");
}

void changeit(char *str, char *newpass) {
	if (isallnum(str) == 0) {
		return;
	}
	if (strlen(str) > 10) {
		return;
	}
	char *tmp = malloc(11);
	int count = strlen(str);
	if (count <= 10) {															//77025077
		for (int i = 10; i >= 0; i--, count--) {
			if (count >= 0) {
				tmp[i] = str[count];
			}
			else {
				tmp[i] = '0';
			}
		}
	}
	else {
		printf("���Ϸ�");
		return;
	}

	//0
	if (allP[getnum(tmp[0])]) {
		if (allP[getnum(tmp[0])][getnum(tmp[1])]) {
			if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])]) {
				if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])]) {
					if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])]) {
						if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])]) {
							if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])]) {
								if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])]) {
									if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])]) {

										if (allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]) {

											//printf("%s\n", allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											printf("�Ѿ�����");
											free(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])]);
											int length = strlen(newpass);
											allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])] = calloc(length + 1, 1);
											strcpy(allP[getnum(tmp[0])][getnum(tmp[1])][getnum(tmp[2])][getnum(tmp[3])][getnum(tmp[4])][getnum(tmp[5])][getnum(tmp[6])][getnum(tmp[7])][getnum(tmp[8])][getnum(tmp[9])], newpass);

											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("û���ҵ�");
}