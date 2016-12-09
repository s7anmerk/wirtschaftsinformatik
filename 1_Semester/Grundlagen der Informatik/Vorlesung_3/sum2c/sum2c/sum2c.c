#include <stdio.h>
#define N 128UL

/* sum2c.c */

/* Funktion zur sicheren Eingabe einer double-Zahl
   Beim ersten nicht umwandelbares Zeichen wird 
   in sscanf weiter gesprungen, jedoch erneute Eingabe,
   wenn alle Zeichen nicht umwandelbar sind in sscanf */
/* z.B. wird bei 3gg die 3 verwendet und gg uebersprungen */

/* int *eof - 1 bei EOF, sonst 0                */
/* char *s - Ausschrift Variableneingabe        */
/* char *p - Zeichenkettenvektor p[0] .. p[n-1] */
/* unsigned long n - Anzahl der Elemente von p  */

double double_in2(int *eof, char *s, char *p, unsigned long n){
	double d = 0.0; int i=0; 
	char *c = 0;
	*eof = 0;
	if(!p){ printf("Puffer existiert nicht\n"); return 0.0; }
	if(n<2UL){ printf("Puffer zu kurz\n"); return 0.0; }
	while(1){                        
	    if(s) printf(s);
	    c = fgets(p,n,stdin);
		if(feof(stdin)){ *eof=1; return 0.0; }
        if(!c){ printf("Error, erneute Eingabe\n"); continue; }
	    i = sscanf(p,"%lf",&d);  /* merkt z.B. nicht 3g */
	    if(!i || i==EOF){ printf("Error\n"); continue; }
	    return d;
	}
} 

void main(){
	int n = 0, i = 0;		  // Anzahl Zahlen
	double sum = 0.0, value = 0.0;
	char puffer[N]="";

	do {
		value = double_in2(&i, "Zahl eingeben = ", puffer, N);
		if(!i){
			n = n+1;                   // Anzahl Zahlen inkrementieren
			sum = sum + value;         // Zahl zu Summe addieren
		}
	} while(!i);

	if(n>0)				               // Anzahl > 0 ?
	    printf("n = %d Zahlen, Mittelwert = %lf\n",n,sum/n);
	else 
		printf("n = %d Zahlen, kein Mittelwert\n",n);    
	getchar();
}