#include <string>
#include <iostream>
#include <cstdlib>

std::string napis;

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
 	napis = "kajak";
	std::cout << palindrom(napis)<<std::endl;

	return 0;
}

// bład konwesji 
// conversion to ‘float’ from ‘std::__cxx11::basic_string<char>::size_type {aka long unsigned int}’ may alter its value [-Wconversion]
    // float dlugosc = napis.size();
    // size_t słuzy do przechowywania maksymalnego rozmiaru obiektu, uzywany przedewszystkim do indeksowania tablic oraz inkrementacji petli
    // natomiast float słuzy do reperezentacji liczb zeminnoprzecinkowych 
