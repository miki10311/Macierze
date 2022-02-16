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
 *    W_bladu;              - tablica zwierająca wektor bledu z klasy Wektor
 *    wyznaczniki[ROZMIAR]; - tablica zapisujaca wyznaczniki Cramera
 *    Wynik;                - tablica zawierajaca wyniki dla danych wyznacznikow
 *    blad;                 - liczba mowiaca o dlugosci wektora bledu
 *
 *  Publiczne:
 *
 *     get_Macierz() const, get_Wektor() const - zwracają wartości macierzy/wektora
 *     get_Macierz() , get_Wektor()            - zwracają macierz/wektor
 *
 *     Metody:
 *           void wynik()
 *           void wypisz_blad();
 *           void Licz_Wyznaczniki();
 *           bool Oblicz();
 *           void Oblicz_blad();
 *                sa opisane ponizej.
 *
 */
class UkladRownanLiniowych {
 
  Macierz M;
  Wektor W;
  Wektor W_bladu;
  double wyznaczniki[ROZMIAR];
  Wektor Wynik;
  double blad;

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




/*!
 * Realizuje wypisanie samych wynikow.
 * Argumenty:
 *     Wynik - tablica zawierajaca wyniki dla danych wyznacznikow
 */
  void wynik()
  {
    for(int i=0; i<ROZMIAR; i++)
    cout << Wynik[i] << "\t";
  }


/*!
 * Realizuje wypisanie bledu.
 * Argumanty:
 *      W_bladu - tablica zwierająca wektor bledu z klasy Wektor
 *      blad - liczba mowiaca o dlugosci wektora bledu
 */
  void wypisz_blad();
  

/*!
 * Liczy wyznaczniki dla układu Cramera.
 * Argumenty:
 *      wyznaczniki[ROZMIAR] - tablica zapisujaca wyznaczniki Cramera
 *      W - wektor umozliwiajacy uzycie metody Cramera
 *      M - macierz dajaca dostep do macierzy glownej
 * Zmienne:
 *     Macierze_po_zamianie[ROZMIAR] - zmienna pomocnicza do wykonywania 
 *                               operacji na macierzach
 */
  void Licz_Wyznaczniki();


/*!
 * Liczy wartosci x1, x2, x3
 * Sprawdza sytuacje, gdy brak rozwiazan i nieskonczenie wiele rozwiazan.
 * Argumenty:
 *      M - dostarcza informacji o wyznaczniku macierzy glownej
 *      wyznaczniki[i] - tablica z wyznacznikami Cramera
 *      Wynik[i] - tablica zapisujaca niewiadome x1, x2, x3
 * Zmienne:
 *     wyznacznik_glowny - liczba będąca wyznacznikiem macierzy
 */
  bool Oblicz();
  

/*!
 * Liczy blad wedlug wzoru i zapisuje do zmiennej 'blad'.
 * Argumenty:
 *      W_bladu, M, Wynik, W, blad - opisane wyzej
 *                 niezbedne do wzoru na dlugosc wektora bledu
 */
  void Oblicz_blad();
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
