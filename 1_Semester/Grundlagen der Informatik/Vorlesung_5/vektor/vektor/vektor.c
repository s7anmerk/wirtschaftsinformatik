#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n=0, i=0;
  double *zeiger=0;

  struct kv {
           unsigned long key;
		   double value;
  };
  struct kv *menge = 0;

  printf("Vektor dynamisch mit n > 0 Elementen autzen\n");
  do {
	  printf("\nZahl > 0 fuer die Dimension des Vektors: ");
	  scanf("%d", &n); while(getchar()!='\n');
  } while(n<=0);

  zeiger = (double *)malloc(n*sizeof(double));
  if(!zeiger){
	  printf("Kein Speicher fuer %d  double-Werte\n", n);
	  return -1;
  }

  srand(13U);  // Initialisierung rand
  for(i = 0; i < n; i++){
   
       *(zeiger + i) = (double)rand(); // pseudorandom integer from [0, RAND_MAX] (32767)
   //  zeiger[i] = rand(i);
	   printf("zeiger[ %d ] = %8.0lf\n", i, zeiger[i]);
  }
  printf("end\n");
  free(zeiger); zeiger = 0;
  getchar();
  return 0;
}

/*
Vektor dynamisch mit n > 0 Elementen autzen

Zahl > 0 fuer die Dimension des Vektors: 5
zeiger[ 0 ] =       81
zeiger[ 1 ] =    16376
zeiger[ 2 ] =    24096
zeiger[ 3 ] =    20348
zeiger[ 4 ] =    11872
end
*/