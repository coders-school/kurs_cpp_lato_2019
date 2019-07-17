/*
 * ------------POCZĄTKOWA WERSJA------------------
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
*/
#include <string>
#include <iostream>

std::string napis;

bool palindrome(std::string napis)
{
    float dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}

int main()
{
    std::cout << "Write a sentence to check: ";
    std::getline(std::cin, napis);
    if(palindrome(napis)){
    std::cout << "It's a palindrome."<<'\n';}
    else{
    std::cout << "It isn't a palindrome."<<'\n';}

    return 0;
}

/*
 Ostrzeżenia które wystąpiły przy kompilacji z flagami "-pedantic -std=c++17 -Wpedantic -Wextra -Wconversion":

mainFloat.cpp: In function ‘bool palindrome(std::__cxx11::string)’:
1.mainFloat.cpp:8:31: warning: conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Wconversion]
     float dlugosc = napis.size();
                     ~~~~~~~~~~^~
2.mainFloat.cpp:11:19: warning: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
3.mainFloat.cpp:11:38: warning: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])

         Ad1. napis.size() nie zwraca float więc dostajemy informację o tym że nastąpiła konwersja. Przy konwersji może wystąpić przekłamanie wartości więc lepiej tego
         unikać. Nawet w dokumentacji dla funkcji .size() znajdziemy informację "size_t is an unsigned integral type" więc jeśli zwraca size_ to nasza zmienna też powinna
         być size_t a nie float.

         Ad2. oraz Ad3. Zgodnie z tym co omawialiśmy na zajęciach iterator powinien być typu size_t. Gwarantuje nam to że nieważne jak duża będzie iteracja to zawsze się
         zmieścimy  w tej zmiennej i nie wystąpi sytuacja gdzie skończy się float i program będzie mógł się wysypać.
*/



