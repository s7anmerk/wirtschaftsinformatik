/*	primes.c        */
#include <stdio.h>
#include <math.h>

void primefactorization(unsigned long long x)
{
	unsigned long long i = 3ULL; /* counter */
	unsigned long long c = x;    /* remaining product */

	while ((c % 2ULL) == 0ULL) {
		printf("%llu, ",2ULL);
		c = c / 2ULL;
	}

	while (i <= (sqrt((double)c)+1.0)) {
		if ((c % i) == 0ULL) {
			printf("%llu, ",i);
			c = c / i;
		}
		else
			i = i + 2ULL;
	}
	if (c > 1ULL) printf("%llu, ",c);
}

main() {
        unsigned long long p = 0ULL;
 //     while(getchar() != '\n'); 
		printf("Zahl = ");
        while (scanf("%lli",&p)!=EOF) {
			while(getchar() != '\n');
			printf("prime factorization of p=%llu \n", p);
			primefactorization(p);
			printf("\n\nZahl = ");
       }
}

/*
Zahl = 18446744073709551601
prime factorization of p=18446744073709551601
53, 348051774975651917,

Zahl = 18446744073709551602
prime factorization of p=18446744073709551602
2, 157, 1973, 29775769179641,

Zahl = 18446744073709551603
prime factorization of p=18446744073709551603
3, 139, 2306123, 19182323033,

Zahl = 18446744073709551604
prime factorization of p=18446744073709551604
2, 2, 37, 9902437, 12586817029,

Zahl = 18446744073709551605
prime factorization of p=18446744073709551605
5, 2551, 1446236305269271,

Zahl = 18446744073709551606
prime factorization of p=18446744073709551606
2, 3, 71, 42013, 1030686124187,

Zahl = 18446744073709551607
prime factorization of p=18446744073709551607
7, 9241, 464773, 613566757,

Zahl = 18446744073709551608
prime factorization of p=18446744073709551608
2, 2, 2, 2305843009213693951,

Zahl = 18446744073709551609
prime factorization of p=18446744073709551609
3, 3, 818923289, 2502845209,

Zahl = 18446744073709551610
prime factorization of p=18446744073709551610
2, 5, 23, 53301701, 1504703107,

Zahl = 18446744073709551611
prime factorization of p=18446744073709551611
11, 59, 98818999, 287630261,

Zahl = 18446744073709551612
prime factorization of p=18446744073709551612
2, 2, 3, 715827883, 2147483647,

Zahl = 18446744073709551613
prime factorization of p=18446744073709551613
13, 3889, 364870227143809,

Zahl = 18446744073709551614
prime factorization of p=18446744073709551614
2, 7, 7, 73, 127, 337, 92737, 649657,

Zahl = 18446744073709551615
prime factorization of p=18446744073709551615
3, 5, 17, 257, 641, 65537, 6700417,

// Zahl = 18446744073709551616
// unendliche Schleife (interner Ueberlauf)

Zahl = ^Z

// groesster unsigned long long - Wert: FFFF FFFF FFFF FFFF (16)
//                                   = 18446744073709551615 (10)
*/