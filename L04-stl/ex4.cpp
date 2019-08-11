#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include <vector>


int main()
{
    std::list<int> l {};
    
    std::generate_n(std::back_inserter(l), 1000000, [n = 1] () mutable {return n++;});    
    
    // time of execution:
    // real	0m0,429s
    // user	0m0,290s
    // sys	0m0,012s

    //Fill_n + iota
    //std::fill_n(std::back_inserter(l), 1000000, 0);
    //std::iota(l.begin(), l.end(), 1);

    // time of execution:
    // real	0m0,467s
    // user	0m0,289s
    // sys	0m0,012s

    auto it = l.begin();
    std::advance(it, 500000);
    std::cout << *it << std::endl;  //500001

    // time of execution:    
    // real	0m0,563s
    // user	0m0,301s
    // sys	0m0,020s

    // vector - time of execution:    
    // real	0m0,153s
    // user	0m0,075s
    // sys	0m0,000s

    return 1;
}