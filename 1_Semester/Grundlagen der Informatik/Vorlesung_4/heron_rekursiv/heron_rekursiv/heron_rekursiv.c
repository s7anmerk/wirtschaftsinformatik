#include <stdio.h>              // heron_rekursiv.c
#include <math.h>

double hr(double x, double a, double epsilon, unsigned long *n){
	(*n)++;
	if(fabs(x*x-a)<= epsilon)
		return x;
	return hr((x+a/x)/2.0, a, epsilon, n);
}

void main(){
	double a = 0.0,					// Argument a
           epsilon = 0.00000001;    // Genauigkeit
	 
    unsigned long n = 0UL;          // Anzahl Iterationen

	printf("Heron-Verfahren zur Bestimmung der Quadratwurzel\n\n");

	do {
	    printf("a (a > 0)                   = "); 
		scanf("%lf", &a); while(getchar()!='\n'); 
	} while(a<=0.0);

	do {
	    printf("epsilon (epsilon > 0)       = ");
		scanf("%lf", &epsilon); while(getchar()!='\n');
	} while(epsilon <= 0.0);

	printf("\nrekursiv sqrt( %10.2lf ) = %16.8lf\n", a, hr(a, a, epsilon, &n));
    printf("math.h   sqrt( %10.2lf ) = %16.8lf\n", a, sqrt(a));
    printf("Iterationen   n             = %7d", n);
    getchar();
 }

/*
Heron-Verfahren zur Bestimmung der Quadratwurzel

a (a > 0)                   = 2
epsilon (epsilon > 0)       = 0.00000001

rekursiv sqrt(       2.00 ) =       1.41421356
math.h   sqrt(       2.00 ) =       1.41421356
Iterationen   n             =       5
*/