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

- <img src="foto/weekend_1.jpg" width="250px" /> <img src="foto/weekend_2.jpg" width="250px" />
  <img src="foto/weekend_3.jpg" width="250px" /> <img src="foto/weekend_4.jpg" width="250px" />
  
#### Grupa wieczorowa

- <img src="foto/evening_1.jpg" width="250px" />

### Post-work

- [ ] (7 punktów) dokończcie zadanie z listą (List.cpp). Zmieńcie listę jednokierunkową w listę dwukierunkową. Zastosujcie właściwe smart pointery. Wymagania:
  - wstawianie elementów na początku listy
  - wyszukiwanie elementów od końca
  - brak wycieków pamięci

- [ ] (13 punktów) zaimplementujcie własny unique_ptr. Wymagania:
  - (2) klasa szablonowa (powinna trzymać wewnątrz wskaźnik do typu szablonowego)
  - (2) RAII (pozyskanie zasobu w konstruktorze, zwolnienie w destruktorze)
  - (2) Kopiowanie niedozwolone
  - (2) Przenoszenie dozwolone
  - (5) operator*, operator->, get(), release(), reset()

### Pre-work

- [ ] Przeczytaj artykuł o [SOLID](https://www.samouczekprogramisty.pl/solid-czyli-dobre-praktyki-w-programowaniu-obiektowym/)
- [ ] Przeczytaj artykuł o [KISS, DRY, YAGNI](https://www.samouczekprogramisty.pl/jakosc-kodu-a-oschle-pocalunki-jagny/)
- [ ] Zapoznaj się z [nowoczesnym C++](https://github.com/AnthonyCalandra/modern-cpp-features)
- [ ] Zapoznaj się z [kodem](../L07-modern-cpp/exercises)
