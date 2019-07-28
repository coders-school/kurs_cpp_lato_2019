#include <string>
#include <iostream>

bool palindrom(std::string napis)
{
    float dlugosc = napis.size();
    for(std::size_t i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}

int main()
{
    std::string testOK1("kobylamamalybok");
    std::string testOK2(200, 'N');
    std::string testNOK(99999999, 'N');
    std::cout << testOK1 << "-" << palindrom(testOK1) << std::endl;
    std::cout << "200x'N' - " << palindrom(testOK2) << std::endl;
    std::cout << "999999999x'N' - " << palindrom(testNOK) << std::endl;

    return 0;
}