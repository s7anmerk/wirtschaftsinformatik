#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 128UL

/* 1.Funktion zur sicheren Eingabe einer double-Zahl */
/* Ende beim ersten nicht umwandelbaren Zeichen */
/* char *s - Ausschrift Variableneingabe */
/* char *p - Zeichenkettenvektor p[0] .. p[n-1] */
/* unsigned long n - Anzahl der Elemente von p */
double double_in1(int *eof, char *s, char *p, unsigned long n){
	double d = 0.0;
	char *c = 0;
	*eof = 0;
	if(!p){ printf("Puffer existiert nicht\n"); return 0.0; }
	if(n<2UL){ printf("Puffer zu kurz\n"); return 0.0; }
	while(1){                        
		if(s) printf(s); 
		c = fgets(p,n,stdin);
		if(feof(stdin)){ *eof=1; return 0.0; }
		//fflush(stdin);
		if(!c){ printf("Error, erneute Eingabe\n"); continue; }
		if((strlen(p)>=1) && (p[strlen(p)-1]=='\n')) 
			p[strlen(p)-1]='\0';
		if(!strcmp(p,"0") || !strcmp(p,"0.0")) return 0.0;
		if(d = atof(p)) return d; // Rueckgabe 0.0, wenn Konvertierungsfehler
		printf("Error, erneute Eingabe\n");
	}
}

void main(){
	int n = 0, i = 0;		  // Anzahl Zahlen
	double sum = 0.0, value = 0.0;
	char puffer[N]="";

	do {
		value = double_in1(&i, "Zahl eingeben = ", puffer, N);
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