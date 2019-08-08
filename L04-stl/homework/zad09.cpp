#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string input)
{
    auto pair1 = std::mismatch(input.begin(),input.end(), input.rbegin(), input.rend());
    // pair1 is std::pair<std::string::const_iterator, std::string::const_reverse_iterator>
    std::cout << "isPalindrome(" << input << "): " << *pair1.first << ' ' << *pair1.second << '\n'; 
    if(pair1.first == input.end() && pair1.second == input.rend()) return true;
    else return false;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome("abcdecba") << '\n';
    std::cout << std::boolalpha << isPalindrome("sedes")    << '\n';
    return 0;
}