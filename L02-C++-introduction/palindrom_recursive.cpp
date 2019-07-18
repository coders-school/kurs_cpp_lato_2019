#include <string_view>
#include <iostream>

bool palindrom(std::string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom(napis.substr(1, napis.size() - 2));
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
