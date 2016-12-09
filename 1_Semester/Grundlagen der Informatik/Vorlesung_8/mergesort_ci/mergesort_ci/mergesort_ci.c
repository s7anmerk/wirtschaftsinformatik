#include  <stdio.h>
#define MIN(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define N 10

/*------------------------------------------------------------------ merge */
void merge(int z[], int l, int m, int r) {
   int i, j, k;
   int hilf[N];
   for (i=m+1; i>l; i--)
      hilf[i-1] = z[i-1];
   for (j=m; j<r; j++)
      hilf[r+m-j] = z[j+1];
   for (k=l; k<=r; k++)
      z[k] = (hilf[i] < hilf[j]) ? hilf[i++] : hilf[j--];
}
/*-------------------------------------------merge_sort iterativ ---------*/
void merge_sort(int z[], int l, int r) {
   int i, m;
   for (m=1; m<r-l+1; m+=m) 
      for (i=l; i<=r-m; i+= m+m) {
         int mitte = i+m-1;
         merge(z, i, mitte, MIN(i+m+m-1, r));  
      }
}
/*------------------------------------------------------------------- main */
int  main(int argc, char *argv[]) {
	int i, zahlen[N]={5, 1, 8, 3, 9, 2, 7, 6, 0, 4};
   
	printf("unsortiert:\n");
	for(i=0; i<N; i++)
		printf("%d  ",zahlen[i]);
	printf("\n");

    merge_sort(zahlen, 0, N-1);

	printf("sortiert:\n");
	for(i=0; i<N; i++)
		printf("%d  ",zahlen[i]);
	printf("\n");
    getc(stdin);
  
   return 0;
}

/*
unsortiert:
5  1  8  3  9  2
sortiert:
1  2  3  5  8  9
*/