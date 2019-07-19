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

int main()
{
	return 0;
}
/* error: conversion from ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} to ‘float’ may change value
 * dlugosc stringa jest liczba naturalna (0...n) konwersja tego typu na float (ktory nie przyjmuje wartosci liczba naturalnych, ale bardzo zblizone naraza nas na ryzyko utratych danych.
 *
 *
 */
