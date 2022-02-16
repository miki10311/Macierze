#include "Wektor.hh"

std::istream & operator >> (std::istream &Strm, Wektor &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm >> Wek[i];
  return Strm;
}


std::ostream & operator << (std::ostream &Strm, const Wektor &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm << Wek[i] << " ";
  
  return Strm;
}


Wektor Wektor::operator + (Wektor skl2)
{
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]+skl2[i];
  
  return wynik;
}


Wektor Wektor::operator - (Wektor skl2)
{
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]-skl2[i];
  
  return wynik; 
}


double Wektor::operator * (Wektor skl2)
{
  double suma=0;
  for (int i=0; i<ROZMIAR; i++)
  suma+=tab[i]*skl2[i];
  
  return suma;
}


Wektor Wektor::operator * (double skl2)
{
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]*skl2;
  
  return wynik;
}


Wektor Wektor::operator / (double skl2)
{
  Wektor wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]/skl2;

  return wynik;
}



double & Wektor::operator[] (int i)
{
  return tab[i];
}



double  Wektor::operator[] (int i) const
{
  return tab[i];
}