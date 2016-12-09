#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int m=0, n=0, i=0, j=0;  // m Zeilen, n Spalten
  double **zeiger=0;       // Matrix (Zeiger auf Zeiger auf double)

  printf("Matrix dynamisch mit m > 0 Zeilen und n > 0 Spalten nutzen\n");
  do {
	  printf("\nZeilen m > 0 der Matrix : ");
	  scanf("%d", &m); while(getchar()!='\n'); // fflush(stdin);
  } while(m<=0);

  zeiger = (double **)malloc(m*sizeof(double *));
  if(!zeiger){
	  printf("Kein Speicher fuer %d Byte\n", m*sizeof(double *));
	  return -1;
  }

  do {
	  printf("\nSpalten n > 0 der Matrix: ");
	  scanf("%d", &n);  while(getchar()!='\n'); //fflush(stdin);
  } while(n<=0);

  printf("\n");
  for(i = 0; i<m; i++){
	  *(zeiger+i) = (double *)malloc(n*sizeof(double));
	  if(!zeiger[i]){
			printf("Kein Speicher fuer %d Byte\n", n*sizeof(double));
			return -1;
	  }
	  for(j=0; j<n; j++){
		  zeiger[i][j] = (double)(i+j); // *(*(zeiger+i)+j) = (double)(i+j);
		  printf("zeiger[ %d ][ %d ] = %8.0lf\n", i, j, zeiger[i][j]);
	  }
  }
  
  for(i = 0; i < m; i++){
		free(zeiger[i]); zeiger[i]=0;  
  }
  free(zeiger); zeiger = 0; m=n=0;

  printf("end\n");
  getchar();
  return 0;
}

/*
Matrix dynamisch mit m > 0 Zeilen und n > 0 Spalten nutzen

Zeilen m > 0 der Matrix : 3

Spalten n > 0 der Matrix: 2

zeiger[ 0 ][ 0 ] =        0
zeiger[ 0 ][ 1 ] =        1
zeiger[ 1 ][ 0 ] =        1
zeiger[ 1 ][ 1 ] =        2
zeiger[ 2 ][ 0 ] =        2
zeiger[ 2 ][ 1 ] =        3
end
*/