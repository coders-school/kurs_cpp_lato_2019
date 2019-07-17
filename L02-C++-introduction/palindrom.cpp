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



/*

palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
palindrom.cpp:5:30: error: conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Werror=conversion]
    float dlugosc = napis.size();
                    ~~~~~~~~~~^~
palindrom.cpp:8:19: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
palindrom.cpp:8:38: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~
*/




/* Z powiadomien  wynika, że:
 * 1) konwersja na 'float' z 'napis.size()' może mieć wplyw na modyfikacje wyniku.
 * 2) konwersja z 'float' na 'string' moze wplynac na modyfikacje wyniku.
 * */
