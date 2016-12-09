#include <stdio.h>
#define N 6

/* Bemerkung: 
   Aeussere Knoten 1..N werden vom Algorithmus intern als Knoten 0..N-1 abgebildet
   Bei der Ausgabe werden die internen Knotennummern wieder hergestellt, d.h. interne
   Knotennummer i entspricht der externen Knotennummer i+1 

   Entfernungen für existierende Kanten werden durch die Werte >= 0.0 ausgedrückt, 
   nicht existierende Kanten werden über Werte -1.0 gekennzeichnet
*/

void ausgabe(double wm[][N]){
	int i = 0, j = 0;
	printf("\r\nLoesungsbaum:\r\n");
	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			if (wm[i][j] >= 0.0)
				printf("Kante von %d nach %d mit Laenge = %lf\r\n",i+1,j+1,wm[i][j]);
}

// existiert noch wählbarer Knoten?
char knoten(double d[N], char m[N]) {
	int i = 0;
	int min = -1;                          // Anfangswert vor for-Schleife
	for (i = 0; i<N; i++) {
		if (m[i] && d[i] >= 0.0)           // Knoten i unerkundet und Distanz nach i >= 0 ?
			if (min < 0 || d[i] < d[min])  // erstmaliger Aufruf for-Schleife oder Distanz zu i < Distanz vorheriger Knoten min
				min = i;                   // min = i  (>=0) ist Knotenindex mit d[min] ist minimaler Abstand
	}
	if (min >= 0) {                        // wurde Knoten mit minimaler Distanz gefunden ?
		m[min] = 0;                    // Knoten mit Index min gilt als "erkundet"
		printf("Knoten %d erkundet\r\n", min + 1);
		return 1;                       // neuer erkundeter Knoten gefunden
	}
	return 0;                          // kein erkundeter Knoten gefunden
}

// Dijkstra Algorithmus iterativ abarbeiten
void dijkstra(double am[][N], double wm[][N], double d[N], char m[N]) {
	int i = 0, j = 0, k = 0;
	while (knoten(d, m)) {                       // solange neuer erkundeter Knoten gefunden
		for (i = 0; i<N; i++) {              // alle Knoten "von"
			for (j = 0; j<N; j++) {          // alle Knoten "nach"
				if (i != j && am[i][j] >= 0.0 && !m[i] && m[j]) { // Kante von i nach j ex. und i "erkundet" und j "unerkundet" ?
																  // für j existiert noch keine Entfernung zum Startknoten
					if (d[j] < 0.0) {            // j neuer "Grenzknoten"
						d[j] = d[i] + am[i][j]; // Distanz nach j ueber i
					}
					else {
						// nach j existiert kürzerer Weg über i
						if (d[j] > (d[i] + am[i][j]))  // neuer Weg nach j ueber i kuerzer als bisherige Distanz nach j ?
							d[j] = (d[i] + am[i][j]);  // Aktualisierung der Distanz nach j ueber i
													   // bisherige Grenzkanten zuruecksetzen
						for (int k = 0; k<N; k++)
							if (wm[k][j] >= 0.0) wm[k][j] = -1.0;  // Verbindung von k nach j zuruecksetzen
					}
					// Grenzkante setzen
					wm[i][j] = am[i][j];      // Kante von i nach j gehoert zum kuerzesten Weg nach j
					printf("Distanz(%d) = %lf\r\n",
						j + 1, d[j]);
				}
			}
		}
	}
}

int main(){
	double am[N][N]; 	// Adjazenzmatrix
	double wm[N][N]; 	// Wegematrix, entspricht Adjazenzmatrix der kuerzesten Wege von s aus
	double d[N];  		// Distanzvektor, entspricht akkumlierter Entfernung Knoten i zu Startknoten
	char m[N];  	    // Markierungsvektor (1: unerkundeter Knoten; 0: bereits erkundet)
	
	int n = N;  // Anzahl Knoten
	int s = 0;  // Startknoten

	int i = 0, j = 0;
		
	// Initialisierung Matrizen und Vektoren
	for (i = 0; i < n; i++)
	{
		m[i] = 1;      // anfangs alle Knoten als unerkundet markieren
		d[i] = -1;        // Entfernung zum Startknoten ist unendlich -1
		for (j = 0; j < n; j++)
		{
			am[i][j] = -1.0; // keine Verbindung zwischen Knonten i und j
			wm[i][j] = -1.0;
		}
	}

	// Kanten eintragen (Beispieldaten)
	am[0][1] = 14.0;
	am[0][2] = 8.0;
	am[1][3] = 3.0;
	am[1][4] = 5.0;
	am[2][1] = 5.0;
	am[2][4] = 2.0;
	am[3][4] = 1.0;

	// Entfernung zum Startknoten ist 0
	d[s] = 0.0;

	dijkstra(am, wm, d, m);
		
	// Ausgabe der Ergebnisse
	printf("\r\nEntfernungen:\r\n");
	for (i=0; i<N; i++)
		printf("d(%d) = %lf\r\n",i+1,d[i]);

	ausgabe(wm);

	printf("Ende des Algorithmus\r\n");
	getchar();
	return 0;
}