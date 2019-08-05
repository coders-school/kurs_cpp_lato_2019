#include <iostream>
#include <algorithm>
#include <string>

bool is_palindrome(const std::string & a)
{
//    std::string b = a;
//    std::reverse(b.begin(), b.end());
//    auto rit = a.rend();
//    std::pair<std::string::iterator, std::string::iterator> stringPair;
//    auto stringPair = mismatch(a.begin(), a.end(), a.rbegin(), a.rend());  //b.begin()
    return std::mismatch(a.begin(), a.end(), a.rbegin(), a.rend()).first == a.end();
}

int main()
{
    if(is_palindrome("asdsa"))
        std::cout << "Yes" << std::endl; 
    else 
        std::cout << "No" << std::endl;
    return 0;
}

//std::boolalpha = wyswietli true/false dla boola zamiast 1/0