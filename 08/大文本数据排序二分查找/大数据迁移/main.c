
//#include"createsort.h"
//#include "createindex.h"
#include "binsearch.h"

void initall() {
	strcpy(filepath, "G:\\BigData.txt");
	strcpy(sortpath, "G:\\BigDataSort.txt");
	strcpy(indexpath, "G:\\BigDataIndex.txt");
}

void main() {

	initall();

	//initmem();
	//sort();
	//writetofile();
	
	//init();

	while (1) {
		char str[256] = { 0 };
		scanf("%s", str);
		binsearch(str);
	}

	system("pause");
}