#include <string>
#include <iostream>
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
	std::string napis;

	std::cout<<"Write a word to check. "<<std::endl;
	std::cin>>napis;

	if(palindrom(napis))
		std::cout<<"It's palindrome."<<std::endl;
		
	else
		std::cout<<"It isn't palindrome."<<std::endl;


	return 0;
}

/*
 daniel@danielt:~/kurs_cpp_lato_2019/L02-C++-introduction$ g++ palindrom.cpp -Wall -Wextra -Werror -Wconversion -Wpedantic --std=c++17
palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
palindrom.cpp:5:31: error: conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Werror=conversion]
     float dlugosc = napis.size();
                     ~~~~~~~~~~^~
palindrom.cpp:8:19: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
palindrom.cpp:8:38: error: conversion to ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ from ‘float’ may alter its value [-Werror=float-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~
cc1plus: all warnings being treated as errors


Kiedy używamy .size() zostaje nam wzwrócony typ size_t. Zmienna dlugosc, do której przypisujemy wynik napis.size() jest typu float, a więc następuje konwersja typów, co czasami może powodować przekłamania. Podobnie jest w iteratorze i, który powinien zwiększać się z każdą iteracją o 1, ale gdy używamy typu float to nigdy nie otrzymamy dokładnie 1 tylko np 0.99999 co po wielu iteracjach może spowodować błąd.
*/
