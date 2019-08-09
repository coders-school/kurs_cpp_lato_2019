#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string wyraz;
int dlugosc;
int pozycja=0;
int i=0;

bool palindrom(const string &s)
{
    auto iterators = std::mismatch(s.begin(), s.end(), s.rbegin(), s.rend());
    return (iterators.first == s.end() and iterators.second == s.rend());
 //   return std::mismatch(s.begin(), s.end(), s.rbegin(), s.rend()).first == s.end();
}


/*bool palindrom (string wyraz)

{   
    auto rit = wyraz.rbegin();
    for (auto it = wyraz.begin(); it != wyraz.begin()+wyraz.length()/2; it++)
    {
        if(*it != *rit) return false;
        rit++;
    }
    return true;
}*/
/*
bool palindrom (string wyraz, int dlugosc)          
{

    for (int i=0; i<=(dlugosc-1); i++)
    {
        if(wyraz[i]!=wyraz[dlugosc-1-i]) return false;
    }
    return true;
}
*/
int main()
{

    cout << "Podaj wyraz: ";
    getline(cin,wyraz);

    transform(wyraz.begin(), wyraz.end(), wyraz.begin(), ::tolower);

    while(pozycja != -1)                    //wykrywanie spacji i ich usuwanie
    {
        pozycja = wyraz.find(" ", i);
        if(pozycja != -1)
        {
            wyraz.erase(pozycja,1);
        }

        i = pozycja + 1;
    }

    dlugosc=wyraz.length();

   // if(palindrom(wyraz,dlugosc)) cout << "Wyraz jest palindromem";
   // else cout << "To nie palindrom";
    if(palindrom(wyraz)) cout << " Wyraz jest palindromem" << endl;
    else cout << "To nie jest palindrom" << endl;
return 0;

}
