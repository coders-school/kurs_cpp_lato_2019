#include <string>

bool palindrom(std::string napis)
{
    float dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}


//zamiana std::size_t na float może zakonczyć się błędem programu,
//następuje konwersja typów. Po włączeniu -Wconversion plik się
//nie skompiluje. Float posiada większy zakres, przy przypisaniu
//do long uinta może nastąpić zmiana wartości.
