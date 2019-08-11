#include <string_view>

bool palindrom_recursive(std::string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom_recursive(napis.substr(1, napis.size() - 2));
}
