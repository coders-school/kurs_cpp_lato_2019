#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string & s)
{
    return std::mismatch(s.begin(), s.end(), s.rbegin(), s.rend()).first == s.end();
}

int main()
{
    std::cout << isPalindrome("kayak") << std::endl;
    std::cout << isPalindrome("maya") << std::endl;
    
    return 0;
}
