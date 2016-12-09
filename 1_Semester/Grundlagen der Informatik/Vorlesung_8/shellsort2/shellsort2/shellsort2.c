#include  <stdio.h>
#include <stdlib.h>
#define N 100

void shell_sort(int z[], int l, int r) {
   int i, j, k, h, v;
   int sw[16] = { 1391376, 463792, 198768, 86961, 33936, 13776,
                  4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };
   for (k=0; k<16; k++) {      
      for (h=sw[k], i=l+h; i<=r; i++) { 
         v = z[i];
         j = i;
         while (j >= h && z[j-h] > v) {
            z[j] = z[j-h];
            j -= h;
         }
         z[j] = v;          
      }       
   }
}

int  main(int argc, char *argv[]) {
	int i, x, zahlen[N], h[N+1]={0};
  
   for (i=0; i<N; i++) {
      do { x=rand()%N+1; } while (h[x]);
      zahlen[i] = x;
      h[x] = 1;
   }
   printf("ShellSort\n\nunsortiert:\n");
   for(i=0; i<N; i++) printf("%d ", zahlen[i]);

   shell_sort(zahlen, 0, N-1);
	
   printf("\n\nsortiert:\n");
   for(i=0; i<N; i++) printf("%d ", zahlen[i]);
   getc(stdin);
   return 0;
}
/*
ShellSort

unsortiert:
42 68 35 1 70 25 79 59 63 65 6 46 82 28 62 92 96 43 37 5 3 54 93 83 22 17 19 48
27 72 39 13 100 36 95 4 12 23 34 74 69 45 58 38 60 24 30 91 89 7 41 49 47 71 51
2 94 85 55 57 67 77 32 9 40 16 31 78 87 73 98 56 75 53 8 88 84 10 14 11 21 97 29
18 15 52 50 20 99 90 86 44 81 80 76 33 26 61 64 66

sortiert:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83
84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100
*/