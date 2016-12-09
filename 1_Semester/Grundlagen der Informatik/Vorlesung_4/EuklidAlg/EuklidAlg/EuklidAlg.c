#include <stdio.h>             // EuklidAlg.c
#include <math.h>

// Der ggt(n,m) wird m, wenn n durch m teilbar, anderenfalls ist er 
// gleich dem ggt(m, Rest(n/m))
long ggT(long n, long m){      // rekursiv
      if(abs(m)>abs(n)) return abs(ggT(m,n));
      if(!m) return abs(n);
      return abs(ggT(m,n%m));
}   

// ggT(6,15) -> ggT(15,6) -> ggT(6,15%6) -> ggT(6,3) -> ggT(3,0) -> 3
//     n  m          n m         n    m         n m         n m   ggt

long Euklid(long a, long b){    // iterativ
	a = abs(a); b=abs(b);
	while(a*b){
		       if(a >= b) a = a % b;
			   else b = b% a;
	}
	return a + b;
}

void main(){
	int a = 0, b = 0;
	printf("ganze Zahl a     =     "); scanf("%5d", &a); while(getchar()!='\n'); /* fflush(stdin);*/
	printf("ganze Zahl b     =     "); scanf("%5d", &b); while(getchar()!='\n'); /*fflush(stdin);*/
	printf("ggT( %d , %d )    = %5d\n", a, b, ggT(a,b));
	printf("Euklid( %d , %d ) = %5d\n", a, b, Euklid(a,b));
	getchar();
}

/*
ganze Zahl a     =     6
ganze Zahl b     =     15
ggT( 6 , 15 )    =     3
Euklid( 6 , 15 ) =     3
*/