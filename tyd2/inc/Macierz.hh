#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <algorithm>
#include <iostream>


/*
 *  Klasa 'Macierz' opisuje nam pojęcie macierzy i zawiera
 *  elementy niezbedne do wykonywania operacji na macierzach.
 *  
 *  Prywatne:
 *     tab - tablica (z klasy Wektor), dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda double Wyznacznik() liczy wyznacznik macierzy.
 *
 *     Przeciazenie operatora mnoznia realizuje mnozenie macierzy razy wektor.
 */
class Macierz {

  Wektor tab[ROZMIAR];

  public:

/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
  Wektor & operator[](int i);



/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
  Wektor operator[](int i) const;



/*!
 * Realizuje liczenie wyznacznika macierzy metodą Gaussa.
 * Argumenty:
 *    brak
 *
 * Zmienne:
 *    kop=*this - kopia macierzy
 *    wynik     - zmienna przechowująca aktualną wartośc wyznacznika
 *    ind       - zmienna zabezpieczająca wyjście poza macierz
 *
 * Zwraca:
 *    Liczbę, będącą wyznacznikiem macierzy.
 */
  double Wyznacznik();



/*!
 * Realizuje mnożenie macierzy przez wektor.
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    W      - wektor, przez który mnożymy macierz
 * Zwraca:
 *    Wektor, jako wynik mnożenia.
 */
  Wektor operator * (Wektor W);
};





/*
 * Funkcja służy do przypisania watrosci Macierzy ze standartowego wejscia.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * Funkcja służy do wypisywania watrosci Macierzy na standardowe wyjście.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

#endif
