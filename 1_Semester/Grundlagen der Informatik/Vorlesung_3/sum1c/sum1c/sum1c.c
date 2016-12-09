#include <stdio.h>

// Mittelwertberechnung sum1c.c in C
//
// Beim ersten nicht in eine Zahl umwandelbaren Zeichen bricht die Eingabe ab,
// wobei die restlichen Zeichen bis zur Enter-Tasteneingabe uebersprungen werden.
void main(){
	int n = 0, i = 0;				   // Anzahl Zahlen
	double sum = 0.0, value = 0.0;
	printf("\nZahl eingeben = ");
	i=scanf("%lf",&value);             // Zahl einlesen bzw. Dateiende (F6, Strg+Z)
	// fflush(stdin);
	while ( getchar() != '\n' );
	
	while(i!=EOF){			           // Zahl eingelesen (kein Datenende)?
		if(i){
			n = n+1;                   // Anzahl Zahlen inkrementieren
			sum = sum + value;         // Zahl zu Summe addieren
		}
		printf("\nZahl eingeben = ");
		i=scanf("%lf",&value);         // Zahl einlesen bzw. Dateiende (F6, Strg+Z)
		// fflush(stdin);                 // Eingabefehler ignorieren
		while ( getchar() != '\n' );
	}	
	if(n>0)				               // Anzahl > 0 ?
	    printf("n = %d Zahlen, Mittelwert = %lf\n",n,sum/n);
	else 
		printf("n = %d Zahlen, kein Mittelwert\n",n);    
	getchar();
}