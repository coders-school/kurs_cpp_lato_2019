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
zad1.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
zad1.cpp:5:31: error: conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Werror=conversion]
     float dlugosc = napis.size();
                     ~~~~~~~~~~^~
zad1.cpp:9:19: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
zad1.cpp:9:38: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~
cc1plus: all warnings being treated as errors


My explanation:
std::size_t is the unsigned integer type of the result of the sizeof operator ("https://en.cppreference.com/w/cpp/language/types")
Our variable "dlugosc" always will be at least zero value and always integer. W can not convert a size_t value to int because of the pottencial big variable size, that it can't handle it.
Float can be bigger than int but during conversion from size_t to float it can loss of precision for a very large size_t value.
And there is no need to use storage for variable "dlugosc" in possible negative and floating point data storage.
*/
