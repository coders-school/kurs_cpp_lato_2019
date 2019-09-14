#include <iostream>
#include <forward_list>
#include <ctime>
#include <iterator>
#include <vector>
#include <numeric>
#include <string>
#include <list>

int main()
{   
    std::list<int> l{};
    l.resize(1000000);
    std::cout << l.size() << std::endl;
    /* 
     real    0m0,373s
     user    0m0,357s
     sys     0m0,016s
    */
    std::iota(l.begin(), l.end(), 1);
    auto it=l.begin();
    std::advance(it,500000);
    std::cout << *it << std::endl;
    /*
    real    0m0,421s
    user    0m0,401s
    sys     0m0,020s
    */
    std::vector<int> v{};
    v.resize(1000000);
    std::cout << v.size() << std::endl;
    /*
    real    0m0,017s
    user    0m0,012s
    sys     0m0,005s
    */
    std::iota(v.begin(), v.end(), 1);
    std::cout << v.at(500000) << std::endl;
    /*
    real    0m0,040s
    user    0m0,030s
    sys     0m0,010s
    */
    
    return 0;
     
}