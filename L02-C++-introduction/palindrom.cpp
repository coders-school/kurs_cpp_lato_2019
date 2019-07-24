#include <string>
#include <iostream>

using namespace std;

bool palindrom(string napis)
{
    float dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}

int main(){

   string longString(500000000,'X');
    cout << boolalpha << palindrom("manam")        <<endl;
    cout << boolalpha << palindrom("gggggggggggg") <<endl;
    cout << boolalpha << palindrom("marcin")       <<endl;
    cout << boolalpha << palindrom(longString)     <<endl;

    return 0;
}

//Result:                                                 output:
//  cout << boolalpha << palindrom("manam")                   true 
//  cout << boolalpha << palindrom("gggggggggggg")            true
//  cout << boolalpha << palindrom("marcin")                  fale
//  cout << boolalpha << palindrom(longString)                false


//palidrom(longString) zwraca nieoczekiwaną wartość - False zamiast true
//typ float jest niedokładna dla dużych liczb