/* WERTEB.C */

/* Bestimmung der maximalen und minimalen Werte von unsigned bzw. signed - *\
\* Typen von char, short, int, long                                        */

#include <stdio.h>
#include <limits.h>

int main(void){
	unsigned char  uc=(unsigned char)~0U;
	unsigned short us=(unsigned short)~0U;
	unsigned int   ui=~0U;
	unsigned long  ul=~0UL;
	unsigned long long ull=~0ULL;
	char    scu=1<<(sizeof(char)*8-1), sco=~scu;
	short   ssu=1<<(sizeof(signed short)*8-1), sso=~ssu;
	int     siu=1<<(sizeof(signed int)*8-1), sio=~siu;
    long    slu=1L<<(sizeof(signed long)*8-1), slo=~slu;
	long long sllu=1LL<<(sizeof(signed long long)*8-1), sllo=~sllu;
	printf("\n\nAusgabe der Zahlbereichsgrenzen             dezimal");
	printf("           hexadezimal\n\n");
	printf("max. unsigned char-Wert      = %20d  %20X\n",uc,uc);
    printf("min. unsigned char-Wert      = %20d  %20X\n\n",0U,0U);
	printf("max. unsigned short-Wert     = %20u  %20X\n",us,us);
	printf("min. unsigned short-Wert     = %20u  %20X\n\n",0U,0U);
	printf("max. unsigned int-Wert       = %20u  %20X\n",ui,ui);
	printf("min. unsigned int-Wert       = %20u  %20X\n\n",0U,0U);
	printf("max. unsigned long-Wert      = %20lu  %20lX\n",ul,ul);
	printf("min. unsigned long-Wert      = %20lu  %20lX\n\n",0UL,0UL);
	printf("max. signed char-Wert        = %20d  %20X\n",sco,sco);
	printf("min. signed char-Wert        = %20d  %20X\n\n",scu,scu);
	printf("max. signed short-Wert       = %20d  %20X\n",sso,sso);
	printf("min. signed short-Wert       = %20d  %20X\n\n",ssu,ssu);
	printf("max. signed int-Wert         = %20d  %20X\n",sio,sio);
//    printf("max. signed int-Wert         = %20d  %20X\n",INT_MAX, INT_MAX);
	printf("min. signed int-Wert         = %20d  %20X\n\n",siu,siu);
	printf("max. signed long-Wert        = %20ld  %20lX\n",slo,slo);
	printf("min. signed long-Wert        = %20ld  %20lX\n\n",slu,slu);
	printf("max. unsigned long long Wert = %20llu  %20llX\n",ull,ull);
	printf("min. unsigned long long Wert = %20llu  %20llX\n\n",0ULL,0ULL);
	printf("max. signed long long Wert   = %20lld  %20llX\n",sllo,sllo);
	printf("min. signed long long Wert   = %20lld  %20llX\n\n",sllu,sllu);
	getc(stdin);
	return 0;
}
/*
Ausgabe der Zahlbereichsgrenzen             dezimal           hexadezimal

max. unsigned char-Wert      =                  255                    FF
min. unsigned char-Wert      =                    0                     0

max. unsigned short-Wert     =                65535                  FFFF
min. unsigned short-Wert     =                    0                     0

max. unsigned int-Wert       =           4294967295              FFFFFFFF
min. unsigned int-Wert       =                    0                     0

max. unsigned long-Wert      =           4294967295              FFFFFFFF
min. unsigned long-Wert      =                    0                     0

max. signed char-Wert        =                  127                    7F
min. signed char-Wert        =                 -128              FFFFFF80

max. signed short-Wert       =                32767                  7FFF
min. signed short-Wert       =               -32768              FFFF8000

max. signed int-Wert         =           2147483647              7FFFFFFF
min. signed int-Wert         =          -2147483648              80000000

max. signed long-Wert        =           2147483647              7FFFFFFF
min. signed long-Wert        =          -2147483648              80000000

max. unsigned long long Wert = 18446744073709551615      FFFFFFFFFFFFFFFF
min. unsigned long long Wert =                    0                     0

max. signed long long Wert   =  9223372036854775807      7FFFFFFFFFFFFFFF
min. signed long long Wert   = -9223372036854775808      8000000000000000
*/