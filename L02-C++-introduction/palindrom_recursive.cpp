#include <string>
#include <iostream>
#include "testPalindrome.h"

using namespace std;

bool palindrome(string_view text)
{
    if(text.size() < 2) return true;

    return text.front() == text.back()
        && palindrome(text.substr(1, text.size() - 2));
}


int main() {
    testPalindrome(palindrome);
    cout << "Program pass the tests" << endl;
}
