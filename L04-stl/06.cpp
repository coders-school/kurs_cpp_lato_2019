#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> fl = {9,8,7,6,5,4,3,2,1,0};
    auto it_begin = begin(fl);
    auto it_end = end(fl);
    std::cout << std::distance(it_begin,it_end) << '\n';
    auto it_5 = std::next(it_begin, 4);
    std::cout << *it_5 << '\n';
    std::cout << std::distance(it_begin,it_5) << '\n';

    return 0;
}
