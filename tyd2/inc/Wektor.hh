#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

using namespace std;

/*
 *  Klasa 'Wektor' opisuje nam pojęcie wektora i zawiera
 *  elementy niezbędne do wykonywania operacji na wektorach.
 *  
 *  Prywatne:
 *     tab - tablica, dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciążenia operatorów arytmetycznych umożliwiają:
 *     - dodawanie i odejmowanie wektorów
 *     - mnożenie macierzy przez wektor
 *     - mnożenie i dzielenie wektora przez liczbę
 */
class Wektor {

  double tab[ROZMIAR];    // macierz o rozmiarze podanym w module 'rozmiar.h'

  public:

/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
  double & operator[](int i);
  


/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
  double operator[](int i) const;




/*!
 * Realizuje dodawanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Wektor, jako suma wektorow.
 */
  Wektor operator + (Wektor skl2);




/*!
 * Realizuje odejmowanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Wektor, jako roznica wektorow.
 */
  Wektor operator - (Wektor skl2);




/*!
 * Realizuje mnozenie wektora przez macierz.
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Liczbe, jako wynik działania.
 */
  double operator * (Wektor skl2);




/*!
 * Realizuje mnozenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    Wektor, jako wynik działania.
 */
  Wektor operator * (double skl2);




/*!
 * Realizuje dzielenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    Wektor, jako wynik działania.
 */
  Wektor operator /(double skl2);

};



/*
 * Funkcja służy do przypisania watrosci Wektora ze standartowego wejscia.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * Funkcja służy do wypisywania watrosci Wektora na standardowe wyjście.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
