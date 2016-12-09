#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
   int h = *a;
   *a = *b;
   *b = h;
}

//int partition(int z[], int l, int r) {
//    int x = z[r], //Vergleich mit x=z[r]
//        i = l-1,
//        j = r;
//    while (1) {
//       while (z[++i] < x)
//          ;
//       while ((l<j) && (z[--j] > x))
//          ;
//       if (i < j)
//          swap(z+i, z+j);   
//       else {
//          swap(z+i, z+r);
//          return i;
//       }
//    }
//}

int partition(int z[], int l, int r) {
    int x = z[l], //Vergleich mit x=z[l]
        i = l,
        j = r+1;
    while (1) {
       while ((i<r) && (z[++i] < x))
          ;
       while (z[--j] > x)
          ;
       if (i < j)
          swap(z+i, z+j);   
       else {
          swap(z+j, z+l);
          return j;
       }
    }
}

void quick_sort(int z[], int l, int r) {
   if (l < r) {
      int pivot = partition(z, l, r);
      quick_sort(z, l, pivot-1);
      quick_sort(z, pivot+1, r);
   }
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
  	quick_sort(values, 0, n-1); 

  	// Ausgabe der Werte (nachher) 
  	printf("\n\nWerte nach dem Sortieren:\n");
  	for (i = 0UL; i < n; i++) 
	  printf("%d  ", values[i]); 
	
	free(values); values=0; n = 0UL; // Freigabe des Vektors 
  	getchar();
} 
