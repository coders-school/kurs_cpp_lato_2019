#include <string>

bool palindrom(std::string napis)
{
    std::size_t dlugosc = napis.size();
    for(std::size_t i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}


/*

******************************* OUTPUT ************************************
 palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
 palindrom.cpp:5:31: warning: conversion to ‘float’ from 
 ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ 
 may alter its value [-Wconversion]
     float dlugosc = napis.size();
                     ~~~~~~~~~~^~
 palindrom.cpp:8:19: warning: conversion to 
 ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ 
 from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
 palindrom.cpp:8:38: warning: conversion to 
 ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ 
 from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])

*****************************************************************************

Po zmianie size_t na float nastepuje niejawna konwersja typu long unsigned int -> float.
Typ float jest typem zmiennoprzecinkowym, nie adaje sie do tego zastosowania aczkolwiek
moze dzialac poprawnie. Dopiero wlaczenie flagi -Wconversion wskazalo niepoprawne uzycie
typu. Dodatkowo typ float ma 4 bajty, a size_t w moim przypadku to 8 bajtow, co oznacza,
ze przy baaardzo dlugich palindromach float nie sprawdzilby sie tak jak size_t.


 */
