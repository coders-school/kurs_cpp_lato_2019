#include <string>
#include <string_view>
#include <iostream>
#include "palindrom.hpp"
#include "palindrom_recursive.hpp"

using namespace std;

int main(void)
{
    string p1 = "kajak";

    if(palindrom(p1)) {
        cout << p1 << " is a palindrome " << endl;
    } else {

        cout << p1 << " is not a palindrome " << endl;
    }

    /******************************************************/

    string_view p2 = "";
    string p3 = "";
/*
    if(palindrom_recursive(p2)) {
        cout << p2 << " is a palindrome " << endl;
    } else {

        cout << p2 << " is not a palindrome " << endl;
    }
*/
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;

    /******************************************************/


    return 0;
}