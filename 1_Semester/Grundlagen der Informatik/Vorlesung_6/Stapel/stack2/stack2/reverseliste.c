#include <stdio.h>
#include "stackliste.h"

int main(void) {
   int  z=0, i=0;

   while (1) {
      printf("int-Zahl (F6 Ende): ");
      i=scanf_s("%d", &z); while(getchar() != '\n');
      if(feof(stdin))
         break;
      push(z); z=0;
   }
   printf("\nInhalt Stack: ");
   while (!isEmpty())
      printf("%d, ", popTop());
   printf("\n");
   getchar();
   return 0;
}
