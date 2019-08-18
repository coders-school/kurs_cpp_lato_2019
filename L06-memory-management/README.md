# Kurs-CPP

Materiały z kursu C++ (Lipiec 2019 - Wrzesień 2019)

## Grupa weekendowa

### 17.08.2019 Zarządzanie pamięcią #1 (problemy z pamięcią, valgrind)

### 18.08.2019 Zarządzanie pamięcią #2 (smart pointery, zadania)

## Grupa wieczorowa

### 19.08.2019 Zarządzanie pamięcią #1 (problemy z pamięcią, valgrind)

### 20.08.2019 Zarządzanie pamięcią #2 (smart poinery, zadania)

### Poprzedni Pre-work

- [x] poszukaj informacji o tym czym jest program `valgrind` i jak go używać do znajdywania wycieków pamięci
- [x] poczytaj w dowolnym źródle o smart pointerach (unique_ptr, shared_ptr, weak_ptr)

### Materiały

- [Prezentacja o problemach z pamięcią](memory_management_problems.pdf)
- [Prezentacja o smart pointerach](smart_pointers.pdf)
- [Repo memory_management](https://github.com/coders-school/memory_management)
- [Semantyka przenoszenia](https://infotraining.bitbucket.io/cpp-11/move.html)
- [Pre-test](pre-test.txt)
- [Post-test](post-test.txt)

### Nagrania i foto

#### Grupa weekendowa

#### Grupa wieczorowa

### Post-work

- [ ] (7 punktów) dokończcie zadanie z listą (List.cpp). Zastosujcie właściwe smart pointery. Wymagania:
  - wstawianie elementów na początku listy
  - wyszukiwanie elementów od końca

- [ ] (13 punktów) zaimplementujcie własny unique_ptr. Wymagania:
  - (2) klasa szablonowa (powinna trzymać wewnątrz wskaźnik do typu szablonowego)
  - (2) RAII (pozyskanie zasobu w konstruktorze, zwolnienie w destruktorze)
  - (2) Kopiowanie niedozwolone
  - (2) Przenoszenie dozwolone
  - (5) operator*, operator->, get(), release(), reset()

### Pre-work

- [ ] poszukaj informacji o tym, jakie nowości weszły do C++11, 14 i 17
- [ ] poszukaj informacji o tym, co wejdzie do standardu C++20
