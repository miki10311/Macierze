#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include <cmath>

/*
 *  Klasa UkladRownanLiniowych 
 *  
 *  Prywatne:
 *    M                     - tablica zawierająca macierz z klasy Macierz
 *    W                     - tablica zawierająca wektor z klasy Wektor 
 *
 *  Publiczne:
 *
 *     get_Macierz() const, get_Wektor() const - zwracają wartości macierzy/wektora
 *     get_Macierz() , get_Wektor()            - zwracają macierz/wektor
 *
 *     ...
 */
class UkladRownanLiniowych{

  Macierz M;
  Wektor W;

  public:

/*!
 * Realizuje zwracanie wartosci macierzy.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc macierzy.
 */
  Macierz get_Macierz() const
  {
    return M;
  }


/*!
 * Realizuje zwracanie macierzy.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca macierz.
 */
  Macierz & get_Macierz() 
  {
    return M;
  }


/*!
 * Realizuje zwracanie wartosci wektora.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc wektora.
 */
  Wektor get_Wektor() const
  {
    return W;
  }


/*!
 * Realizuje zwracanie wektora.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wektor.
 */
  Wektor & get_Wektor() 
  {
    return W;
  }
};


/*
 * Funkcja służy do przypisania watrosci Układu ze standartowego wejscia.
 * Argumenty:
 *    operator      - zawiera symbol operatora                            
 *    Strm, UklRown - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * Funkcja służy do wypisywania watrosci Układu na standardowe wyjście.
 * Argumenty:
 *    operator      - zawiera symbol operatora                            
 *    Strm, UklRown - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
