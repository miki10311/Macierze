#include "Macierz.hh"


Wektor & Macierz::operator[](int i)
{
    return tab[i];
}




Wektor  Macierz::operator[](int i) const
{
    return tab[i];
}




std::ostream & operator << (std::ostream &Strm, const Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Mac[i] << std::endl;
    }
    return Strm;
}



std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}




Wektor  Macierz::operator * (Wektor W)
{
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    wynik[i]=tab[i]*W;

    return wynik;
}



double Macierz::Wyznacznik()
{
    Macierz kop=*this;
    double wynik=1;
    int ind=0;
  
    for (int i=0; i<ROZMIAR; i++)
    {
        do
        {
            if (++ind==ROZMIAR)
            {     
                break;
            }
            else if (kop[i][i]==0)
            {
                std::swap(kop[i],kop[ind]);  //zamiana kolumn
                wynik*=(-1);                 //zmiana znaku przy zamianie
            }
        }while (kop[i][i]==0);
        
        if(kop[i][i]==0)
        return 0;
         
        for (int j=i+1; j<ROZMIAR; j++)
        {
            kop[j]=kop[j]-kop[i]*kop[j][i]/kop[i][i];
        }
        wynik*=kop[i][i];
    }
    return wynik;
}