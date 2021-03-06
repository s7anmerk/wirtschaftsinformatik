#include <iostream>
using namespace std;

// Mittelwertberechnung      sum2.cpp
//
// Alle Fehleingabe werden abgefangen

double rdin(bool &, char *);		// Prototyp-Deklaration

void main(){
	int n = 0;			//Anzahl Zahlen
	double sum = 0.0, value = 0.0;
	bool eof = false;
					
	while(true){			// Endlosschleife
		value = rdin(eof, "Zahl eingeben = ");
		if(eof) break;		// Verlasse Schleife bei EOF
		n = n+1;                // Anzahl Zahlen inkrementieren
		sum = sum + value;      // Zahl zu Summe addieren
	}

	if(n>0)				// Anzahl > 0 ?
	    cout<<"n = "<<n
		    <<" Zahlen, Mittelwert = "
		    <<sum/n<<endl;	// Mittelwert berechnen und ausgeben
	else			// Division durch 0 verhindern
	    cout<<"n = "<<n
		    <<" Zahlen, kein Mittelwert"<<endl;	
	cin.get();
}

double rdin(bool &eof, char * s = "double - Wert = "){
	double d = 0.0;
	char c = '\n';
	eof = false;
	do {
		if(cin.rdstate() || c != '\n'){ 
			cout<<"Fehler, Eingabe wiederholen\n";
			cin.clear(); 
			cin.ignore(INT_MAX,'\n');
		}
		cout<<s; cin>>d;	// Einlesen
		if(cin.eof()){
			eof = true;	// EOF erkannt
			cin.clear();
			return d;   	// 0.0 zurueck
		}
		c = cin.peek(); 	// naechstes Zeichen ohne Lesen
	} while(cin.rdstate() || c != '\n');
	return d;
}

/* Zahl eingeben = 4
Zahl eingeben = 5
Zahl eingeben = 6
Zahl eingeben = ^Z
n = 3 Zahlen, Mittelwert = 5 */