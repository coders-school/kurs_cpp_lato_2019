#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string &input)
{
    auto pair1 = std::mismatch(input.cbegin(),input.cend(), input.crbegin(), input.crend());
    // pair1 is std::pair<std::string::const_iterator, std::string::const_reverse_iterator>
    std::cout << "isPalindrome(" << input << "): " << *pair1.first << ' ' << *pair1.second << '\n'; 
    if(pair1.first == input.cend() && pair1.second == input.crend()) return true;
    else return false;
}

int main()
{
    std::cout << std::boolalpha << isPalindrome("abcdecba") << '\n';
    std::cout << std::boolalpha << isPalindrome("sedes")    << '\n';
    return 0;
}