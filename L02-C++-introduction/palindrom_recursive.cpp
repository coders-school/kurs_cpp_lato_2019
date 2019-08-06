#include <string_view>

bool palindrom_recursive(std::string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom_recursive(napis.substr(1, napis.size() - 2));
}

/*
    Klasa string_view przechowuje napis za pomoca dwoch danych:
     - wskaznik,
     - rozmiar.

    Porownanie rozmiaru obiektow:
      string_view p2 = "kobylamamalybok"; ---> 16 bitow
      string p3 = "kobylamamalybok";      ---> 32 bity

    Uzycie string_view optymalizuje funkcje palindrom_recursive,
    poniewaz w ten sposob funca operuje na wskazniku, a nie na kopii
    danych.

 */