## Kontenery STL (przypomnienie)
### Sekwencyjne:
+ array
+ vector
+ forward list
+ list
+ deque
<<<<<<< HEAD

=======
           
>>>>>>> 30d65c884ae823d22863f078f230eba89c25f915
### Asocjacyjne:
* **Uporządkowane:**
	* set
	* map
	* multiset
	* multimap
* **nieuporzadkowane:**
	* unordered_set
	* unordered_map
	* unordered_multiset
	* unordered_multimap
* **Container adaptors:**
	* stack (LIFO)
	* queue (FIFO)
	* priority_queue

## Algorytmy STL:
**Algorytmy STL**:
zestaw funkcji, który operuje na zakresach zdefiniowanych przez iteratory.

### Kategorie algorytmów STL:
* Non-modifying sequence operations,
* Modifying sequence operations,
* Sorting,
* Partitions,
* Binary search,
* Merge,
* Heap (do tworzenia kopca),
* Min/max,
* Other,
* Numeric.

***

### Non-modifying sequence operations:
	#include <algorithm>
* **all_of, any_of, none_of:**
	* operacje logicze  na całym kontenerze;
	* zwracają true/false, gdy spełniają określony predykat;
	* przykładowe użycie:
		* napisanie funkcji lambda, dzięki której przy użyciu **all_of**<br/>
		sprawdzimy czy wszystkie elementy kontenera są parzyste;
* **for_each:**
	* odpowiednik zakresowej pętli for;
	* dla każdego elementu kolekcji wykona określoną akcję;
	* rzadko używany - sugerowane użycie zakresowej pętli for;
* **for_each_n:** 
	* jak for_each z tą różnicą, że używa:
		* jednego iteratora oraz
		* ilości elementów (zamiast końcowego iteratora);
* **count, count_if:**
	* zliczanie wystąpień elementu w kolekcji (count);
	* zliczanie elementów w kolekcji spełniających kryteria (count_if);
	* przyjmuje funkcję, funkcję lambda lub funktor;
* **mismatch:**
	* przyjmuje dwa zakresy określone iteratorami;
	* porównuje dwa zakresy ze sobą:
		* jeśli są identyczne - iteratory przejdą do końca;
		* jeśli się różnią - zwróci iter. na różniące się elementy;
* **find:**
	* zwraca iterator na poszukiwany element;
* **find_if, find_if_not:**
	* **find if** - zwraca iterator na element spełniający kryteria;
	* **find_if_not** - zwraca it. na pierwszy napotkany element<br/>
		który nie spełnia podanego kryterium;
* **find_end:**
	* zwraca iterator na ostatnie występowanie elementu<br/>
	(za element można wstawić np mniejszy wektor);
* **find_first_of:**
	* jako argumenty podajemy np. dwa wektory:
		* pierwszy jest przeszukiwaną kolekcją,
		* drugi argument to szukane elementy;
			* funkcja zwróci iterator na pierwsze wystąpienie w 1 kontenerze,<br/>
			któregokolwiek elementu z drugiego kontenera;
* **adjacent_find:**
	* szuka dwóch elementów, które sąsiadują ze sobą i są identyczne;
	* zwraca iterator na pierwszy z nich;
* **search:**
	* szuka zakresu elementów, a nie pojedynczego elementu;
	* zwraca iterator na pierwszy element poszukiwanego pod-ciągu;
* **search_n:**
	* nie szuka do końca kolekcji, 
	* podajemy przez ile elementów ma się odbyć przeszukiwanie;

***

### Modifying sequence operations:
	#include <algorithm>
* **copy, copy_if:**
	* skopiuje zakres do nowego zakresu lub kontenera;
	* kontenery nie muszą być tego samego typu;
	* copy_if skopiuje elementy spełniające warunek;
* **copy_n:**
	* jak copy -> skopiuje n wartości od begin();
* **copy_backward:**
	* kopiowanie w odwrotnej kolejności;
* **move:**
	* przenosi elementy z jednej kolekcji do drugiej;
* **move_backward:**
	* przenosi elementy z jednej kolekcji do drugiej,<br/>
	ale w odwrotnej kolejności (od końca) ;
* **fill:**
	* wypełnia każdy element w kontenerze podaną wartością;
* **fill_n:**
	* wypełnia n elementów;
* **transform** (często stosowany):
	* transformuje zakres wejściowy -> zakres wyjściowy;
	* może być konieczność użycia odpowiedniego insertera do kontenerów<br/>
	(np. do vectora back_inserter);
* **generate** (często stosowany):
	* podajemy zakres wyjściowy i funktor;
	* generuje dane do kontenera, przykład z użyciem f. lambda:<br/>
	`std::generate ( v.begin(), v.end(), [n=0] () mutable { return n++; } );`
		* mutable ściąga niejawnego consta ze zmiennych zdefiniowanych na liście przechwytującej,
		* zmienne zdefiniowane na liście przechwytującej są zawsze typu auto;
* **generate_n:**
	* jak generate, ale nie podajemy końca tylko n elementów;
* **remove, remove_if:**
	* usuwa elementy z kontenera;
	* usuwa pojedyncze elementy dla których f. lambda zwróci true;
* **remove_copy, remove_copy_if:**
	* kopiuje elementy z pominięciem elementów spełniających kryteriów;
	* przykładowe użycie:
		* usuwanie spacji ze zmiennej typu std::string;
* **replace, replace if:**
	* zamienia elementy spełniające określone kryterium;
* **replace_copy, replace_copy_if:**
	* jak replace oraz replace_if, tylko kopiują wynik do nowego kontenera;
* **swap:**
	* zamiana dwóch kontenerów ze sobą;
	* muszą być takie same kontenery;
	* wartości trzymane pod spodem zostaną ze sobą zamienione;
* **swap_ranges:**
	* zamienia po zakresach;
	* mogą być kontenery różnego rodzaju;
* **iter_swap:**
	* zamień elementy na które pokazują dwa iteratory (mogą być różne kontenery);
* **reverse:**
	* odwraca zawartość kontenera;
* **reverse_copy:**
	* analogicznie jak reverse - tylko wynik zapisywany jest w nowym kontenerze;
* **rotate:**
	* (obracanie) / przesuwanie kontenera względem elementu na który wskazuje iterator np.:<br/>
	`1 2 >3< 4 5`<br/>
	`>3< 4 5  1 2`
* **shift_left, shift_right:** *(C++ 20)*
	* jak rotate, podajemy o ile ma przesunąć oraz w którą stronę;
* ~~**random_shuffle**~~: *(funkcja usunięta)*
	* mieszało elementy, lecz nie do końca losowo;
* **shuffle:**
	* mieszanie kolejności elementów w kolekcji;
* **sample:**
	* wybierz n losowych wartości z naszego kontenera wejściowego;
* **unique:**
	* usuwa duplikaty *(nie do końca prawda)*;
		* unique nie usuwa fizycznie duplikatów tylko przesuwa je na koniec kolekcji oraz<br/>
		zwraca iterator na miejsce gdzie kończą się niepowtarzalne wartości;

***

### Sorting operations:
	#include <algorithm>
* **is_sorted:**
	* czy dany kontener jest posortowany;
	* można podać lambdę / komparator;
* **is_sorted_until:**
	* algorytm zwraca iterator na **ostatni posortowany** element;
* **sort:**
	* sortuje rosnąco;
	* można przekazać komparator;
* **partial_sort:**;
	* sortuje pierwsze n elementów:
		* podajemy ilość elementów do posortowania;
		* resztę elementów pozostawia nieposortowaną;
	* pozostałe elementy mogą mieć zmienioną kolejność!
	* przyjmuje 3 iteratory, sortuje od iteratora first do middle;
* **stable_sort:**
	* gdy sortujemy np 4 pary i bierzemy tylko first do sortowania;
	* mamy gwarancję, że nie pomiesza kolejności ze względu na drugą wartość:<br/>
	`(1,1) (1,2) (2,2) (2,1)` -> input<br/>
	`(1,1) (1,2) (2,2) (2,1)`  -> stable sort<br/>
	`(1,2) (1,1) (2,2) (2,1)`  -> zwykły sort tak może zrobić<br/>
* **nth_element:**
	* wybrany element będzie na swoim miejscu;
	* na lewo elementy będą mniejsze;
	* na prawo elementy będą większe;

***

### Partitioning operations:
	#include <algorithm>
**Algorytmy partycjonujące:**<br/>
-> dzielą nam zbiór wejściowy na 2 części -> część lewą i część prawą;<br/>
-> przekazujemy lambdę, która przekazuje kryteria partycjonowania;<br/>
-> np podział na elementy parzyste i nieparzyste<br/>

* **partition:**
	* wrzucamy lambde z warunkiem, dla pierwszego zakresu:
	(parzyste true, znajdą się w 1 kontenerze, nieparzyste w 2);
	* kolejność po partycjonowaniu nie zostanie zachowana;
* **stable_partition:**
	* jak partition, ale nie zostanie zamieniona względna kolejność elementów w tej kolekcji;
* **partition_point:**
	* zwraca iterator na granicę partycjonowania (pierwszy element nie spełniający predykatu)
* **is_partitioned:**
	* zwraca *true* lub *false*;

***

### Binary search operations:
	#include <algorithm>
**Binary search:**<br/>
-> .find jest gotowe w mapie lub w zbiorze;<br/>
-> binary search można użyć przy użyciu algorithm;<br/>
-> warunkiem jest posiadanie posortowanego kontenera;<br/>

* **binary_search:**
    * sprawdza czy element znajduje się w podanym zakresie

W przypadku powtarzających się elementów możemy skorzystać z:

* **lower_bound** oraz **upper_bound**:
	* zwraca odpowiednio:
		* iterator na pierwszy powtarzający się element
		* iterator na element za ostatnim powtarzającym się:<br/>
		`1 2* 2 3* 3 4` -> w przypadku liczby 2;
* **equal_range:**
	* zwraca zakres elementów pasujących do podanego klucza;
	* zwraca parę lower i upper bound (first -> lower, second -> upper)

***

### Other operations on sorted ranges:
	#include <algorithm>
* **merge:**
	* przyjmuje 2 zakresy i trzeci do którego dane zostaną wstawione;
	* zachowuje kolejność, będzie sortować dane
	(można podać własny komparator);
* **inplace_merge:**
	* dołącza drugi zakres do pierwszego;

***

### Set operations:
	#include <algorithm>
* **includes**:
	* mówi nam czy jeden zbiór zawiera się w drugim<br/>
	(czy występuje część wspólna)
* **set_union:**
	* suma zbiorów -> elementy z jednego i drugiego zbioru:
		* w wyniku działania set_union usunięte zostaną duplikaty;
* **set_intersection:**
	* zwraca część wspólną zbiorów;
* **set_difference:**
	* zwraca różnicę pomiędzy zbiorami;
	* kolejność argumentów ma znaczenie;
* **set_symetric_difference:**
	* suma wszystkiego co nie jest częścią wspólną<br/>
	(wyklucza część wspólną);

***

### Heap operations:
	#include <algorithm>
* **push_heap:**
	* dodawanie do kopca;
* **pop_heap:**
	* ściąganie z kopca;
* **make_heap:**
	* sortowanie, aby elementy odpowiadały strukturze kopca;
* **sort_heap:**
	* sortowanie kontenera;
* **is_heap:**
	* czy mamy strukturę kopca w kontenerze;
* **is_heap_until:**
	* do kiedy kontener spełnia strukturę kopca;

***

### Minimum/ maximum operations:
	#include <algorithm>
* **min:**
	* zwraca najmniejszą **wartość**
* **max:**
	* zwraca największą **wartość**
* **minmax:**
	* zwraca parę min i max (**wartość**)
* **min_element:**
	* zwraca iterator na najmniejszy element
* **max_element:**
	* zwraca iterator na największy element
* **minmax_element:**
	* zwraca parę iteratorów na min oraz na max
* **clamp:**
	* spłaszczenie wartości do podanych granic:
		* podajemy wartość min i max (np 3 i 5)
		* wszystko mniejsze od 3 -> będzie 3
		* wszystko powyżej 5 -> będzie 5
		* wartości pośrednie nie ulegną zmianie

***

### Comparison and permutation operations:
	#include <algorithm>
* **lexicographical_compare:**
	* zwraca true jeśli pierwsza permutacja będzie mniejsza od drugiej
	* przykład kolejnych permutacji:  abc, acb, bac, bca, cab, cba
* **next_permutation:**
 	* podajemy kontener, który jest permutacją
 		* może być std::string lub inny kontener z liczbami
 	* zwraca kolejną permutację
 * **prev_permutation:**
 	* jak next_permutation tylko zwraca poprzednią permutację
 * **equal:**
 	* zwraca wartość logiczną czy dwa zbiory są sobie równe
 	* czy elementy są takie same (np w deque i vectorze)
 * **compare_3way:** *(C++20)*
 	* dziś mamy 6 operatorów logicznych:  <, <=, >, >=, ==, !=
 	* dojdzie 7-my operator 3 way: **<=>** (space ship operator :Ð)
 	zwróci jedną z 3 wartości:
 		* mniejszy od 0 jeśli pierwszy element jest mniejszy
 		* 0 jeśli są takie same
 		* większy od 0 jeśli drugi element jest mniejszy
 	 * wykorzystać będzie można **std::compare_3way** lub **operator <=>**

***

### Numeric operations:
	#include <numeric>
* **iota:**
	* funkcja, która generuje ciąg
	* podajemy od czego ma zacząć<br/>
	**1:** `1, 2, 3, 4, 5, (...)`<br/>
	**a:** `a, b, c, d, e, (...)`<br/>
* **accumulate:**
	* sumowanie elementów z kontenera
	* sprawdź również **std::reduce**
* **inner_product:**
	* iloczyn skalarny:<br/>
	`std::vector<int> a{0, 1, 2, 3};`<br/>
	`std::vector<int> b{5, 4, 2, 3};`<br/>
	 *output:*  `0*5 + 1*4 + 2*2 + 3*3`<br/>
* **adjacent_difference:**
	* różnica pomiędzy sąsiadującymi elementami:<br/>
 	*input*: 	`10,   8,   10,   6`<br/>
 	*output:* 	`10, -2, 2, -4`<br/>
 * **partial_sum:**
 	* sumuje od początku do elementu na którym jesteśmy
 	* *input*: `10, 8, 10, 6`
 	* *output*: `10, 18, 28, 34`
 * **reduce:**
 	* wynik działania jak w std::accumulate
 	* może być szybszy od accumulate (multi-thread);
---
#### Nieomówione algorytmy z numeric:
* exclusive_scan
* inclusive_scan
* transform_reduce
* transform_exclusive_scan
* transform_inclusive_scan
 
