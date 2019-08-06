#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool is_palindrom(string wyraz)
{
    auto result = mismatch(wyraz.begin(), wyraz.end(), wyraz.rbegin(), wyraz.rend());
    return (result.first == wyraz.end());
}


int main()
{
        string w1;
        cout << "Wpisz wyraz: " << endl;
        getline(cin, w1);
        if (is_palindrom(w1) == true) {cout << "Jest palindromem!";}
        else cout << "Nie jest palindromem!";
        return 0;
}
