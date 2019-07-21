# Kurs-CPP

Materiały z kursu C++ (Lipiec 2019 - Wrzesień 2019)

## 20.07.2019 Obiektowy C++ (podstawowe typy, funkcje, rekurencja, stos, sterta, wskaźniki, referencje, OOP, klasy, konstruktory, destruktory, operatory)

### Poprzedni Pre-work

- [x] Zapoznaj się ze [ściągą o polimorfiźmie](https://github.com/coders-school/kurs_cpp_zima_2019/blob/master/L06-algorithms%2Ctesting/polimorfizm.pdf)

### Materiały

- [Prezentacja Obiektowy C++](object_oriented_cpp.pdf)
- [Pre-test](pre-test.txt)
- [Post-test](post-test.txt)
- [Repozytorium z projektem](https://github.com/LordLukin/Cars)
- [Kolejność inicjalizacji](https://dorwijnerda.pl/blog/kolejnosc-inicjalizacji/)

### Nagrania i foto

### Post-work

Pracujcie w parach lub po 3 osoby na wspólnym repo. Punkty zostaną przyznane wszystkim osobom w grupie, których commity będą widoczne w PR.

- [ ] (2 punkty) Naprawcie enkapsulację, aby m.in. nie można było wymienić silnika podczas jazdy samochodem
- [ ] (2 punkty) Naprawcie wycieki pamięci poprzez zwalnianie zaalokowanych obiektów (silników) w odpowiednich destruktorach
- [ ] (2 punkt) Dodajcie do samochodów pole `velocity`, które będzie przechowywać aktualną prędkość pojazdu i modyfikujcie je odpowienio w funkcjach `accelerate()` oraz `brake()`
- [ ] (3 punkty) Poprawcie interfejs, aby był jak najmniej podatny na niewłaściwe użycie (np. accelerate(-999))
- [ ] (4 punktów) Napiszcie w dowolny sposób kilka testów do obecnej funkcjonalności, m.in. sprawdzających pole `velocity`. Nie musicie używać żadnego frameworka, jeśli nie znacie. Wystarczy funkcja `assert()`.
- [ ] (2 punkty) Utwórzcie wyjątek InvalidGear, który powinien być rzucony w momencie, gdy ktoś próbuje np. zmienić bieg z 5 na R. Powinien on dziedziczyć z jednego z wyjątków z biblioteki standardowej

### Pre-work

- [ ] Zapoznaj się z [opisem kontenerów](http://en.cppreference.com/w/cpp/container)
- [ ] [Playlista na YT odnosnie STLa](https://www.youtube.com/playlist?list=PL5jc9xFGsL8G3y3ywuFSvOuNm3GjBwdkb) - obejrzyj ile mozesz :)
- [ ] Przeczytaj [artykuł Marcina Pietraszka o złożoności obliczeniowej](http://www.samouczekprogramisty.pl/podstawy-zlozonosci-obliczeniowej/)
