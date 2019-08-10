#include <iostream>
#include <list>
#include <ctime>
#include <iterator>
#include <vector>
#include <numeric>

int main()
{
    std::list<int> l{};
    std::list<int>::iterator it{};
    l.resize(1000000);
    std::cout << l.size() << std::endl;
    std::iota(l.begin(), l.end(), 1);
    std::advance(it,500000);
    std::cout << *it << std::endl;
    std::vector<int> v{};
    v.resize(1000000);
    std::iota(l.begin(), l.end(), 1);
    std::cout << v.at(500000) << std::endl;

    return 0;
     
}