#include <string>

bool palindrom(std::string_view napis)
{
    if(napis.size() < 2) return true;

    std::string_view sv = napis;

    return napis.front() == napis.back()
        && palindrom(sv.substr(1, napis.size() - 2));
}
