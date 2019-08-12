#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string &s)
{
    auto it = std::mismatch(s.begin(), s.end(), s.rbegin());
    return (it.first == s.end() && it.second == s.rend());
}

int main() 
{
    std::string s = "mdfbdfbef";
    std::cout << is_palindrome(s) << std::endl;
    return 1;
}