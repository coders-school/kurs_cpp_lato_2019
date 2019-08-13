#include <iostream>
#include <vector>
#include <algorithm>


bool is_palindrome(std::string napis)
{
    auto it = std::mismatch(napis.begin(), napis.end(),napis.rbegin());
    return it.first == napis.end() and it.second == napis.rend();
}

int main()
{
    std::cout << "kajak " << is_palindrome("kajak") << '\n';
    std::cout << "ala ma kota " << is_palindrome("ala ma kota") << '\n';   

    return 0;
}
