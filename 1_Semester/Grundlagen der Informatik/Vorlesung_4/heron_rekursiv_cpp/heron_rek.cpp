#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// globale Variable (um weitere Parameter bei S zu vermeiden) 
double a = 0.0,					// Argument a
       epsilon = 0.00000001,    // Genauigkeit
	   x = 0.0;                 // Wurzel(a)

unsigned long n = 0UL;          // Anzahl Iterationen

void S(double x){				// rekursives Verfahren
	n++;                        // Zaehler
	if(abs(x*x-a)<= epsilon){   // Abbruch
		::x = x; return;	    // globales x := lokales x
	}
	else S((x+a/x)/2.0);        // rekursiver Aufruf
}

void main(){
	cout<<"Heron-Verfahren zur Bestimmung der Quadratwurzel\n";
	do {
	    cout<<"a (a > 0)           = "; cin>>a; 
	    cin.clear(); cin.ignore(INT_MAX, '\n');
	} while(a<=0.0);

	do {
	    cout<<"epsilon ( > 0)      = "; cin>>epsilon;
        cin.clear(); cin.ignore(INT_MAX, '\n');
	} while(epsilon <= 0.0);

	S(a);				// Aufruf der rekursiven Funktion

    cout<<"rekursiv sqrt("<<fixed<<setprecision(2)<<a<<") = "
	    <<fixed<<setw(14)<<setprecision(8)<<x<<endl;

	cout<<"math.h   sqrt("<<setprecision(2)<<a<<") = "
	    <<fixed<<setw(14)<<setprecision(8)<< sqrt(a)<<endl;

	cout<<"Rekursionen       n = "<<setw(14)<<n<<endl;
	cin.get();
 }

//Heron-Verfahren zur Bestimmung der Quadratwurzel
//a (a > 0)           = 2
//epsilon ( > 0)      = 0.00000001
//rekursiv sqrt(2.00) =     1.41421356
//math.h   sqrt(2.00) =     1.41421356
//Iterationen       n =              5
