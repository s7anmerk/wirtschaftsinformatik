#include <stdio.h>
#include <stdlib.h>
 
struct element {
       int value; // der Wert des Elements
       struct element *next; // das nächste Element
};
 
void append(struct element **lst, struct element *new)
{
  struct element *lst_iter = *lst;
  if ( lst_iter!= 0 ) { // sind Elemente vorhanden
      while (lst_iter->next != 0 ) // suche das letzte Element
          lst_iter=lst_iter->next;
      lst_iter->next=new; // Hänge das Element hinten an
  }
  else // wenn die liste leer ist, bin ich das erste Element
      *lst=new;
}
 
void main()
{
	struct element *first = 0; // init. die Liste mit 0 = leere liste
	struct element *einE = 0;

	einE = malloc(sizeof(struct element)); // erzeuge ein neues Element
	einE->value = 1;      // Wert des Listenelementes    
	einE->next = 0;       // Wichtig für das Erkennen des Listenendes
	append(&first, einE); // fuege das Element in die Liste ein
}
