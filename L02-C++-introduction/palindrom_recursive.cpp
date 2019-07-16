#include <string>
#include <string_view>

bool palindrom(std::string_view napis)
{
    std::string_view word = napis;   
	
    if(word.size() < 2) return true;

    return word.front() == word.back()
        && palindrom(word.substr(1, word.size() - 2));
}
