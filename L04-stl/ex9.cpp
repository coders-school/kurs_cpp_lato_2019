#include <iostream>
#include <string>
#include <algorithm>


using namespace std;



bool palindrom(const string &s)
{
    auto iterators = std::mismatch(s.begin(), s.end(), s.rbegin(), s.rend());
    return (iterators.first == s.end() and iterators.second == s.rend());
}

int main()
{
    string wyraz;
    int dlugosc;
    int pozycja=0;
    int i=0;

    cout << "Podaj wyraz: ";
    getline(cin,wyraz);

    transform(wyraz.begin(), wyraz.end(), wyraz.begin(), ::tolower);

    while(pozycja != std::string::npos)                    //wykrywanie spacji i ich usuwanie
    {
        pozycja = wyraz.find(" ", i);
        if(pozycja != -1)
        {
            wyraz.erase(pozycja,1);
        }
        i = pozycja + 1;
    }

    dlugosc=wyraz.length();

    if(palindrom(wyraz)) cout << " To jest palindrom" << endl;
    else cout << "To nie jest palindrom" << endl;

    return 0;
}
