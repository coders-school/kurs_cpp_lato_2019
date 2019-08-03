#include <string_view>

bool palindrom(std::string_view& napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom(napis.substr(1, napis.size() - 2));
}
