# Kurs C++

Materiały z kursu C++ (Lipiec 2019 - Wrzesień 2019)

## Projekt

### Course Dashboard (Kokpit kursu? :D)

Celem projektu będzie utworzenie aplikacji, która będzie przechowywać i wyświetlać dane związane z naszym kursem C++.

### Słownik

User Story - wymaganie użytkownika
Użytkownik - osoba korzystająca z aplikacji (trener lub kursant)
Dane kursanów - imię, nick na Discordzie, link do GitHuba, link do Firecode, grupa.

### User Stories

1. Jako trener chciałbym móc przeglądać, dodawać, usuwać i edytować dane kursantów
1. Jako trener chcę, aby wszelkie informacje były zapisywane w pliku (tekstowy, binarny, baza danych?) i odczytywane z niego
1. Jako użytkownik chcę móc zalogować się do aplikacji z użyciem adresu e-mail i hasła
1. Jako użytkownik aplikacji nie chcę, aby moje hasło było gdziekolwiek dostępne i możliwe do odszyfrowania
1. Jako użytkownik chciałbym, aby plik z danymi do programu był dostępny online i aby aplikacja pobierała z niego dane.
1. Jako kursant chciałbym móc zaznaczać swoje przyszłe nieobecności lub odróbki w innej grupie
1. Jako trener chciałbym móc przeglądać tabelę obecności kursantów
1. Jako trener chciałbym, aby nazwy i daty lekcji były odczytywane z pliku konfiguracyjnego json
1. Jako trener chciałbym móc wpisywać punkty każdemu kursantowi za poszczególne lekcje i inne aktywności
1. Jako kursant chciałbym móc przeglądać swoją punktację za poszczególne lekcje i inne aktywności
1. Jako użytkownik, chciałbym domyślnie widzieć tabelę rankingową wszystkich kursantów.
1. Jako kursant chciałbym, aby moje dane były chronione, więc nikt oprócz trenera i mnie nie może edytować moich danych.
1. Jako trener chciałbym, aby punkty za lekcje można było odczytać z pliku Markdown
1. Jako użytkownik chciałbym, aby aplikacja była dostępna przez przeglądarkę internetową

### Zasady formatowania kodu

1. Nazwy klas i typów UpperCamelCase (PascalCase). Nazwy zmiennych i funkcji lowerCamelCase.
1. Nazwy klas i zmiennych muszą zawierać rzeczownik. Nazwy funkcji muszą zawierać czasownik.
1. Głębokość wcięć to 4 spacje.
1. Dopuszczamy jednolinijkowe funkcje, jeśli składają się tylko z jednej instrukcji.

    ```cpp
    int doSth(int value) { return doSthElse(value); }
    ```

1. Nie dopuszczamy jednolinijkowych instrukcji warunkowych lub pętli:

    ```cpp
    if (condition) return 42;  // bad
    ```

    Akcja zawsze musi być w kolejnej linijce, aby jej nie przeoczyć:

    ```cpp
    if (condition)  // good
        return 42;
    ```

1. Reszta do ustalenia przez was wspólnie.
    1. Braces

        ```cpp
        void f()
        {
            dosth();
        }
        // or
        void f() {
            dosth();
        }
        ```

    1. Left, right or center references and pointers

        ```cpp
        int b = 42;
        int& i = b;  // left
        int &i = b;  // right
        int & i = b;  // center
        ```
