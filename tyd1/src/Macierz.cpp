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
    for(int i=0; i<ROZMIAR; i++)
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