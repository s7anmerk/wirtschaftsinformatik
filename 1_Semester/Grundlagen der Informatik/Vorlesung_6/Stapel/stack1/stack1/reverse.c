#include <stdio.h>
#include "stack.h"

int main(void) {
   int  z=0, n=0, i=0;

   printf("Stackgroesse: "); 
   i=scanf_s("%d", &n);      /* Groesse n des Stacks einlesen */
   while(getchar() != '\n');

   stackinit(n);         /* Stack mit n Elementen anlegen */

   while (1) {           /* unendliche Schleife */
      printf("int-Zahl fuer Stack (F6=EOF): ");
      i=scanf_s("%d", &z);   /* Wert fuer Stack einlesen */
	  while(getchar() != '\n');

	  if(feof(stdin))    /* Abbruch bei F6 bzw. Strg+Z (EOF) */
         break;
      push(z);	         /* Zahl z auf Stack legen */
	  z=0;
   }

   printf("Inhalt Stack der Groesse %d :\n", n);

   while (!isEmpty())             /* Solange Stack nicht leer */
      printf("%d, ", popTop());   /* oberstes Element entfernen */

   printf("\n");
   getchar();
   return 0;
}

/*
 Stackgroesse: 4
int-Zahl fuer Stack (F6=EOF): 0
int-Zahl fuer Stack (F6=EOF): 1
int-Zahl fuer Stack (F6=EOF): 2
int-Zahl fuer Stack (F6=EOF): 3
int-Zahl fuer Stack (F6=EOF): 4
Stack voll
int-Zahl fuer Stack (F6=EOF): ^Z

Inhalt Stack der Groesse 4 :
3, 2, 1, 0,
*/