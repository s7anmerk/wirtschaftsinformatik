#include <iostream>
using namespace std;

// Mittelwertberechnung C++
//
// Achtung: Beim ersten nicht in eine Zahl umwandelbaren Zeichen bricht die Eingabe ab,
//          wobei die restlichen Zeichen bis zur Enter-Tasteneingabe uebersprungen werden.
//	    Wird bereits das erste Zeichen nicht umgewandelt, dann behaelt value seinen 
//          bisherigen Wert, was zu einem fehlerhaften Mittelwert fuehrt
void main(){
	int n = 0;				//Anzahl Zahlen
	double sum = 0.0, value = 0.0;
	cout<<"Zahl eingeben = ";
	cin>>value;                             // Zahl einlesen bzw. Dateiende (F6, Strg+Z)
	while(!cin.eof()){			// Zahl eingelesen (kein Datenende)?
		cin.clear(); cin.ignore(INT_MAX, '\n'); // Eingabefehler ignorieren
		n = n+1;                        // Anzahl Zahlen inkrementieren
		sum = sum + value;              // Zahl zu Summe addieren
		cout<<"Zahl eingeben = ";
		cin>>value;			// Zahl einlesen bzw. Dateiende (F6, Strg+Z)
	}	
	if(n>0)					// Anzahl > 0 ?
	    cout<<"n = "<<n
		<<" Zahlen, Mittelwert = "
		<<sum/n<<endl;			// Mittelwert berechnen und ausgaben
	else                                    // Division durch 0 verhindern
	    cout<<"n = "<<n
		<<" Zahlen, kein Mittelwert"<<endl;	
	cin.clear();
	cin.get();
}
/* Zahl eingeben = 4
Zahl eingeben = 5
Zahl eingeben = 6
Zahl eingeben = ^Z
n = 3 Zahlen, Mittelwert = 5 */