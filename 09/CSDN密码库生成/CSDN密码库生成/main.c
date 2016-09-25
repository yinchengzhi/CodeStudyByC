#include"list.h"

void main() {

	PINFO phead = NULL;


	char *str[10] = { "123","1234","456","789","2345","123",
		"456","789","1234","123" };

	for (int i = 0; i < 10; i++) {
		if (isin(phead,str[i])==0) {
			phead = addback(phead, str[i]);
		}
	}

	show(phead);

	sortByci(phead);
	printf("\n\n");
	show(phead);

	sortBypass(phead);
	printf("\n\n");
	show(phead);


	system("pause");
}