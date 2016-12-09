#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(void)
{
  int    i=0;
  double zeiger[N];

  srand(13U);  // Initialisierung rand
  for(i = 0; i < N; i++){
   
       zeiger[i] = (double)rand(); // pseudorandom integer from [0, RAND_MAX] (32767)
  
	   printf("zeiger[ %d ] = %8.0lf\n", i, zeiger[i]);
  }
  printf("end\n");
  getchar();
  return 0;
}

/*
Vektor dynamisch mit N = 5 Elementen nutzen

Zahl > 0 fuer die Dimension des Vektors: 5
zeiger[ 0 ] =       81
zeiger[ 1 ] =    16376
zeiger[ 2 ] =    24096
zeiger[ 3 ] =    20348
zeiger[ 4 ] =    11872
end
*/