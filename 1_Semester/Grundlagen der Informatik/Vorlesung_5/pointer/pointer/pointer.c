#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=8, y=0; int *px=&x;

	int *py = (int *)malloc(sizeof(int)); 

	y = *py = *px + *px;

	printf("py = %p,  *py = %d\n", py, *py); 

	*py = 9;

	printf("py = %p,  *py = %d\n", py, *py); 

	free(py);
	py=0;

	getchar();
	return 0;
}

/*
   py = 000000C737DA7460,  *py = 16
   py = 000000C737DA7460,  *py = 9
*/