#include <stdio.h>                 // heron_iterativ.c
#include <math.h>

void main(){
	double a = 0.0, epsilon = 0.00000001;
	double x = a, y = 1.0; 
	unsigned long n = 0UL;
   
	printf("Heron-Verfahren zur Bestimmung der Quadratwurzel\n\n");
	do {
	    printf("a (a > 0)                   = "); 
		scanf("%lf", &a); while(getchar()!='\n'); 
	   
	} while(a<=0.0);

	do {
	    printf("epsilon (epsilon > 0)       = ");
		scanf("%lf", &epsilon);  while(getchar()!='\n'); 
	} while(epsilon <= 0.0);

    x = a;                          // Anfangswert x = a

    while(fabs(x*x - a) >= epsilon) // Abbruchbedingung
    {
        ++n;                        // Anzahl Iterationen
		x = (x + a/x)/2.0;          // alternativ kuerzer
    }

    printf("\niterativ sqrt( %10.2lf ) = %16.8lf\n", a, x);
    printf("math.h   sqrt( %10.2lf ) = %16.8lf\n", a, sqrt(a));
    printf("Iterationen   n             = %7d", n);
    getchar();
 }

/*
Heron-Verfahren zur Bestimmung der Quadratwurzel

a (a > 0)                   = 2
epsilon (epsilon > 0)       = 0.00000001

iterativ sqrt(       2.00 ) =       1.41421356
math.h   sqrt(       2.00 ) =       1.41421356
Iterationen   n             =       4
*/