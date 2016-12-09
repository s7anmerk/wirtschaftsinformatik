program Mittelwert sum1;
#include <stdio.h>

int main(void)
{
  // declare your variables here
  
  n:=0;
  sum:=0;
  Read(zahl);
  while Solange nicht EOF gelesen 
  {
    n:=n+1;
    sum:=sum+zahl;
    Read(zahl);
  }
  if (n>0) ? then
  {
    Write(sum/n);
  {
  else
  }
    Write("Kein Mittelwert");
  }
}