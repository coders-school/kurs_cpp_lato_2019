#include <iostream>
#include <list>
#include <iterator>
#include <numeric>

void printContent(std::list<int> a)
{
    for(auto elements:a)
    {
        std::cout << elements << " ";
    }
    std::cout << std::endl;
}

void printSize(std::list<int>a)
{
    std::cout << "size: " << a.size() << std::endl;
}

int main()
{
    std::list<int> list{};
    printSize(list);
    auto it = list.begin();
    for(int i=1; i<=1000000; i++)
    {
        list.insert(it, 1, i);
        it++;
    }
    printSize(list);
    auto it2 = list.begin();
    std::advance(it2, 499999);
    std::cout << "500000th element = " << *it2 << std::endl;
    return 0;
}

/////////////////////////////////////////////////////////////
// alternative fill method
//
// std::list<int> list(1000000);
// std::itoa(list.begin(), list.end(), 1);
//
// time:
// real 0m 0.133s
// user 0m 0.107s
// sys 0m 0.026s