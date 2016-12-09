#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void main(){
	double a = 0.0, epsilon = 0.00000001;
   
	cout<<"Heron-Verfahren zur Bestimmung der Quadratwurzel\n";
	do {
	    cout<<"a (a > 0) = "; cin>>a; 
	    cin.clear(); cin.ignore(INT_MAX, '\n');
	} while(a<=0.0);

	do {
	    cout<<"epsilon (epsilon > 0) = ";
		cin>>epsilon;
        cin.clear(); cin.ignore(INT_MAX, '\n');
	} while(epsilon <= 0.0);

    double x = a, y = 1.0 /*, xold = 0.0*/ /*, xneu, yneu */;
	unsigned long n = 0UL;

	// while(abs(xold - x) >= epsilon) // nach Aufgabenstellung

	while(abs(x*x - a) >= epsilon) // alternativ
    {
        ++n;               // Anzahl Iterationen
    //  xneu = (x+y)/2.0;  // klassisch nach HERON
	//	yneu = a/xneu;
	//	x = xneu;
	//	y = yneu;
	/*	xold = x; */
		x = (x + a/x)/2.0; // alternativ kuerzer
    }

	cout.setf(ios::fixed);
    	cout<<"iterativ sqrt("<<setprecision(2)<<a<<") = "
	    <<setw(14)<<setprecision(8)<<x<<endl;
	cout<<"math.h   sqrt("<<setprecision(2)<<a<<") = "
	    <<setw(14)<<setprecision(8)<< sqrt(a)<<endl;
	cout<<"Iterationen   n = "<<setw(14)<<n<<endl;
	cin.get();
 }