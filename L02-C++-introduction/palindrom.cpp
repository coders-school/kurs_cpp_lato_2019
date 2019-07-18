#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

bool palindrom(std::string napis)
{
    float  dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}

int main() {
    bool (*pal)(string napis);

    pal = palindrom;

    assert(pal("") == true);
    assert(pal(" ") == true);
    assert(pal("1") == true);
    assert(pal("kajak") == true);
    assert(pal("KAYAK") == true);
    assert(pal("AAAAAAAAAAAAAAAAA") == true);
    assert(pal("ADAM") == false);
    assert(pal("Adam") == false);
    assert(pal("AAAABBBB") == false);
    assert(pal("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXY") == false);
    cout << "Program pass the tests" << endl;
}

/* Version 1
 *
 * float  dlugosc = napis.size();
 * for(size_t i = 0; i < (dlugosc / 2); ++i)
 *
 * Building CXX object CMakeFiles/pali.dir/palindrom.cpp.o
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:8:32: warning: conversion from ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
     float  dlugosc = napis.size();
                      ~~~~~~~~~~^~
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:9:39: warning: conversion from ‘size_t’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
     for(size_t i = 0; i < (dlugosc / 2); ++i)
                                       ^
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:11:43: warning: conversion from ‘size_t’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                                        ~~~^~~~
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:11:38: warning: conversion from ‘float’ to ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} may change value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~

Compilation of 'L02-C++-introduction/palindrom.cpp' finished
 *
 * Program pass the tests
 *
 **********************************************************************
 *
 * Version 2
 *
 * size_t  dlugosc = napis.size();
 * for(float i = 0; i < (dlugosc / 2); ++i)
 *
 *Building CXX object CMakeFiles/pali.dir/palindrom.cpp.o
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:10:35: warning: conversion from ‘size_t’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
     for(float i = 0; i < (dlugosc / 2); ++i)
                          ~~~~~~~~~^~~~
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:12:19: warning: conversion from ‘float’ to ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} may change value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:12:46: warning: conversion from ‘size_t’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                                              ^
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:12:38: warning: conversion from ‘float’ to ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} may change value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~
 *
 * Program pass the tests
 *
 **********************************************************************
 *
 * Version 3
 *
 * float  dlugosc = napis.size();
 * for(float i = 0; i < (dlugosc / 2); ++i)
 *
 * Building CXX object CMakeFiles/pali.dir/palindrom.cpp.o
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp: In function ‘bool palindrom(std::__cxx11::string)’:
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:9:32: warning: conversion from ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} to ‘float’ may change value [-Wconversion]
     float  dlugosc = napis.size();
                      ~~~~~~~~~~^~
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:12:19: warning: conversion from ‘float’ to ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} may change value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                   ^
/home/adi/dev/coders/kurs_cpp_lato_2019/L02-C++-introduction/palindrom.cpp:12:38: warning: conversion from ‘float’ to ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} may change value [-Wfloat-conversion]
         if(napis[i] != napis[dlugosc - (i + 1)])
                              ~~~~~~~~^~~~~~~~~

 * Program pass the tests
 *
 *
 * Zamienienie typu używanego do iteraci na float może spowodować przekłamania, przy dużych liczbach może przeskakiwać o więcej niż 1
 */