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
    std::string testOK1("kobylamamalybok");
    std::string testOK2(200, 'N');
    std::cout << testOK1 << "-" << palindrom(testOK1) << std::endl;
    std::cout << "200x'N' - " << palindrom(testOK2) << std::endl;

    return 0;
}