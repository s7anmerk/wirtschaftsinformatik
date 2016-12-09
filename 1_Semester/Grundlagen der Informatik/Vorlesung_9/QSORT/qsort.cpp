// qsort.cpp 
#include<iostream>
using namespace std;

#include<cstdlib>   // enthält Prototyp von qsort()

// Definition der Vergleichsfunktion
int icmp(const void *a, const void *b)
{
    // Typumwandlung der Zeiger auf void in Zeiger auf int
    // und anschliessende Dereferenzierung (von rechts lesen)
    int ia = *(int *)a;
    int ib = *(int *)b;

    // Vergleich und Ergebnisrückgabe ( > 0, = 0, oder < 0)
    if(ia == ib) return 0;
    return ia > ib ? 1 : -1;
}

void main()
{
    int ifeld[] = {100,22,3,44,6,9,2,1,8,9};

    // Die Feldgroesse ist die Anzahl der Elemente des Feldes.
    // Feldgroesse = sizeof(Feld) / sizeof(ein Element)
    int Groesse = sizeof(ifeld)/sizeof(ifeld[0]);

    // Aufruf von qsort():
    qsort(ifeld, Groesse, sizeof(ifeld[0]), icmp);

    // Ausgabe des sortierten Feldes:
    for (int i = 0; i < Groesse; ++i)
         cout << " " << ifeld[i];
    cout << endl;
	cin.ignore();
}

// 1 2 3 6 8 9 9 22 44 100
