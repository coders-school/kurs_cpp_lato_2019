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
    std::cout << std::boolalpha << palindrom("kajak") << std::endl;
    std::cout << std::boolalpha << palindrom("aaaaaaaaaaaaaaaaaaaa") << std::endl;
    std::cout << std::boolalpha << palindrom("onomatopeja") << std::endl;
    std::string longString(1000000000,'X');
    std::cout << std::boolalpha << palindrom(longString) << std::endl;
    return 0;
}

// OUTPUT:
// palindrom("kajak"):                  true
// palindrom("aaaaaaaaaaaaaaaaaaaa"):   true
// palindrom("onomatopeja"):            false
// palindrom(longString):               false 

// palindrom(longString) returned unexpected false value
// due to inaccuracy of floating-point variable on large numbers
// float dlugosc = napis.size()
