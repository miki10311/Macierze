#include "UkladRownanLiniowych.hh"

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{

    Strm << "Macierz A^T:" << endl;
    Strm << UklRown.get_Macierz() << endl;
    Strm << "Wektor wyrazow wolnych b:" << endl;
    Strm << UklRown.get_Wektor() << endl;
    return Strm;
}



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.get_Macierz() >> UklRown.get_Wektor();
    return Strm;
}