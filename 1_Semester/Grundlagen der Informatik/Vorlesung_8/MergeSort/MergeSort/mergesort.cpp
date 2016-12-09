#include <iostream>
using namespace std;

/* Sortiert aufsteigend die n Elemente des int-Arrays array */ 

static void msort(int array[], int le, int ri, int l){
	int i, j, k;
	int *b = new int[l]; //Hilfsfeld anlegen

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
	delete [] b; b=0; //Hilfsfeld freigeben
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

void read(int * &f, unsigned long &n){ // 2 Referenzparameter
	int i = 0;		         // lokaler Speicher fuer i
	unsigned long j = n;     // Index n nach j
	cout<<"int-Zahl = "; cin>>i; // Lesen der naechsten Zahl
	if(!cin.eof()){		   // kein Dateiende gelesen
					n++;   // n := n + 1 
					cin.clear(); cin.ignore(INT_MAX, '\n');
					read(f, n);  // rekursiver Aufruf
	}
	if(cin.eof()){		   // EOF (F6) gelesen
			f = new int[n];// anlegen des int-Vektors f
			cin.clear();   // cin.eof() zurueck auf false
			if(f==0){      // Speicherplatzzuweisung fuer
						   // Vektor f nicht moeglich !
			   cout<<"kein Speicherplatz bei n = "<<n<<endl;
			   n=0UL;      // n:=0, da kein Speicherplatz
			}
			return;
	}
	f[j] = i;  // in der Ebene j gelesener Wert i nach f[j]
}

// Kleiner Test: Lass bubbeln! 
void main() { 

	unsigned long n = 0UL;
	int *values = 0;       // Zeiger auf Vektor values == 0

	read(values, n); // Aufruf des rekursiven Lesens von Tastatur

  	// Ausgabe der Werte (vorher) 
  	cout<<"Werte vor dem Sortieren:\n";
  	for (unsigned long i = 0UL; i < n; i++) 
	  cout<<values[i]<<"  "; 
  
  	// Sortiere alle (count!) Elemente von values 
  	mergesort(values, n); 

  	// Ausgabe der Werte (nachher) 
  	cout<<"\n\nWerte nach dem Sortieren:\n";
  	for (unsigned long i = 0UL; i < n; i++) 
	  cout<<values[i]<<"  ";
	
	delete [] values; values=0; // Freigabe des Vektors 
  	cin.get();
} 
