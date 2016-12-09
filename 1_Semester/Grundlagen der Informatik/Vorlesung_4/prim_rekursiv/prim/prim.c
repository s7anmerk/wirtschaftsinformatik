#include <stdio.h>          // Primfaktoren rekursiv
#include <ctype.h>
void PF1(unsigned long long, unsigned long long);

void PFR(unsigned long long n)
{
    if (n % 2ULL == 0ULL)
    {
        printf(", 2");
        PFR(n / 2ULL);
    }
    else PF1(n, 3ULL);
}

void PF1(unsigned long long n, unsigned long long m)
{
    if (n == 1ULL) return;
    if (n < m * m) printf(", %llu",n);
    else if(n % m == 0ULL){printf(", %llu",m);PF1(n/m,m);}
         else PF1(n, m + 2ULL);
}

void CalcPrim(unsigned long long from, unsigned long long to)
{
    unsigned long long i=0ULL;
    for(i = from; i <= to; i++)
    {
		printf("%10llu : ",i);
        PFR(i);
        printf("\n");
		if(i==to) break;  // i++ > to bringt overflow !!
    }
}

void main()
{
  unsigned long long von = 1ULL, bis = 1ULL;
  do {
	printf("Berechnung der Primfaktoren:\n");
	printf("von = "); scanf("%lli", &von); while(getchar()!='\n'); 
	printf("bis = "); scanf("%lli", &bis); while(getchar()!='\n'); 

	CalcPrim(von, bis);

	printf("erneute Berechnung ? [y/n]: ");
  } while(tolower(getchar())=='y');
  getchar();
}
/*
Berechnung der Primfaktoren:
von = 18446744073709551615
bis = 18446744073709551615
18446744073709551615 : , 3, 5, 17, 257, 641, 65537, 6700417
erneute Berechnung ? [y/n]: n
*/
/* 18446744073709551612 --> Stack-Overflow 
   Stack einstellen im VS2008:
   Projekt | prim-Eigenschaften | Linker | System | 
   Stapelreservierungsgroesse | 9999999999 
   reicht nicht aus !!                     */