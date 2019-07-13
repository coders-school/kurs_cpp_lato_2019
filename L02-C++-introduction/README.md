# Kurs-CPP

Materiały z kursu C++ (Lipiec 2019 - Wrzesień 2019)

## 13.07.2019 Podstawy C++

### Materiały

- [C++ Fundamental types](https://en.cppreference.com/w/cpp/language/types)
- [C++ Fixed width integer types](https://en.cppreference.com/w/cpp/types/integer)
- [More about recursion](https://www.geeksforgeeks.org/recursion/)
- [Memory : Stack vs Heap](https://www.gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)
- [Pointers vs References in C++](https://www.geeksforgeeks.org/pointers-vs-references-cpp/)
- [C++ keywords](https://en.cppreference.com/w/cpp/keyword)
- [C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects)

### Post-work

- [ ] (2 punkty) Sprobój zamienić std::size_t na float w funkcji [palindrom](palindrom.cpp) i sprawdzić wynik
- [ ] (2 punkty) Zrob optymalizację żeby pozbyć się kopiowania stringów w  [rekurencyjnej funkcji palindrom](palindrom_recursive.cpp) <details><summary>Podpowiedź</summary><p>Zapoznaj się z std::string_view</p></details>
- [ ] (1 punkt) Zapoznaj się ze wszystkimi slowami kluczowymi z rozdziału "Basic" z prezentacji (43 slajd)
- [ ] (3 punkty) Funkcja [toString](long_int.cpp) posiada bug. Sprobuj jego znaleźć i naprawić <details><summary>Podpowiedź</summary><p>Sprobuj dostać takie wartości "0", "10", "3001"</p></details>
- [ ] (2 punkty) Zapoznaj się ze slowem kluczowym "default" i użyj jego w [kodzie](long_int.cpp)
- [ ] (3 punktow) Dopisz brakujące operatory takie jak "-=", "-", "+" w [kodzie](long_int.cpp)
- [ ] (2 punktow) Dopisz własne operatory "<<" oraz ">>" żeby twoją klasę można było użyć razem z std::cout i std::cin w tym [kodzie](long_int.cpp)<details><summary>Podpowiedź</summary><p>Zobacz ten [przykład](https://medium.com/@nonuruzun/overloading-input-output-operators-in-c-a2a74c5dda8a)</p></details>
