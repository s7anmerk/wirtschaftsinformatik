/************************************************
Algorithmen und Problemloesungen mit C++,
http://www.algorithmen-und-problemloesungen.de
Copyright @2007 by Doina Logofatu
************************************************/

#include <fstream>
#include <vector>

using namespace std;

void readData(vector<int> &a){
  int aux;
  ifstream f("QSort.in");
  while(f && !f.eof() && f>>aux)
    a.push_back(aux);
}

void quickSort(vector<int> &a, int inf, int sup){
  if(inf<sup){
    int pivot = a[inf], aux;
    int i = inf + 1, j = sup;
    while(i<=j){
      while(i<=sup && a[i] <= pivot) i++;
      while(j>=inf && a[j]  > pivot) j--;
      if(i<j && i<=sup && j>=inf){
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
        i++; j--;
      }
    }
    i--;
    a[inf] = a[i]; a[i] = pivot;
    quickSort(a, inf, i-1);
    quickSort(a, i+1, sup); 
  }
}

void write(vector<int> a){
  ofstream f("QSort.out");
  for(int i=0; i<(int)a.size(); i++) f << a[i] << " ";
}

int main(){  
  vector<int> a;
  readData(a);
  quickSort(a, 0, (int)a.size()-1);
  write(a);
  return 0;
}

