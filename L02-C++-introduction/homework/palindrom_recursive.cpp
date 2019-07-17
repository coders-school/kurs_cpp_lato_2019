#include <string>
#include <string_view>
#include <iostream>


bool palindrom(std::string_view sv)
{
    if(sv.size() < 2) return true;

    return sv.front() == sv.back()
        && palindrom(sv.substr(1, sv.size() - 2));
}


int main()
{

    std::cout<<"kajak "<<palindrom("kajak")<<std::endl;
    std::cout<<"Rafal "<<palindrom("Rafal")<<std::endl;

    return 0;

}
