#include <stdio.h>
#include <stdlib.h>

/* Sortiert aufsteigend die n Elemente des int-Arrays array */ 

static void msort(int array[], int le, int ri, int l){
	int i, j, k;
	int *b = (int *)malloc(l*sizeof(int));//Hilfsfeld anlegen

	if(ri > le){
		//zu sortierendes Feld teilen
		int mid = (ri + le)/2;

		//Teilfelder sortieren
		msort(array, le, mid, l);
		msort(array, mid+1, ri, l);

		//Hilfsfeld aufbauen
		for(k=le; k<=mid; k++)
			b[k] = array[k];
		for(k=mid; k<ri; k++)
			b[ri+mid-k]=array[k+1];

		//Ergebnisse mischen ueber Hilfsfeld b
		i=le; j=ri;
		for(k=le; k<=ri; k++)
			if(b[i] < b[j])
				array[k] = b[i++];
			else
				array[k] = b[j--];	
	}
	free(b); b=0; //Hilfsfeld freigeben
}

static void mergesort(int array[], int l){
	msort(array, 0, l-1, l);
}

// Funktion zum rekursiven Einlesen von int-Zahlen ueber
// Tastatur, maximal ULONG_MAX == 4 294 967 295 (0xffffffff)
// Zahlen (falls der Stack-Speicher reicht !)
 
// f ist Parameter fuer Ein-/Ausgabe, beschreibt dynamisch
// vereinbarten Vektor mit n Elementen
//
// n ist Parameter fuer Ein-/Ausgabe, beschreibt die Anzahl
// der gelesenen Zahlen, dient beim Anlegen des Vektors
// als Grenze, wird auch ausserhalb von read() fuer das
// Durchlaufen des Vektors values[0..n-1] genutzt

void read(int **f, unsigned long *n){ // Parameter *f und n werden veraendert
	int i = 0;		                  // lokaler Speicher fuer i
	unsigned long j = *n;             // Index n nach j
	printf("int-Zahl = "); 
	scanf("%d", &i); while(getchar() != '\n'); // Lesen der naechsten Zahl

	if(!feof(stdin)){		         // kein Dateiende gelesen
					(*n)++;          // n := n + 1 
					read(f, n);      // rekursiver Aufruf
	}
	if(feof(stdin)){		         // EOF (F6) gelesen
			*f = (int *)malloc(*n*sizeof(int)); // anlegen des int-Vektors f
			clearerr(stdin);        // feof() zurueck auf false
			if(*f==0){              // Speicherplatzzuweisung fuer
						            // Vektor f nicht moeglich !
			   printf("kein Speicherplatz bei n = %lu\n", *n);
			   *n=0UL;      // n:=0, da kein Speicherplatz
			}
			return;
	}
	(*f)[j] = i;  // in der Ebene j gelesener Wert i nach f[j]
}

// Kleiner Test: selectionsort 
void main() { 

	unsigned long n = 0UL;
	unsigned long i = 0UL;
	int *values = 0;       // Zeiger auf Vektor values == 0

	read(&values, &n); // Aufruf des rekursiven Lesens von Tastatur

  	// Ausgabe der Werte (vorher) 
  	printf("Werte vor dem Sortieren:\n");
  	for (i = 0UL; i < n; i++) 
	  printf("%d  ", values[i]); 
  
  	// Sortiere alle (count!) Elemente von values 
  	mergesort(values, n); 

  	// Ausgabe der Werte (nachher) 
  	printf("\n\nWerte nach dem Sortieren:\n");
  	for (i = 0UL; i < n; i++) 
	  printf("%d  ", values[i]); 
	
	free(values); values=0; n = 0UL; // Freigabe des Vektors 
  	getchar();
} 