#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 5

int main(void)
{
  int i=0, j=0;  
  double zeiger[M][N], sum = 0.0;       // Matrix 

  for(i = 0; i < M; i++)
	  for(j = 0; j < N; j++) {
  
		zeiger[i][j]= 3.0*(i + j);  
  
	  }

  for(i=0; i<M; i++)
	  sum += zeiger[i][i];

  printf("Summe Hauptdiagonale = %lf\n", sum);
  getchar();
  return 0;
}

/*
Summe Hauptdiagonale = 60.000000
*/