#include <iostream>
#include <string.h>

using namespace std;

#include <cstdlib>

int sort_str_up(const void *, const void *);
int sort_str_down(const char *, const char *);
int sort_int_up(const int *, const int *);
int sort_int_down(const void *, const void *);

char list[][4]={"cat","cha","cab","cap","can"};

int vektor[]={9, 8, -4, 5, 10, 7, 1, 12 };

void main()
{ int i;

  cout<<"Steigende Sortierung des char * - Vektors:\n";
  qsort((void *)list, sizeof(list)/sizeof(list[0]), sizeof(list[0]), 
        &sort_str_up);       
  for(i=0; i<sizeof(list)/sizeof(list[0]); i++) cout<<list[i]<<"  ";


  cout<<"\n\nFallende Sortierung des char * - Vektors:\n";
  qsort(list, sizeof(list)/sizeof(list[0]), sizeof(list[0]), sort_str_down);  
  for(i=0; i<sizeof(list)/sizeof(list[0]); i++) cout<<list[i]<<"  ";


  cout<<"\n\nSteigende Sortierung des int - Vektors:\n";
  qsort(vektor, sizeof(vektor)/sizeof(int), sizeof(int), sort_int_up); 
  for(i=0; i<sizeof(vektor)/sizeof(int); i++) cout<<vektor[i]<<"  ";


  cout<<"\n\nFallende Sortierung des int - Vektors:\n";
  qsort((void *)vektor, sizeof(vektor)/sizeof(int), sizeof(int), 
        sort_int_down);
  for(i=0; i<sizeof(vektor)/sizeof(int); i++) cout<<vektor[i]<<"  ";
  cin.ignore();
}

int sort_str_up(const void *a, const void *b)
{
	return( strcmp((char *)a, (char *)b));
}

int sort_str_down(const char *a, const char *b)
{
	return( strcmp(b, a));
}

int sort_int_up(const int *a, const int *b)
{
	return((*a<*b)?-1:((*a>*b)?1:0));	
}

int sort_int_down(const void *b, const void *a)
{
	return((*(int *)a<*(int *)b)?-1:((*(int *)a>*(int *)b)?1:0));
}


/*
Steigende Sortierung des char * - Vektors:
cab can cap cat cha

Fallende Sortierung des char * - Vektors:
cha cat cap can cab

Steigende Sortierung des int - Vektors:
-4 1 5 7 8 9 10 12

Fallende Sortierung des int - Vektors:
12 10 9 8 7 5 1 -4 
*/