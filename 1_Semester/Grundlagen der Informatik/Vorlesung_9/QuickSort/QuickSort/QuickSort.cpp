#include <fstream>		// Header-File zur Dateiarbeit
#include <vector>       	// Header-File fuer vector - Template

using namespace std;

void readData(vector<int> &a){	// Funktion zum Lesen nach int-Vektor a
  int aux;
  ifstream f("QSort.in");	// Eingabestrom aus Datei QSort.in
  while(f && !f.eof() && f>>aux)// Eingabestrom exist. und nicht f.EOF 
                                // und fehlerfrei Lesen von f nach aux ?
    a.push_back(aux);	   // fuegt Wert von aux an Ende des Vektors an
}

void quickSort(vector<int> &a, int inf, int sup){ // Parameter a, inf, sup
  if(inf<sup){    // Falls linker Index inf kleiner als rechter Index sup
    int pivot = a[inf], aux;       // pivot := linkes Element a[inf]
    int i = inf + 1, j = sup;      // Beginne mit i: = inf+1 und j: = sup
    while(i<=j){  // Wiederhole, solange linker Index i <= rechter Index j
      while(i<=sup && a[i] <= pivot) i++; // suche von links El., welches
      					  // groesser als Pivotelement ist
      while(j>=inf && a[j]  > pivot) j--; // suche von rechts El., welches
                                          // kleinergleich als Pivotel. ist
      if(i<j && i<=sup && j>=inf){ // Falls Index i des linken El. kleiner 
      				   // als Index j des rechten Elementes 
      				   // und Indexe i und j zulaessig, dann  
        aux = a[i];                // vertausche a[i] mit a[j]
        a[i] = a[j];              
        a[j] = aux;
        i++; j--;		   // Erhoehe i um 1, verringere j um 1
      }
    }	       // Ende while(i<=j), nach while(i<=j){...} gilt i > j
    i--;       // i:=i-1, damit gilt i == j, a[i] wird neues Trennelement 
                                       
    a[inf] = a[i]; a[i] = pivot;   // vertausche a[inf] == pivot mit a[i]
    
    quickSort(a, inf, i-1); // rekursiver Aufruf fuer den linken Bereich
                            // a[inf] ... a[i-1] von a
                            // a[i] ist Trennelement
    quickSort(a, i+1, sup); // rekursiver Aufruf fuer den rechten Bereich
  			    // a[i+1] ... a[sup] von a
  }			    // Ende von if(inf<sup), d.h. Ende wegen 
}                           // inf >= sup (einelementiger Bereich von a)

void write(vector<int> a){  // Funktion zum Schreiben nach int-Vektor a
  ofstream f("QSort.out");  // Ausgabestrom nach Datei QSort.out
  for(int i=0; i<(int)a.size(); i++) // alle a[i] durchlaufen und in
        f << a[i] << " ";   // Datei schreiben, die mit f verbunden
}

int main(){  
  vector<int> a;	    // int-Vektor a vereinbaren
  readData(a);		    // Aufruf readData(a) zum Lesen in Vektor a
  
  quickSort(a, 0, (int)a.size()-1); // Aufruf Quicksort fuer Vektor a von
                                    // a[0] bis a[a.size()-1]
  write(a);		   // Aufruf von write(a) zum Schreiben vektor a 
  return 0;                // in File
}

