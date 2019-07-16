#include <string>

bool palindrom(std::string napis)
{
    std::float dlugosc = napis.size();
    for(std::float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}


/*
error: conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Werror=conversion]

wywolanie funkcji size() na zmiennej napis zwraca nam dlugosc napisu, 
ktory jest typu log unsigned int, wiec jesli chcemy aby dlugosc zostala przypisana
do zmiennej o typie float, musimy sie liczyc z pewna utrata danych.

Zatem odradzalbym uzywanie float w tym kontekscie.


*/
