#include <string>
#include <time.h>
#include <iostream>

using namespace std;

bool palindrom(string_view napis)
{
    if(napis.size() < 2) return true;

    return napis.front() == napis.back()
        && palindrom(napis.substr(1, napis.size() - 2));
}


int main()
        {
        string w;
        cout << "Wpisz wyraz: " << endl;
        cin >> w;

        unsigned t0 = clock(), t1;
        if (palindrom(w) == true) cout << "Wyraz jest palindromem!" << endl;
        else cout << "Wyraz NIE jest palindromem" << endl;
        t1 = clock() - t0;
        cout << "Execution time:: " << t1 << endl;

        return 0;
        }   

// W kodzie palindrom_recursive.cpp w wersji rekurencyjnej w każdym kroku alkokuje się pamięć na stercie z powodu nowego skóconego napisu o pierwszy i ostatni znak. Podejście rekurencyjne w przeciwieństwie do iteracyjnego jest szybsze, ale zajmuje więcej pamięci. Jeśli dobrze rozumiem, użycie std::string_view pozwala uniknąć tego problemu. String_view ma mniejszy rozmiar w porównaniu z typem string i dodatkowo w jego przypadku nie ma miejsca kopiowanie danych. 

// Execution time w przypadku wyrazu "aaaaaannnnaaaaaa":
// Wersja zoptymalizowana: 13
// Wersja bez string_view: 40

// Wersja z string_view jest ok. 3-krotnie szybsza w przypadku tego wyrazu. 
