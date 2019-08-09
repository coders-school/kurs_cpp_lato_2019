#include <string>
#include <iostream>
bool palindrom(std::string napis)
{    
//    std::size_t dlugosc = napis.size();
    float dlugosc = napis.size();
//    for(std::size_t i = 0; i < (dlugosc / 2); ++i)
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
