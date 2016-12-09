#include <stdio.h>
#include <stdlib.h>

struct elem {         /* Listenelement */
   int         zahl;  /* Wert */
   struct elem *next; /* Zeiger auf naechstes Element */
};

/* Liste am Anfang leer */
static struct elem *liste = NULL, *temp = NULL;

int isFull() { return 0; }  /* Liste niemals voll */

int isEmpty() { return liste == NULL; } /* Liste leer ? */

void push(int wert) {  /* neues oberes Element */
   struct elem *neu =
      (struct elem *)malloc(sizeof *neu); /* Anlegen */
   neu->zahl = wert;   /* Wert eintragen */
   neu->next = liste;  /* zeige auf bisheriges oberes El. */
   liste = neu;        /* zeige auf neues oberes Element */
}

void pop() {  /* oberes Element entfernen */
   if (isEmpty()) {
      printf("Stack leer\n");
      return;
   }
   temp = liste->next;
   free(liste);			/* Freigabe Speicher Listenelement */
   liste = temp;        /* zeige auf vorletztes Element */
}

int top() {  /* Wert des obersten Elementes liefern */
   if (isEmpty()) {
      printf("Stack leer\n");
      return -1;
   }
   return liste->zahl;
}

int popTop() { /* oberstes Element liefern und entfernen */
   int wert = top();
   pop();
   return wert;
}
