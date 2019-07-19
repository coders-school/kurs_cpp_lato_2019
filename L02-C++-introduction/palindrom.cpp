#include <string>
#include <iostream>

using namespace std;


bool palindrom(std::string napis)
{
    float dlugosc = napis.size();
    for(float i = 0; i < (dlugosc / 2); ++i)
    {
        if(napis[i] != napis[dlugosc - (i + 1)])
            return false;
    }
    return true;
}


int main()
    {
    string w;
    cout << "Wpisz wyraz: " << endl;
    cin >> w;

    if (palindrom(w) == true) cout << "Wyraz jest palindromem!" << endl;
    else cout << "Wyraz NIE jest palindromem" << endl;

    return 0;
    }

// Zamiana size_t na float powoduje pojawienie się ostrzeżenia podczas kompilacji z flagą –Wconversion. Kompilator podpowiada, że zachodzi konwersja zmiennej o typie zmiennoprzecinkoym na typ całkowity.

// implicit conversion turns floating-point number into integer: 'float' to'size_type' (aka 'unsigned long') [-Wfloat-conversion

//Size_t przechowuje maksymalny rozmiar obiektu o dowolnym typie i jest szczególnie stosowany w iteracjach w pętli i przy indeksowaniu w tablicach. Używanie float do iteracji w pętli może spowodować niepoprawną liczbę iteracji ze względu na problemy z precyzją, które się kumulują wraz z kolejnymi iteracjami, np. zamiast 11, mamy 10.99908 i jakaś instukcja może się nie wykonać.

