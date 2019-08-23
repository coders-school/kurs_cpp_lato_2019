// W przypadku problemów z polskimi znakami diakrytycznymi pod Ms Windows
// można użyć Notepad++ w celu zmiany kodowania z UTF-8 na Windows-1250.

// KONTENERY STL (przypomnienie):
//     * SEKWENCYJNE:
//         * array
//         * vector
//         * forward list
//         * list
//         * deque
        
//     * ASOCJACYJNE:
//         * uporzadkowane:
//             * set
//             * map
//             * multiset
//             * multimap
            
//         * nieuporzadkowane:
//             * unordered_set
//             * unordered_map
//             * unordered_multiset
//             * unordered_multimap

//     * CONTAINER ADAPTORS: 
//         * stack (LIFO)
//         * queue (FIFO)
//         * priority_queue
    

// ALGORYTMY STL:
//     zestaw funkcji, który operuje na zakresach zdefiniowanych przez iteratory.

// KATEGORIE ALGORYTMÓW:
//     * Non-modifying sequence operations
//     * Modifying sequence operations 
//     * Sorting
//     * Partitions
//     * Binary search
//     * Merge
//     * Heap (do tworzenia kopca)
//     * Min/max
//     * Other
//     * Numeric


// NON-MODIFYING SEQUENCE OPERATIONS: (nie modyfikujące sekwencji operacji)    
//     * all_of, any_of, none_of 
//         -> operacje logicze  na całym kontenerze
//         -> zwracają true/false, gdy spełniają określony predykat
//             * przykładowe użycie:
//                napisanie funkcji lambda, dzięki której przy użyciu all_of
//                sprawdzimy czy wszystkie elementy kontenera są parzyste.
    
//     * for_each
//         -> odpowiednik zakresowej pętli for
//             * dla każdego elementu kolekcji wykona określoną akcję
//         -> rzadko używany -> sugerowane użycie nowej pętli for
    
//     * for_each_n 
//         -> jak for_each tylko używa iteratora begin()
//             oraz ilości elementów zamiast iteratora końca end();
    
//     * count, count_if
//         -> zliczanie wystąpień elementu w kolekcji (count)
//         -> zliczanie elementów w kolekcji spełniających kryteria (count_if)
//             * można podać funkcję, funkcję lambda lub funktor
    
//     * mismatch
//         -> przyjmuje 2 zakresy określone iteratorami
//         -> porównuje je ze sobą:
//             * jeśli są identyczne -> iteratory przejdą do końca
//             * jeśli się rożnią ->  zwróci iteratory na różniące się elementy
    
//     * find 
//         -> zwraca iterator na poszukiwany element
    
//     * find_if, find_if_not
//         -> find_if - zwraca iterator na element spełniający określone kryterium
//         -> find_if_not - zwraca iterator na pierwszy napotkany element,
//             który nie spełnia podanego kryterium        
        
//     * find_end 
//         -> zwraca iterator na ostatnie występowanie elementu
//             (za element można wstawić np mniejszy wektor)
    
//     * find_first_of
//         -> jako argumenty podajemy np dwa wektory
//             * pierwszy jest przeszukiwaną kolekcją (np vector)
//             * drugi argument to szukane elementy (np vector)
//         -> funkcja zwróci iterator na pierwsze wystąpienie w 1 kontenerze,
//             któregokolwiek elementu z drugiego kontenera
    
//     * adjacent_find 
//         -> szuka 2ch elementów, które sąsiadują ze sobą i są identyczne
//         -> zwraca iterator na pierwszy z nich
    
//     * search
//         -> szuka zakresu elementów, a nie pojedynczego elementu
//         -> zwraca iterator na pierwszy element poszukiwanego pod-ciągu
    
//     * search_n
//         -> nie szuka do końca kolekcji, 
//             podajemy przez ile elementów ma się odbyć przeszukiwanie
    

// MODIFYING SEQUENCE OPERATIONS:    
//     *  copy, copy if
//         -> skopiuje zakres do nowego zakresu lub kontenera
//         -> kontenery nie muszą być tego samego typu
//         -> copy_if skopiuje elementy spełniające warunek
    
//     * copy_n
//         -> jak copy -> skopiuje n wartości od begin()
    
//     * copy_backward
//         -> kopiowanie w odwrotnej kolejności
    
//     * move
//         -> przenosi elementy z jednej kolekcji do drugiej
    
//     * move_backward
//         -> przenosi elementy z jednej kolekcji do drugiej,
//             ale w odwrotnej kolejności (od końca)
    
//     * fill
//         -> wypełnia każdy element w kontenerze podaną wartością
    
//     * fill_n
//         -> wypełnia n elementów
        
//     * transform (często stosowany)
//         -> transformuje zakres wejściowy -> zakres wyjściowy
//         -> może być konieczność użycia odpowiedniego insertera do kontenerów
//             np. do vectora back_inserter
    
//     * generate (często stosowany)
//         -> podajemy zakres wyjściowy i funktor,
//         -> generuje dane do kontenera, przykład z użyciem f. lambda:
//             std::generate (v.begin(), 
//                             v.end(), 
//                             [n=0] () mutable { return n++; });
//             * mutable ściąga NIEJAWNEGO consta ze zmiennych zdefiniowanych
//                 na liście przechwytującej
//             * zmienne zdefiniowane na liście przechwytującej
//                 są zawsze typu auto.
//     * generate_n
//         -> jak generate, ale nie podajemy końca tylko n elementów
    
//     * remove, remove_if
//         -> usuwa elementy z kontenera
//         -> usuwa pojedyncze elementy dla których f. lambda zwróci true
    
//     * remove_copy, remove_copy_if
//         -> kopiuje elementy z pominięciem elementów spełniających kryteriów
//         -> przykładowe użycie:
//             * usuwanie spacji ze zmiennej typu std::string
  
//     * replace, replace if
//         -> zamienia elementy spełniające kryterium
    
//     * replace_copy, replace_copy_if
//         -> jak replace oraz replace_if,
//             tylko kopiują wynik do nowego kontenera
    
//     * swap
//         -> zamiana dwóch kontenerów ze sobą 
//         -> muszą być takie same kontenery
//         -> wartości trzymane pod spodem zostaną ze sobą zamienione
    
//     * swap_ranges
//         -> zamienia po zakresach 
//         -> mogą być różne kontenery
    
//     * iter_swap
//         -> zamień elementy na które pokazują dwa iteratory
//             (mogą być różne kontenery)
    
//     * reverse
//         -> odwraca zawartość kontenera
     
//     * reverse_copy
//         -> analogicznie jak reverse -> wynik w nowym kontenerze
        
//     * rotate 
//         -> (obracanie)/ przesuwanie kontenera względem elementu
//             na który wskazuje iterator np;
//                 1 2 3* 4 5
//                 3 4 5  1 2
    
//     * shift_left, shift_right C++ 20,
//         -> jak rotate, podajemy o ile ma przesunąć oraz w którą stronę
    
//     * random_shuffle (usuniete)
//         -> mieszało elementy, lecz nie do końca losowo
    
//     * shuffle
//         -> mieszanie kolejności elementów w kolekcji
    
//     * sample
//         -> wybierz n losowych wartości z naszego kontenera wejściowego
    
//     * unique
//         -> usuwa duplikaty (nie do końca prawda)
//         -> unique nie usuwa elementów,
//             przesuwa zdublowane elementy na koniec 
//             oraz zwraca iterator na miejsce gdzie kończą
//             się niepowtarzalne wartości


// ALGORYTMY SORTUJĄCE:
//     * is_sorted
//         -> czy dany kontener jest posortowany
//         -> można podać lambdę / komparator
    
//     * is_sorted_until
//         -> UWAGA!:
//             algorytm ten zwraca iterator na OSTATNI posortowany element
//             (a nie na pierwszy nieposortowany element)
    
//     * sort  
//         -> sortuje rosnąco
//         -> można przekazać komparator
        
//     * partial_sort
//         -> sortuje pierwsze n elementów,
//             podajemy ilość elementów do posortowania,
//             resztę elementów pozostawia nieposortowaną
//         -> pozostałe elementy mogą mieć zmienioną kolejność!
//         -> przyjmuje 3 iteratory, sortuje od iteratora first do middle
        
//     * stable_sort
//         -> gdy sortujemy np 4 pary i bierzemy tylko first do sortowania
//         -> mamy gwarancję, że nie pomiesza kolejności ze względu na drugą wartość
//             (1,1) (1,2) (2,2) (2,1)
//             (1,1) (1,2) (2,2) (2,1) -> stable sort
//             (1,2) (1,1) (2,2) (2,1) -> zwykły sort tak może zrobić
    
//     * nth_element
//         -> wybrany element będzie na swoim miejscu
//         -> na lewo elementy będą mniejsze
//         -> na prawo elementy będą większe
        

// ALGORYTMY PARTYCJONUJĄCE
//     ->  dzielą nam zbiór wejściowy na 2 części -> część lewą i część prawą
//         przekazujemy lambdę, która przekazuje kryteria partycjonowania
//     ->  np podział na elementy parzyste i nieparzyste
    
//     * partition
//         -> wrzucamy lambde z warunkiem, dla pierwszego zakresu
//             (przyste true, znajdą się w pierwszym kont., nieparzyste w 2);
//         -> kolejność po partycjonowaniu nie zostanie zachowana
    
//     * stable_partition
//         -> jak partition, ale nie zostanie zamieniona względna
//             kolejność elementów w tej kolekcji
        
//     * partition_point
//         -> zwraca iterator na granicę partycjonowania
//         (pierwszy element nie spełniający predykatu)
    
//     * is_partitioned 
//         -> zwraca true or false
    

// ALGORYTMY DO WYSZUKIWANIA BINARNEGO:
//     (.find jest gotowe w mapie lub w zbiorze)
//     binary search można użyć z pomocą algorithm,
//     warunkiem jest posiadanie posortowanego kontenera
    
//     * binary_search
//         W przypadku powtarzających się elementów możemy skorzystać z:
//     * lower_bound oraz upper_bound
//         -> zwraca odpowiednio
//             - iterator na pierwszy powtarzający się element
//             - iterator na element za ostatnim powtarzającym się
//             (np. 1 2* 2 3* 3 4 -> w przypadku 2jki)
    
//     * equal_range
//         -> zwraca zakres elementów pasujących do podanego klucza
//         -> zwraca parę lower i upper bound (first -> lower, second -> upper)


// INNE OPERACJE NA POSORTOWANYCH ZAKRESACH:
//     * merge
//         -> przyjmuje 2 zakresy i trzeci do którego dane zostaną wstawione
//         -> zachowuje kolejność, będzie sortować dane
//             (można podać własny komparator)
    
//     * inplace_merge
//         -> dołącza drugi zakres do pierwszego 
    

// OPERACJE NA ZBIORACH:
//     * includes
//         -> mówi nam czy jeden zbiór zawiera się w drugim
//             (czy występuje część wspólna)
    
//     * set_union
//         -> suma zbiorów -> elementy z jednego i drugiego zbioru
//             w wyniku działania set_union usunięte zostaną duplikaty
    
//     * set_intersection
//         -> zwraca część wspólną zbiorów
    
//     * set_difference
//         -> zwraca różnicę pomiędzy zbiorami,
//             kolejność argumentów ma znaczenie
    
//     * set_symetric_difference
//         -> wyklucza część wspólną,
//             suma wszystkiego co nie jest częścią wspólną
    

// OPERACJE NA KOPCU (HEAP):
//     Struktura kopca -> forma drzewa binarnego
//     * push_heap
//         -> dodawanie do kopca
    
//     * pop_heap
//         -> ściąganie z kopca
    
//     * make_heap
//         -> sortowanie, aby elementy odpowiadały strukturze kopca
    
//     * sort_heap
//         -> sortowanie kontenera
    
//     * is_heap
//         -> czy mamy strukturę kopca w kontenerze
    
//     * is_heap_until
//         -> do kiedy kontener spełnia strukturę kopca
        
// MIN / MAX:
//     * min              -> zwraca najmniejszą WARTOŚĆ
//     * max              -> zwraca największą WARTOŚĆ
//     * minmax           -> zwraca parę min i max (WARTOŚĆ)
//     * min_element      -> zwraca iterator na najmniejszy element
//     * max_element      -> zwraca iterator na największy element 
//     * minmax_element   -> zwraca parę iteratorów na min oraz na max
//     * clamp            
//          + spłaszczenie wartości do podanych granic:
//             -> podajemy wartość min i max (np 3 i 5)
//             -> wszystko mniejsze od 3 -> będzie 3 
//             -> wszystko powyżej 5 -> będzie 5
//             -> wartości pośrednie nie ulegną zmianie


// PERMUTACJE I PORÓWNANIA LEKSYKOGRAFICZNE:
//     * lexicographical_compare
//         -> zwraca true jeśli pierwsza permutacja będzie mniejsza od drugiej
//         -> przykład kolejnych permutacji:  abc, acb, bac, bca, cab, cba
    
//     * next_permutation
//         -> podajemy kontener, który jest permutacją 
//             * może być std::string lub inny kontener z liczbami
//         -> zwraca kolejną permutację
    
//     * prev_permutation
//         -> jak next_permutation tylko zwraca poprzednią permutację 
    
//     * equal
//         -> zwraca czy dwa zbiory są sobie równe
//         -> czy elementy są takie same (np w deque i vectorze)
    
//     * compare_3way (C++20)
//         -> dziś mamy 6 operatorów logicznych:  <, <=, >, >=, ==, !=
//         -> dojdzie 7my operator 3 way: <=> (space ship operator :Ð)
//             * zwróci coś z 3 wartości:
//                 * mniejszy od 0 jeśli pierwszy element jest mniejszy
//                 * 0 jeśli są takie same
//                 * większy od 0s jeśli drugi element jest mniejszy
//         -> wykorzystać będzie można std::compare_3way lub operator <=>


// ALGORYTMY NUMERYCZNE (#include <numeric>)
//     * iota
//         -> funkcja, która generuje ciąg
//         -> podajemy od czego ma zacząć  1*, 2, 3, 4, 5, (...)
//                                         a*, b, c, d, e, (...)
//     * accumulate            
//         -> sumowanie elementów z kontenera
//         (sprawdź również std::reduce)
    
//     * inner_product
//         -> iloczyn skalarny
//             std::vector<int> a{0, 1, 2, 3};
//             std::vector<int> b{5, 4, 2, 3};
//                 przykład:  0*5 + 1*4 + 2*2 + 3*3

//     * adjacent_difference
//         -> różnica pomiędzy sąsiadującymi elementami
//             * wejście: 10   8   10   6
//             * wyjście: 10  -2    2  -4
        
//     * partial_sum
//         -> sumuje od początku do elementu na którym jesteśmy
//             * wejście: 10 8 10 6
//             * wyjście: 10 18 28 34
            
//     * reduce
//         -> wynik działania jak w std::accumulate
//         -> może być szybszy od accumulate (multi-thread)
          

// INNE NIEOMÓWIONE ALGORYTMY C++17, DOKUMENTACJA NA CPPREFERENCE:
//     * exclusive_scan
//     * inclusive_scan
//     * transform_reduce
//     * transform_exclusive_scan
//     * transform_inclusive_scan
