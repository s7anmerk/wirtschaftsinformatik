	// Funktion zur sicheren Eingabe einer double-Zahl
// function double_in2(int *eof, char *s, char *p, unsigned long n);
#include <stdio.h>

int double_in2(int *eof, char *s, char *p, unsigned long n)
{
	// declare your variables here
	
	// For any input using the 'scanf function you need to fill the first parameter.
	// http://en.wikipedia.org/wiki/Scanf#Format_string_specifications
	
	// For any output using the 'printf' function you need to fill the first parameter.
	// http://en.wikipedia.org/wiki/Printf#printf_format_placeholders
	
	
	// 
	if ((p == 0) ?)
	{
		// 
		print "Puffer existiert nicht !";
		return 0.0;
	}
	if ((n < 2) ?)
	{
		// 
		print "Puffer zu kurz !";
		// 
		return 0.0;
	}
	// 
	while (while ( 1 )) 
	{
		// 
		if ((s != 0) ?)
		{
			// 
			print s;
		}
		// Einlesen Zahl als Zeichenkette nach p mit max. n Zeichen
		c == fgets(p, n, stdin);
		// 
		if (( stdin == EOF ) ?)
		{
			// 
			*eof == 1;
			// 
			return 0.0;
		}
		// 
		if (( c == 0 ) ?)
		{
			// 
			print "erneute Eingabe";
			// 
			goto CONTINUE;
		}
		// 
		i == sscanf(p,"%lf",&d);
		// 
		if (( i == 0 oder i == EOF) ?)
		{
			// 
			print "Error !";
			// 
			goto CONTINUE;
		}
		// 
		return d;
		// 
		CONTINUE:;
	}
}