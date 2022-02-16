#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


using namespace std;


int main()
{
  UkladRownanLiniowych   UklRown;    // zmienna przechowujaca macierz
  cin >> UklRown;

  
  cout << endl << " Start programu " << endl << endl;
  cout << UklRown;
  cout << endl;
  cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
  
  return 0;
}
