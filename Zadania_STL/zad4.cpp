// Exercise 4:
// 1. Create an empty list.
// 2. Fill it with numbers from 1 to 1’000’000.
// 3. Measure time of execution (time ./a.out in terminal)
// 4. Print value of the element with index 500’000
// 5. Measure time of execution
// 6. Replace list with vector
// 7. Measure time of execution

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main(){
    std::list <int> l{};
    l.resize(1'000'000, 1);
    // real    0m0,057s
    // user    0m0,049s
    // sys     0m0,008s

    auto it = std::next(l.begin(),499'999);
    std::cout << *it <<std::endl;
    // real    0m0,064s
    // user    0m0,048s
    // sys     0m0,016s

    std::vector<int> vec (l.begin(), l.end());
    // real    0m0,076s
    // user    0m0,071s
    // sys     0m0,005s
   
    auto itv = std::next(vec.begin(),499'999);
    std::cout << *itv <<std::endl;
    // real    0m0,074s
    // user    0m0,057s
    // sys     0m0,017s

    return 0;
}