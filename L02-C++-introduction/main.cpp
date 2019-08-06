#include <string>
#include <iostream>
#include "palindrom.hpp"

using namespace std;

int main(void)
{
    string p1 = "kajak";

    if(palindrom(p1)) {
        cout << p1 << " is a palindrome " << endl;
    } else {

        cout << p1 << " is not a palindrome " << endl;
    }

    return 0;
}