#include "UkladRownanLiniowych.hh"


std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    /* Kod podstawowy
    Strm << "Macierz A^T:" << endl;
    Strm << UklRown.get_Macierz() << endl;
    Strm << "Wektor wyrazow wolnych b:" << endl;
    Strm << UklRown.get_Wektor() << endl;
    */

    // Kod rozszerzony
    string szukane[3]={"x_1","x_2","x_3"};
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm <<"|"<< UklRown.get_Macierz()[i] <<"|"<<"|"<< szukane[i] <<"|";
        
        if (i==ROZMIAR/2)
        Strm << "=";
        else
        Strm << " ";
        
        Strm <<"|"<< UklRown.get_Wektor()[i] <<"|"<< endl; 
    }
    return Strm;
}



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.get_Macierz() >> UklRown.get_Wektor();
    return Strm;
}



void UkladRownanLiniowych::Licz_Wyznaczniki()
{
    Macierz Macierze_po_zamianie[ROZMIAR];

    for (int i=0; i<ROZMIAR; i++)
    Macierze_po_zamianie[i]=M;

    for (int i=0; i<ROZMIAR; i++)
    for (int j=0; j<ROZMIAR; j++)
    Macierze_po_zamianie[i][i][j]=W[j];

    for(int i=0; i<ROZMIAR; i++)
    wyznaczniki[i]=Macierze_po_zamianie[i].Wyznacznik();
}




bool UkladRownanLiniowych::Oblicz()
{
    double wyznacznik_glowny=M.Wyznacznik();
    Licz_Wyznaczniki();

    for (int i=0; i<ROZMIAR; i++)
    if(wyznacznik_glowny==0 && wyznaczniki[i]==0)
    {
        cout << "Uklad nieoznaczony, nieskonczenie wiele rozwiazan" << endl;
        return true;
    }
   
    if(wyznacznik_glowny==0)   
    {
        cout << "Uklad sprzeczny, brak rozwiazan" << endl;
        return true;
    }

    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=wyznaczniki[i]/wyznacznik_glowny;
    return false;
}




void UkladRownanLiniowych::Oblicz_blad()
{
    W_bladu=M*Wynik-W;
    blad=sqrt(W_bladu*W_bladu);
}




void UkladRownanLiniowych::wypisz_blad()
{
    cout << "Wektor bledu: Ax-b = (" << W_bladu << ")" << endl;
    cout << "Dlugosc wektora bledu: ||Ax-b|| = " << blad << endl;
}