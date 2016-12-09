#include <stdio.h>
void tausche(int *a, int *b) {
   int c = *a;
   *a = *b;
   *b = c;
}
 
void sort(int array[], size_t size) {
   size_t step=size -1;
   size_t start,i,j; 
   do {
 
      step/=2;
      for(start=0;start<step;++start){
 
         for(i=start+1;i<size;i+=step){
 
            for(j=i-1;j>=0;j-=step){
 
               if((j+step)<size && array[j]>array[j+step])
                  tausche(&array[j],&array[j+step]);
               else
                  break;
            }
         }
      }
   } while(step>0);
}
 
int main(void){
 
  int n = 0;
  int x[] = {30,5,24,11,26,20,4,23,9,25,6,28,15,27,7,22,10,3,1,13,21,29,
             17,2,19,8,16,14,12,18};
  printf("Shellsort...\nVorher: ");
  for (n = 0;n < sizeof(x)/sizeof(int);n++) printf("%d|",x[n]);
  sort(x,sizeof(x)/sizeof(int));
  printf("\n\nNachher:");
  for (n = 0;n < sizeof(x)/sizeof(int);n++) printf("%d|",x[n]);
  getc(stdin);
  return 0;
}
/*
Shellsort...
Vorher: 30|5|24|11|26|20|4|23|9|25|6|28|15|27|7|22|10|3|1|13|21|29|17|2|19|8|16|
14|12|18|

Nachher:1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|
28|29|30|
*/
