#include <forward_list>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    std::forward_list<int> fl {9, 2, 3, 4, 5, 6, 7, 8};
    auto it_begin = std::begin(fl);
    auto it_end = std::end(fl);
    std::cout << std::distance(it_begin, it_end) << std::endl;


    auto it_five = it_begin;
    std::advance(it_five, 4);
    std::cout << *it_five << std::endl; 

    std::cout << std::distance(it_begin, it_five) << std::endl;

    return 1;
}