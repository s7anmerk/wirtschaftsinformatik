#include <stdio.h>

/* Sortiert aufsteigend die n Elemente des int-Arrays v */ 
void bubblesort(int v[], int n) { 
  char b = 0;
  int i = 0;
  
  do {
	b = 0;	// Ruecksetzen Austauschmerkmal

	for (i = 0; i < n-1; i++) { 

		// ggf. Korrektur der Ordnung zweier, 
		// aufeinanderfolgender Werte 
		if (v[i] > v[i + 1]) { 

		   // Bubble-Schritt (Vertauschung) 
		   int t = v[i]; 
		   v[i] = v[i + 1]; 
		   v[i + 1] = t; 
		   b = 1;	// Austausch erfolgte
		} 
       	}
	n--;
  } while(b && n>1);  // wurde ausgetauscht und noch
}                     // mehr als 1 Wert in Liste ?

//void bubblesort(int *v, int n) { 
//  char b = 0;
//  int i = 0, t = 0;
//  do {
//	b = i = 0;	// Ruecksetzen Austauschmerkmal
//	while(i<n-1)
//	       (*(v+i) > *(v+i+1)  ? (t = *(v+i), *(v+i) = *(v+i+1), *(v+i+1) = t, b = 1) : 0), i++;
//  } while(--n>1 && b);  // wurde ausgetauscht und noch
//}                       // mehr als 1 Wert in Liste ?

// Kleiner Test: Lasse es bubbeln ! 
void main() { 
	int i = 0;
  	int values[] = {25, 13, 19, 31, 11, 99, 21, 17}; 
  	int count = sizeof(values) / sizeof(*values); 

  	// Ausgabe der Werte (vorher) 
  	printf("Werte vor dem Sortieren:\n");
  	for (i = 0; i < count; i++) 
	  printf("%d  ",values[i]); 
    printf("\n");
  	// Sortiere alle (count!) Elemente von values 
  	bubblesort(values, count); 

  	// Ausgabe der Werte (nachher) 
  	printf("\n\nWerte nach dem Sortieren:\n");
  	for (i = 0; i < count; i++) 
	  printf("%d  ",values[i]);
	printf("\n");
  	getchar();
} 

/*
Werte vor dem Sortieren:
25  13  19  31  11  99  21  17

Werte nach dem Sortieren:
11  13  17  19  21  25  31  99
*/